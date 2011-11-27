/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of COLLADA.
 *
 */

/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_reflective_t *collada_reflective_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_reflective_t *result = collada_ctx_factory(ctx, collada_reflective_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_color_t *color;
	collada_fx_common_param_t *param;
	collada_fx_common_texture_t *texture;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2802D184: /* color */
				color = collada_ctx_parser(ctx, collada_color_t, node1);

				result->color = color;
				break;

			case 0x657C2B30: /* param */
				param = collada_ctx_parser(ctx, collada_fx_common_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;

			case 0xA816715B: /* texture */
				texture = collada_ctx_parser(ctx, collada_fx_common_texture_t, node1);

				ctnr_list_add(result->texture_list, texture);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_reflective_dump(collada_ctx_t *ctx, collada_reflective_t *reflective, int indent)
{
	if(reflective == NULL) {
		return;
	}

	/**/

	int nr;

	collada_fx_common_param_t *param;
	collada_fx_common_texture_t *texture;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Reflective:\n");

	indent++;

	collada_ctx_dump(ctx, collada_color_t, reflective->color, indent);

	ctnr_list_foreach(reflective->param_list, param, nr) {
		collada_ctx_dump(ctx, collada_fx_common_param_t, param, indent);
	}

	ctnr_list_foreach(reflective->texture_list, texture, nr) {
		collada_ctx_dump(ctx, collada_fx_common_texture_t, texture, indent);
	}
}

/*-------------------------------------------------------------------------*/

