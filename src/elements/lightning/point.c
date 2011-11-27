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

coco_point_t *coco_point_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_point_t *result = coco_ctx_factory(ctx, coco_point_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_color_t *color;

	/**/

	result->constant_attenuation = -9999.0f;
	result->linear_attenuation = -9999.0f;
	result->quadratic_attenuation = -9999.0f;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2802D184: /* color */
				color = coco_ctx_parse(ctx, coco_color_t, node1);

				result->color = color;
				break;

			case 0x65E5140C: /* constant_attenuation */
				result->constant_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0xA4ABA437: /* linear_attenuation */
				result->linear_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x9F6FF61E: /* quadratic_attenuation */
				result->quadratic_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_point_check(coco_ctx_t *ctx, coco_point_t *point)
{
	if(point == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_point_dump(coco_ctx_t *ctx, coco_point_t *point, int indent)
{
	if(point == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Point:\n");

	indent++;

	coco_ctx_dump(ctx, coco_color_t, point->color, indent);

	if(point->constant_attenuation != -9999.0f)
	{
		COCO_DUMP_INDENT(indent, "Constant attenuation: %f\n", point->constant_attenuation);
	}

	if(point->linear_attenuation != -9999.0f)
	{
		COCO_DUMP_INDENT(indent, "Linear attenuation: %f\n", point->linear_attenuation);
	}

	if(point->quadratic_attenuation != -9999.0f)
	{
		COCO_DUMP_INDENT(indent, "Quadratic attenuation: %f\n", point->quadratic_attenuation);
	}
}

/*-------------------------------------------------------------------------*/

