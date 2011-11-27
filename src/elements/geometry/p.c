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

coco_p_t *coco_p_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_p_t *result = coco_ctx_factory(ctx, coco_p_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_vector_int_t vector;
	coco_string_to_vector_int(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	result->count = vector.nr;
	result->array = vector.array;

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_p_check(coco_ctx_t *ctx, coco_p_t *p)
{
	if(p == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_p_dump(coco_ctx_t *ctx, coco_p_t *p, int indent)
{
	if(p == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COCO_DUMP_INDENT(indent, "P:\n");

	indent++;

	COCO_DUMP_INDENT(indent, "Count: %d\n", p->count);

	COCO_DUMP_INDENT(indent, "Array:");

	for(i = 0; i < p->count && i < 10; i++){
		printf(" %d", p->array[i]);
	}

	if(p->count > 10) {
		printf(" ...");
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

