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

coco_transparent_t *coco_transparent_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_transparent_t *result = coco_ctx_factory(ctx, coco_transparent_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_color_t *color;
	coco_fx_common_param_t *param;
	coco_fx_common_texture_t *texture;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "opaque", NULL);
	if(str != NULL) {
		result->opaque = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2802D184: /* color */
				color = coco_ctx_parse(ctx, coco_color_t, node1);

				result->color = color;
				break;

			case 0x657C2B30: /* param */
				param = coco_ctx_parse(ctx, coco_fx_common_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;

			case 0xA816715B: /* texture */
				texture = coco_ctx_parse(ctx, coco_fx_common_texture_t, node1);

				ctnr_list_add(result->texture_list, texture);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_transparent_check(coco_ctx_t *ctx, coco_transparent_t *transparent)
{
	if(transparent == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_transparent_dump(coco_ctx_t *ctx, coco_transparent_t *transparent, int indent)
{
	if(transparent == NULL) {
		return;
	}

	/**/

	int nr;

	coco_fx_common_param_t *param;
	coco_fx_common_texture_t *texture;

	/**/

	COCO_DUMP_INDENT(indent, "Transparent:\n");

	indent++;

	if(transparent->opaque != NULL)
	{
		COCO_DUMP_INDENT(indent, "Opaque: %s\n", transparent->opaque);
	}

	coco_ctx_dump(ctx, coco_color_t, transparent->color, indent);

	ctnr_list_foreach(transparent->param_list, param, nr) {
		coco_ctx_dump(ctx, coco_fx_common_param_t, param, indent);
	}

	ctnr_list_foreach(transparent->texture_list, texture, nr) {
		coco_ctx_dump(ctx, coco_fx_common_texture_t, texture, indent);
	}
}

/*-------------------------------------------------------------------------*/

