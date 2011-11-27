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

coco_instance_material_t *coco_instance_material_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_instance_material_t *result = coco_ctx_factory(ctx, coco_instance_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_bind_vertex_input_t *bind_vertex_input;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "symbol", NULL);
	if(str != NULL) {
		result->symbol = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "target", NULL);
	if(str != NULL) {
		result->target = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
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
			case 0xC8DA7155: /* bind_vertex_input */
				bind_vertex_input = coco_ctx_parse(ctx, coco_bind_vertex_input_t, node1);

				ctnr_list_add(result->bind_vertex_input_list, bind_vertex_input);
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

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_instance_material_check(coco_ctx_t *ctx, coco_instance_material_t *instance_material)
{
	if(instance_material == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_instance_material_dump(coco_ctx_t *ctx, coco_instance_material_t *instance_material, int indent)
{
	if(instance_material == NULL) {
		return;
	}

	/**/

	int nr;

	coco_bind_vertex_input_t *bind_vertex_input;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Instance material:\n");

	indent++;

	if(instance_material->symbol != NULL)
	{
		COCO_DUMP_INDENT(indent, "Symbol: %s\n", instance_material->symbol);
	}

	if(instance_material->target != NULL)
	{
		COCO_DUMP_INDENT(indent, "Target: %s\n", instance_material->target);
	}

	if(instance_material->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", instance_material->sid);
	}

	if(instance_material->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", instance_material->name);
	}

	ctnr_list_foreach(instance_material->bind_vertex_input_list, bind_vertex_input, nr) {
		coco_ctx_dump(ctx, coco_bind_vertex_input_t, bind_vertex_input, indent);
	}

	ctnr_list_foreach(instance_material->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

