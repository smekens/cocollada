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

collada_color_t *collada_color_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_color_t *result = collada_ctx_factory(ctx, collada_color_t);

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

	/**/ if(vector.nr == 3)
	{
		result->r = vector.array[0];
		result->g = vector.array[1];
		result->b = vector.array[2];
		result->a = 1.0f;
	}
	else if(vector.nr == 4)
	{
		result->r = vector.array[0];
		result->g = vector.array[1];
		result->b = vector.array[2];
		result->a = vector.array[3];
	}
	else
	{
		result->r = -9999.0f;
		result->g = -9999.0f;
		result->b = -9999.0f;
		result->a = -9999.0f;

		collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 3 or 4 !\n");
	}

	collada_vector_flt_free(ctx, &vector);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_color_dump(collada_ctx_t *ctx, collada_color_t *color, int indent)
{
	if(color == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Color:\n");

	indent++;

	if(color->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", color->sid);
	}

	if(color->r >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Red: %f\n", color->r);

		COLLADA_DUMP_INDENT(indent);
		printf("Green: %f\n", color->g);

		COLLADA_DUMP_INDENT(indent);
		printf("Blue: %f\n", color->b);

		COLLADA_DUMP_INDENT(indent);
		printf("Alpha: %f\n", color->a);
	}
}

/*-------------------------------------------------------------------------*/

