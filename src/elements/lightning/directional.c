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

coco_directional_t *coco_directional_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_directional_t *result = coco_ctx_factory(ctx, coco_directional_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_color_t *color;

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

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_directional_check(coco_ctx_t *ctx, coco_directional_t *directional)
{
	if(directional == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_directional_dump(coco_ctx_t *ctx, coco_directional_t *directional, int indent)
{
	if(directional == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Directional:\n");

	indent++;

	coco_ctx_dump(ctx, coco_color_t, directional->color, indent);
}

/*-------------------------------------------------------------------------*/

