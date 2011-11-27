/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of COCO.
 *
 */

/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_library_lights_t *coco_library_lights_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_library_lights_t *result = coco_ctx_factory(ctx, coco_library_lights_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_light_t *light;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3BCDA5FD: /* asset */
				asset = coco_ctx_parse(ctx, coco_asset_t, node1);

				result->asset = asset;
				break;

			case 0xFC898F45: /* light */
				light = coco_ctx_parse(ctx, coco_light_t, node1);

				ctnr_list_add(result->light_list, light);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_library_lights_dump(coco_ctx_t *ctx, coco_library_lights_t *library_lights, int indent)
{
	if(library_lights == NULL) {
		return;
	}

	/**/

	int nr1;

	coco_light_t *light;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Library lights:\n");

	indent++;

	coco_ctx_dump(ctx, coco_asset_t, library_lights->asset, indent);

	ctnr_list_foreach(library_lights->light_list, light, nr1) {
		coco_ctx_dump(ctx, coco_light_t, light, indent);
	}

	ctnr_list_foreach(library_lights->extra_list, extra, nr1) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

