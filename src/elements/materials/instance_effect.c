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

coco_instance_effect_technique_hint_t *coco_instance_effect_technique_hint_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_instance_effect_technique_hint_t *result = coco_ctx_factory(ctx, coco_instance_effect_technique_hint_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "platform", NULL);
	if(str != NULL) {
		result->platform = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "profile", NULL);
	if(str != NULL) {
		result->profile = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "ref", NULL);
	if(str != NULL) {
		result->ref = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_instance_effect_technique_hint_check(coco_ctx_t *ctx, coco_instance_effect_technique_hint_t *instance_effect_technique_hint)
{
	if(instance_effect_technique_hint == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_instance_effect_technique_hint_dump(coco_ctx_t *ctx, coco_instance_effect_technique_hint_t *technique_hint, int indent)
{
	if(technique_hint == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Technique hint:\n");

	indent++;

	if(technique_hint->platform != NULL)
	{
		COCO_DUMP_INDENT(indent, "Platform: %s\n", technique_hint->platform);
	}

	if(technique_hint->profile != NULL)
	{
		COCO_DUMP_INDENT(indent, "Profile: %s\n", technique_hint->profile);
	}

	if(technique_hint->ref != NULL)
	{
		COCO_DUMP_INDENT(indent, "Ref: %s\n", technique_hint->ref);
	}
}

/*-------------------------------------------------------------------------*/

coco_instance_effect_t *coco_instance_effect_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_instance_effect_t *result = coco_ctx_factory(ctx, coco_instance_effect_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_instance_effect_technique_hint_t *technique_hint;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "url", NULL);
	if(str != NULL) {
		result->url = coco_ctx_strdup(ctx, str);
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
			case 0x639B057A: /* technique_hint */
				technique_hint = coco_ctx_parse(ctx, coco_instance_effect_technique_hint_t, node1);

				result->technique_hint = technique_hint;
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

bool coco_instance_effect_check(coco_ctx_t *ctx, coco_instance_effect_t *instance_effect)
{
	if(instance_effect == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_instance_effect_dump(coco_ctx_t *ctx, coco_instance_effect_t *instance_effect, int indent)
{
	if(instance_effect == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Instance effect:\n");

	indent++;

	if(instance_effect->url != NULL)
	{
		COCO_DUMP_INDENT(indent, "Url: %s\n", instance_effect->url);
	}

	if(instance_effect->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", instance_effect->sid);
	}

	if(instance_effect->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", instance_effect->name);
	}

	coco_ctx_dump(ctx, coco_instance_effect_technique_hint_t, instance_effect->technique_hint, indent);

	ctnr_list_foreach(instance_effect->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

