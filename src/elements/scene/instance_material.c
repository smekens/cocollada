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

collada_instance_material_t *collada_instance_material_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_instance_material_t *result = collada_ctx_factory(ctx, collada_instance_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_bind_vertex_input_t *bind_vertex_input;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "symbol", NULL);
	if(str != NULL) {
		result->symbol = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "target", NULL);
	if(str != NULL) {
		result->target = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
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
			case 0xC8DA7155: /* bind_vertex_input */
				bind_vertex_input = collada_ctx_parser(ctx, collada_bind_vertex_input_t, node1);

				ctnr_list_add(result->bind_vertex_input_list, bind_vertex_input);
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

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_instance_material_dump(collada_ctx_t *ctx, collada_instance_material_t *instance_material, int indent)
{
	if(instance_material == NULL) {
		return;
	}

	/**/

	int nr;

	collada_bind_vertex_input_t *bind_vertex_input;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Instance material:\n");

	indent++;

	if(instance_material->symbol != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Symbol: %s\n", instance_material->symbol);
	}

	if(instance_material->target != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Target: %s\n", instance_material->target);
	}

	if(instance_material->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", instance_material->sid);
	}

	if(instance_material->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", instance_material->name);
	}

	ctnr_list_foreach(instance_material->bind_vertex_input_list, bind_vertex_input, nr) {
		collada_ctx_dump(ctx, collada_bind_vertex_input_t, bind_vertex_input, indent);
	}

	ctnr_list_foreach(instance_material->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

