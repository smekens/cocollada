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

coco_fx_common_float_t *coco_fx_common_float_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_fx_common_float_t *result = coco_ctx_factory(ctx, coco_fx_common_float_t);

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

	if(vector.nr == 1)
	{
		result->value = vector.array[0];
	}
	else
	{
		result->value = -9999.0f;

		coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "number of values should be 1 !\n");
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_fx_common_float_check(coco_ctx_t *ctx, coco_fx_common_float_t *fx_common_float)
{
	if(fx_common_float == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_fx_common_float_dump(coco_ctx_t *ctx, coco_fx_common_float_t *fx_common_float, int indent)
{
	if(fx_common_float == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Float:\n");

	indent++;

	if(fx_common_float->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", fx_common_float->sid);
	}

	if(fx_common_float->value >= 0)
	{
		COCO_DUMP_INDENT(indent, "Value: %f\n", fx_common_float->value);
	}
}

/*-------------------------------------------------------------------------*/

