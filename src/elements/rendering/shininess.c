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

collada_shininess_t *collada_shininess_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_shininess_t *result = collada_ctx_factory(ctx, collada_shininess_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_fx_common_float_t *flt;
	collada_fx_common_param_t *param;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x767C3C00: /* float */
				flt = collada_ctx_parser(ctx, collada_fx_common_float_t, node1);

				result->flt = flt;
				break;

			case 0x657C2B30: /* param */
				param = collada_ctx_parser(ctx, collada_fx_common_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_shininess_dump(collada_ctx_t *ctx, collada_shininess_t *shininess, int indent)
{
	if(shininess == NULL) {
		return;
	}

	/**/

	int nr;

	collada_fx_common_param_t *param;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Shininess:\n");

	indent++;

	collada_ctx_dump(ctx, collada_fx_common_float_t, shininess->flt, indent);

	ctnr_list_foreach(shininess->param_list, param, nr) {
		collada_ctx_dump(ctx, collada_fx_common_param_t, param, indent);
	}
}

/*-------------------------------------------------------------------------*/
