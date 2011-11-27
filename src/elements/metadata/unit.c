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

collada_unit_t *collada_unit_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_unit_t *result = collada_ctx_factory(ctx, collada_unit_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	result->meter = YAXP_GET_FLT_ATTR(node0, "meter", "0.0");
	result->name = YAXP_GET_STR_ATTR(node0, "name", "-- ??? --");

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_unit_dump(collada_ctx_t *ctx, collada_unit_t *unit, int indent)
{
	if(unit == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Unit:\n");

	indent++;

	COLLADA_DUMP_INDENT(indent);
	printf("Meter: %f\n", unit->meter);

	if(unit->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", unit->name);
	}
}

/*-------------------------------------------------------------------------*/

