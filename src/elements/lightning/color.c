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

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_color_t *coco_color_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_color_t *result = coco_ctx_factory(ctx, coco_color_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}

	coco_vector_flt_t vector;
	coco_string_to_vector_flt(ctx, &vector, YAXP_GET_STR_TEXT(node0, ""));

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

		coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 3 or 4 !\n");
	}

	coco_vector_flt_free(ctx, &vector);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_color_dump(coco_ctx_t *ctx, coco_color_t *color, int indent)
{
	if(color == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Color:\n");

	indent++;

	if(color->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", color->sid);
	}

	if(color->r >= 0)
	{
		COCO_DUMP_INDENT(indent, "Red: %f\n", color->r);

		COCO_DUMP_INDENT(indent, "Green: %f\n", color->g);

		COCO_DUMP_INDENT(indent, "Blue: %f\n", color->b);

		COCO_DUMP_INDENT(indent, "Alpha: %f\n", color->a);
	}
}

/*-------------------------------------------------------------------------*/

