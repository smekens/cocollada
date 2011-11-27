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

coco_float_array_t *coco_float_array_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_float_array_t *result = coco_ctx_factory(ctx, coco_float_array_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	result->digits = YAXP_GET_INT_ATTR(node0, "digits", "-1");
	result->magnitude = YAXP_GET_INT_ATTR(node0, "magnitude", "-1");

	/**/

	coco_vector_flt_t vector;
	coco_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	if(result->count == vector.nr)
	{
		result->array = vector.array;
	}
	else
	{
		coco_vector_flt_free(ctx, &vector);

		coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "count (%d) does not match array size (%d)!\n", result->count, vector.nr);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_float_array_dump(coco_ctx_t *ctx, coco_float_array_t *float_array, int indent)
{
	if(float_array == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COCO_DUMP_INDENT(indent, "Float array:\n");

	indent++;

	if(float_array->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", float_array->id);
	}

	if(float_array->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", float_array->name);
	}

	if(float_array->count >= 0)
	{
		COCO_DUMP_INDENT(indent, "Count: %d\n", float_array->count);
	}

	if(float_array->digits >= 0)
	{
		COCO_DUMP_INDENT(indent, "Digits: %d\n", float_array->digits);
	}

	if(float_array->magnitude >= 0)
	{
		COCO_DUMP_INDENT(indent, "Magnitude: %d\n", float_array->magnitude);
	}

	if(float_array->count >= 0)
	{
		COCO_DUMP_INDENT(indent, "Array:");

		for(i = 0; i < float_array->count && i < 10; i++){
			printf(" %f", float_array->array[i]);
		}

		if(float_array->count > 10) {
			printf(" ...");
		}

		printf("\n");
	}
}

/*-------------------------------------------------------------------------*/

