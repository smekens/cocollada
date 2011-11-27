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

coco_translate_t *coco_translate_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_translate_t *result = coco_ctx_factory(ctx, coco_translate_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}

	/**/

	coco_vector_flt_t vector;
	coco_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	if(vector.nr == 3)
	{
		memcpy(result->array, vector.array, 3 * sizeof(float));
	}
	else
	{
		coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 16 !\n");
	}

	coco_vector_flt_free(ctx, &vector);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_translate_check(coco_ctx_t *ctx, coco_translate_t *translate)
{
	if(translate == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_translate_dump(coco_ctx_t *ctx, coco_translate_t *translate, int indent)
{
	if(translate == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COCO_DUMP_INDENT(indent, "Translate:\n");

	indent++;

	COCO_DUMP_INDENT(indent, "Array:");

	for(i = 0; i < 3; i++){
		printf(" %f", translate->array[i]);
	}

	printf("\n");
}

/*-------------------------------------------------------------------------*/

