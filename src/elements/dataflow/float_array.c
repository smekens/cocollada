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

collada_float_array_t *collada_float_array_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_float_array_t *result = collada_ctx_factory(ctx, collada_float_array_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	result->digits = YAXP_GET_INT_ATTR(node0, "digits", "-1");
	result->magnitude = YAXP_GET_INT_ATTR(node0, "magnitude", "-1");

	/**/

	collada_vector_flt_t vector;
	collada_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

	if(result->count == vector.nr)
	{
		result->array = vector.array;
	}
	else
	{
		collada_vector_flt_free(ctx, &vector);

		collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "count (%d) does not match array size (%d)!\n", result->count, vector.nr);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_float_array_dump(collada_ctx_t *ctx, collada_float_array_t *float_array, int indent)
{
	if(float_array == NULL) {
		return;
	}

	/**/

	int i;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Float array:\n");

	indent++;

	if(float_array->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", float_array->id);
	}

	if(float_array->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", float_array->name);
	}

	if(float_array->count >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Count: %d\n", float_array->count);
	}

	if(float_array->digits >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Digits: %d\n", float_array->digits);
	}

	if(float_array->magnitude >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Magnitude: %d\n", float_array->magnitude);
	}

	if(float_array->count >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Array:");

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

