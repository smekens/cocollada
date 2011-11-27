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

coco_vertices_input_t *coco_vertices_input_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_vertices_input_t *result = coco_ctx_factory(ctx, coco_vertices_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_vertices_input_dump(coco_ctx_t *ctx, coco_vertices_input_t *vertices_input, int indent)
{
	if(vertices_input == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Input:\n");

	indent++;

	if(vertices_input->semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Semantic: %s\n", vertices_input->semantic);
	}

	if(vertices_input->source != NULL)
	{
		COCO_DUMP_INDENT(indent, "Source: %s\n", vertices_input->source);
	}
}

/*-------------------------------------------------------------------------*/

coco_vertices_t *coco_vertices_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_vertices_t *result = coco_ctx_factory(ctx, coco_vertices_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_vertices_input_t *vertices_input;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x9F642814: /* input */
				vertices_input = coco_ctx_parse(ctx, coco_vertices_input_t, node1);

				ctnr_list_add(result->input_list, vertices_input);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_vertices_dump(coco_ctx_t *ctx, coco_vertices_t *vertices, int indent)
{
	if(vertices == NULL) {
		return;
	}

	/**/

	int nr;

	coco_vertices_input_t *vertices_input;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Vertices:\n");

	indent++;

	if(vertices->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", vertices->id);
	}

	if(vertices->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", vertices->name);
	}

	ctnr_list_foreach(vertices->input_list, vertices_input, nr) {
		coco_ctx_dump(ctx, coco_vertices_input_t, vertices_input, indent);
	}

	ctnr_list_foreach(vertices->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

