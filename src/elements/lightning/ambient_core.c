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

coco_ambient_core_t *coco_ambient_core_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_ambient_core_t *result = coco_ctx_factory(ctx, coco_ambient_core_t);

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

void coco_ambient_core_dump(coco_ctx_t *ctx, coco_ambient_core_t *ambient_core, int indent)
{
	if(ambient_core == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Ambient (core):\n");

	indent++;

	coco_ctx_dump(ctx, coco_color_t, ambient_core->color, indent);
}

/*-------------------------------------------------------------------------*/

