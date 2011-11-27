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

coco_vcount_t *coco_vcount_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_vcount_t *result = coco_ctx_factory(ctx, coco_vcount_t);

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

void coco_vcount_dump(coco_ctx_t *ctx, coco_vcount_t *vcount, int indent)
{
	if(vcount == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COCO_DUMP_INDENT(indent, "Vcount:\n");

	indent++;

	COCO_DUMP_INDENT(indent, "Count: %d\n", vcount->count);

	COCO_DUMP_INDENT(indent, "Array:");

	for(i = 0; i < vcount->count && i < 10; i++){
		printf(" %d", vcount->array[i]);
	}

	if(vcount->count > 10) {
		printf(" ...");
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

