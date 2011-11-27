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

collada_vertices_input_t *collada_vertices_input_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_vertices_input_t *result = collada_ctx_factory(ctx, collada_vertices_input_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_vertices_input_dump(collada_ctx_t *ctx, collada_vertices_input_t *vertices_input, int indent)
{
	if(vertices_input == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Input:\n");

	indent++;

	if(vertices_input->semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Semantic: %s\n", vertices_input->semantic);
	}

	if(vertices_input->source != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Source: %s\n", vertices_input->source);
	}
}

/*-------------------------------------------------------------------------*/

collada_vertices_t *collada_vertices_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_vertices_t *result = collada_ctx_factory(ctx, collada_vertices_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_vertices_input_t *vertices_input;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x9F642814: /* input */
				vertices_input = collada_ctx_parser(ctx, collada_vertices_input_t, node1);

				ctnr_list_add(result->input_list, vertices_input);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_vertices_dump(collada_ctx_t *ctx, collada_vertices_t *vertices, int indent)
{
	if(vertices == NULL) {
		return;
	}

	/**/

	int nr;

	collada_vertices_input_t *vertices_input;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Vertices:\n");

	indent++;

	if(vertices->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", vertices->id);
	}

	if(vertices->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", vertices->name);
	}

	ctnr_list_foreach(vertices->input_list, vertices_input, nr) {
		collada_ctx_dump(ctx, collada_vertices_input_t, vertices_input, indent);
	}

	ctnr_list_foreach(vertices->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

