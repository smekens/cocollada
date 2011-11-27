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
#include <stdlib.h>

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_material_t *coco_material_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_material_t *result = coco_ctx_factory(ctx, coco_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_instance_effect_t *instance_effect;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

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

			case 0x9FE65945: /* instance_effect */
				instance_effect = coco_ctx_parse(ctx, coco_instance_effect_t, node1);

				result->instance_effect = instance_effect;
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

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_material_dump(coco_ctx_t *ctx, coco_material_t *material, int indent)
{
	if(material == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Material:\n");

	indent++;

	if(material->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", material->id);
	}

	if(material->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", material->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, material->asset, indent);

	coco_ctx_dump(ctx, coco_instance_effect_t, material->instance_effect, indent);

	ctnr_list_foreach(material->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

