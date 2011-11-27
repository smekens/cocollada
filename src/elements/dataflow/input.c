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

collada_input_t *collada_input_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_input_t *result = collada_ctx_factory(ctx, collada_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	result->offset = YAXP_GET_INT_ATTR(node0, "offset", "-1");

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = collada_ctx_strdup(ctx, str);
	}

	result->set = YAXP_GET_INT_ATTR(node0, "set", "-1");

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_input_dump(collada_ctx_t *ctx, collada_input_t *input, int indent)
{
	if(input == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Input:\n");

	indent++;

	if(input->offset >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Offset: %d\n", input->offset);
	}

	if(input->semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Semantic: %s\n", input->semantic);
	}

	if(input->source != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Source: %s\n", input->source);
	}

	if(input->set >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Stride: %d\n", input->set);
	}
}

/*-------------------------------------------------------------------------*/

