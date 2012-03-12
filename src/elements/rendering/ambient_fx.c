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

coco_ambient_fx_t *coco_ambient_fx_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_ambient_fx_t *result = coco_ctx_factory(ctx, coco_ambient_fx_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_color_t *color;
	coco_fx_common_param_t *param;
	coco_fx_common_texture_t *texture;

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

				ctnr_list_append(result->param_list, param);
				break;

			case 0xA816715B: /* texture */
				texture = coco_ctx_parse(ctx, coco_fx_common_texture_t, node1);

				ctnr_list_append(result->texture_list, texture);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_ambient_fx_check(coco_ctx_t *ctx, coco_ambient_fx_t *ambient_fx)
{
	if(ambient_fx == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_ambient_fx_dump(coco_ctx_t *ctx, coco_ambient_fx_t *ambient_fx, int indent)
{
	if(ambient_fx == NULL) {
		return;
	}

	/**/

	int nr;

	coco_fx_common_param_t *param;
	coco_fx_common_texture_t *texture;

	/**/

	COCO_DUMP_INDENT(indent, "Ambient (FX):\n");

	indent++;

	coco_ctx_dump(ctx, coco_color_t, ambient_fx->color, indent);

	ctnr_list_foreach(ambient_fx->param_list, param, nr) {
		coco_ctx_dump(ctx, coco_fx_common_param_t, param, indent);
	}

	ctnr_list_foreach(ambient_fx->texture_list, texture, nr) {
		coco_ctx_dump(ctx, coco_fx_common_texture_t, texture, indent);
	}
}

/*-------------------------------------------------------------------------*/

