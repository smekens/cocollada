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

coco_bind_vertex_input_t *coco_bind_vertex_input_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_bind_vertex_input_t *result = coco_ctx_factory(ctx, coco_bind_vertex_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "input_semantic", NULL);
	if(str != NULL) {
		result->input_semantic = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "input_set", NULL);
	if(str != NULL) {
		result->input_set = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_bind_vertex_input_check(coco_ctx_t *ctx, coco_bind_vertex_input_t *bind_vertex_input)
{
	if(bind_vertex_input == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_bind_vertex_input_dump(coco_ctx_t *ctx, coco_bind_vertex_input_t *bind_vertex_input, int indent)
{
	if(bind_vertex_input == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Bind vertex input:\n");

	indent++;

	if(bind_vertex_input->semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Semantic: %s\n", bind_vertex_input->semantic);
	}

	if(bind_vertex_input->input_semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Input semantic: %s\n", bind_vertex_input->input_semantic);
	}

	if(bind_vertex_input->input_set != NULL)
	{
		COCO_DUMP_INDENT(indent, "Input set: %s\n", bind_vertex_input->input_set);
	}
}

/*-------------------------------------------------------------------------*/

