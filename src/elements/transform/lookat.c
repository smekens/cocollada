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
#include <stdlib.h>

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_lookat_t *collada_lookat_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_lookat_t *result = collada_ctx_factory(ctx, collada_lookat_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}

	/**/

	collada_vector_flt_t vector;
	collada_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	if(vector.nr == 9)
	{
		memcpy(result->array, vector.array, 9 * sizeof(float));
	}
	else
	{
		collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 9 !\n");
	}

	collada_vector_flt_free(ctx, &vector);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_lookat_dump(collada_ctx_t *ctx, collada_lookat_t *lookat, int indent)
{
	if(lookat == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Lookat:\n");

	indent++;

	COLLADA_DUMP_INDENT(indent);
	printf("Array:");

	for(i = 0; i < 9; i++){
		printf(" %f", lookat->array[i]);
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

