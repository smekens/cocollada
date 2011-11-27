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

collada_vcount_t *collada_vcount_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_vcount_t *result = collada_ctx_factory(ctx, collada_vcount_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_vector_int_t vector;
	collada_string_to_vector_int(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	result->count = vector.nr;
	result->array = vector.array;

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_vcount_dump(collada_ctx_t *ctx, collada_vcount_t *vcount, int indent)
{
	if(vcount == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Vcount:\n");

	indent++;

	COLLADA_DUMP_INDENT(indent);
	printf("Count: %d\n", vcount->count);

	COLLADA_DUMP_INDENT(indent);
	printf("Array:");

	for(i = 0; i < vcount->count && i < 10; i++){
		printf(" %d", vcount->array[i]);
	}

	if(vcount->count > 10) {
		printf(" ...");
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

