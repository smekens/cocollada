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

coco_bind_material_param_t *coco_bind_material_param_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_bind_material_param_t *result = coco_ctx_factory(ctx, coco_bind_material_param_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "semantic", NULL);
	if(str != NULL) {
		result->semantic = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_bind_material_param_dump(coco_ctx_t *ctx, coco_bind_material_param_t *param, int indent)
{
	if(param == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Param:\n");

	indent++;

	if(param->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s", param->name);
	}

	if(param->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s", param->sid);
	}

	if(param->semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Semantic: %s", param->semantic);
	}

	if(param->type != NULL)
	{
		COCO_DUMP_INDENT(indent, "Type: %s", param->type);
	}
}

/*-------------------------------------------------------------------------*/

coco_bind_material_technique_common_t *coco_bind_material_technique_common_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_bind_material_technique_common_t *result = coco_ctx_factory(ctx, coco_bind_material_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_instance_material_t *instance_material;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xD7BD5326: /* instance_material */
				instance_material = coco_ctx_parse(ctx, coco_instance_material_t, node1);

				ctnr_list_add(result->instance_material_list, instance_material);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_bind_material_technique_common_dump(coco_ctx_t *ctx, coco_bind_material_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	int nr;

	coco_instance_material_t *instance_material;

	/**/

	COCO_DUMP_INDENT(indent, "Technique common:\n");

	indent++;

	ctnr_list_foreach(technique_common->instance_material_list, instance_material, nr) {
		coco_ctx_dump(ctx, coco_instance_material_t, instance_material, indent);
	}
}

/*-------------------------------------------------------------------------*/

coco_bind_material_t *coco_bind_material_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_bind_material_t *result = coco_ctx_factory(ctx, coco_bind_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_bind_material_param_t *param;
	coco_bind_material_technique_common_t *technique_common;
	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x657C2B30: /* param */
				param = coco_ctx_parse(ctx, coco_bind_material_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;

			case 0x8BA567DA: /* technique_common */
				technique_common = coco_ctx_parse(ctx, coco_bind_material_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				technique = coco_ctx_parse(ctx, coco_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique);
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

void coco_bind_material_dump(coco_ctx_t *ctx, coco_bind_material_t *bind_material, int indent)
{
	if(bind_material == NULL) {
		return;
	}

	/**/

	int nr;

	coco_bind_material_param_t *param;
	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Bind material:\n");

	indent++;

	ctnr_list_foreach(bind_material->param_list, param, nr) {
		coco_ctx_dump(ctx, coco_bind_material_param_t, param, indent);
	}

	coco_ctx_dump(ctx, coco_bind_material_technique_common_t, bind_material->technique_common, indent);

	ctnr_list_foreach(bind_material->technique_list, technique, nr) {
		coco_ctx_dump(ctx, coco_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(bind_material->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

