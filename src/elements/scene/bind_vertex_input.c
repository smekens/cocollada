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

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_bind_vertex_input_t *collada_bind_vertex_input_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_bind_vertex_input_t *result = collada_ctx_factory(ctx, collada_bind_vertex_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "input_semantic", NULL);
	if(str != NULL) {
		result->input_semantic = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "input_set", NULL);
	if(str != NULL) {
		result->input_set = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_bind_vertex_input_dump(collada_ctx_t *ctx, collada_bind_vertex_input_t *bind_vertex_input, int indent)
{
	if(bind_vertex_input == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Bind vertex input:\n");

	indent++;

	if(bind_vertex_input->semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Semantic: %s\n", bind_vertex_input->semantic);
	}

	if(bind_vertex_input->input_semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Input semantic: %s\n", bind_vertex_input->input_semantic);
	}

	if(bind_vertex_input->input_set != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Input set: %s\n", bind_vertex_input->input_set);
	}
}

/*-------------------------------------------------------------------------*/

