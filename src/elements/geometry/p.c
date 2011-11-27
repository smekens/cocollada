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

collada_p_t *collada_p_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_p_t *result = collada_ctx_factory(ctx, collada_p_t);

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

void collada_p_dump(collada_ctx_t *ctx, collada_p_t *p, int indent)
{
	if(p == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("P:\n");

	indent++;

	COLLADA_DUMP_INDENT(indent);
	printf("Count: %d\n", p->count);

	COLLADA_DUMP_INDENT(indent);
	printf("Array:");

	for(i = 0; i < p->count && i < 10; i++){
		printf(" %d", p->array[i]);
	}

	if(p->count > 10) {
		printf(" ...");
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

