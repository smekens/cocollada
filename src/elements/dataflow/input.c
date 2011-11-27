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

coco_input_t *coco_input_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_input_t *result = coco_ctx_factory(ctx, coco_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	result->offset = YAXP_GET_INT_ATTR(node0, "offset", "-1");

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = coco_ctx_strdup(ctx, str);
	}

	result->set = YAXP_GET_INT_ATTR(node0, "set", "-1");

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_input_dump(coco_ctx_t *ctx, coco_input_t *input, int indent)
{
	if(input == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Input:\n");

	indent++;

	if(input->offset >= 0)
	{
		COCO_DUMP_INDENT(indent, "Offset: %d\n", input->offset);
	}

	if(input->semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Semantic: %s\n", input->semantic);
	}

	if(input->source != NULL)
	{
		COCO_DUMP_INDENT(indent, "Source: %s\n", input->source);
	}

	if(input->set >= 0)
	{
		COCO_DUMP_INDENT(indent, "Stride: %d\n", input->set);
	}
}

/*-------------------------------------------------------------------------*/

