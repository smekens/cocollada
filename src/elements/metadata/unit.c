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

coco_unit_t *coco_unit_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_unit_t *result = coco_ctx_factory(ctx, coco_unit_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	result->meter = YAXP_GET_FLT_ATTR(node0, "meter", "0.0");
	result->name = YAXP_GET_STR_ATTR(node0, "name", "-- ??? --");

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_unit_check(coco_ctx_t *ctx, coco_unit_t *unit)
{
	if(unit == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_unit_dump(coco_ctx_t *ctx, coco_unit_t *unit, int indent)
{
	if(unit == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Unit:\n");

	indent++;

	COCO_DUMP_INDENT(indent, "Meter: %f\n", unit->meter);

	if(unit->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", unit->name);
	}
}

/*-------------------------------------------------------------------------*/

