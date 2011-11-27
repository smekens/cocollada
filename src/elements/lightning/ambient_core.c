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

collada_ambient_core_t *collada_ambient_core_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_ambient_core_t *result = collada_ctx_factory(ctx, collada_ambient_core_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_color_t *color;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2802D184: /* color */
				color = collada_ctx_parser(ctx, collada_color_t, node1);

				result->color = color;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_ambient_core_dump(collada_ctx_t *ctx, collada_ambient_core_t *ambient_core, int indent)
{
	if(ambient_core == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Ambient (core):\n");

	indent++;

	collada_ctx_dump(ctx, collada_color_t, ambient_core->color, indent);
}

/*-------------------------------------------------------------------------*/

