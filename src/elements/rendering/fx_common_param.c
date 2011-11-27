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

collada_fx_common_param_t *collada_fx_common_param_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_fx_common_param_t *result = collada_ctx_factory(ctx, collada_fx_common_param_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "ref", NULL);
	if(str != NULL) {
		result->ref = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_fx_common_param_dump(collada_ctx_t *ctx, collada_fx_common_param_t *fx_common_param, int indent)
{
	if(fx_common_param == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Param (FX):\n");

	indent++;

	if(fx_common_param->ref != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Ref: %s\n", fx_common_param->ref);
	}
}

/*-------------------------------------------------------------------------*/

