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

collada_fx_common_float_t *collada_fx_common_float_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_fx_common_float_t *result = collada_ctx_factory(ctx, collada_fx_common_float_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}

	collada_vector_flt_t vector;
	collada_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	if(vector.nr == 1)
	{
		result->value = vector.array[0];
	}
	else
	{
		result->value = -9999.0f;

		collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 1 !\n");
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_fx_common_float_dump(collada_ctx_t *ctx, collada_fx_common_float_t *fx_common_float, int indent)
{
	if(fx_common_float == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Float:\n");

	indent++;

	if(fx_common_float->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", fx_common_float->sid);
	}

	if(fx_common_float->value >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Value: %f\n", fx_common_float->value);
	}
}

/*-------------------------------------------------------------------------*/

