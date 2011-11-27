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

collada_bind_material_param_t *collada_bind_material_param_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_bind_material_param_t *result = collada_ctx_factory(ctx, collada_bind_material_param_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_bind_material_param_dump(collada_ctx_t *ctx, collada_bind_material_param_t *param, int indent)
{
	if(param == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Param:\n");

	indent++;

	if(param->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s", param->name);
	}

	if(param->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s", param->sid);
	}

	if(param->semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Semantic: %s", param->semantic);
	}

	if(param->type != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Type: %s", param->type);
	}
}

/*-------------------------------------------------------------------------*/

collada_bind_material_technique_common_t *collada_bind_material_technique_common_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_bind_material_technique_common_t *result = collada_ctx_factory(ctx, collada_bind_material_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_instance_material_t *instance_material;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xD7BD5326: /* instance_material */
				instance_material = collada_ctx_parser(ctx, collada_instance_material_t, node1);

				ctnr_list_add(result->instance_material_list, instance_material);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_bind_material_technique_common_dump(collada_ctx_t *ctx, collada_bind_material_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	int nr;

	collada_instance_material_t *instance_material;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique common:\n");

	indent++;

	ctnr_list_foreach(technique_common->instance_material_list, instance_material, nr) {
		collada_ctx_dump(ctx, collada_instance_material_t, instance_material, indent);
	}
}

/*-------------------------------------------------------------------------*/

collada_bind_material_t *collada_bind_material_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_bind_material_t *result = collada_ctx_factory(ctx, collada_bind_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_bind_material_param_t *param;
	collada_bind_material_technique_common_t *technique_common;
	collada_technique_core_t *technique;

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x657C2B30: /* param */
				param = collada_ctx_parser(ctx, collada_bind_material_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;

			case 0x8BA567DA: /* technique_common */
				technique_common = collada_ctx_parser(ctx, collada_bind_material_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				technique = collada_ctx_parser(ctx, collada_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique);
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

void collada_bind_material_dump(collada_ctx_t *ctx, collada_bind_material_t *bind_material, int indent)
{
	if(bind_material == NULL) {
		return;
	}

	/**/

	int nr;

	collada_bind_material_param_t *param;
	collada_technique_core_t *technique;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Bind material:\n");

	indent++;

	ctnr_list_foreach(bind_material->param_list, param, nr) {
		collada_ctx_dump(ctx, collada_bind_material_param_t, param, indent);
	}

	collada_ctx_dump(ctx, collada_bind_material_technique_common_t, bind_material->technique_common, indent);

	ctnr_list_foreach(bind_material->technique_list, technique, nr) {
		collada_ctx_dump(ctx, collada_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(bind_material->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

