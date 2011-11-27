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

collada_instance_effect_technique_hint_t *collada_instance_effect_technique_hint_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_instance_effect_technique_hint_t *result = collada_ctx_factory(ctx, collada_instance_effect_technique_hint_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "platform", NULL);
	if(str != NULL) {
		result->platform = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "profile", NULL);
	if(str != NULL) {
		result->profile = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "ref", NULL);
	if(str != NULL) {
		result->ref = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_instance_effect_technique_hint_dump(collada_ctx_t *ctx, collada_instance_effect_technique_hint_t *technique_hint, int indent)
{
	if(technique_hint == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique hint:\n");

	indent++;

	if(technique_hint->platform != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Platform: %s\n", technique_hint->platform);
	}

	if(technique_hint->profile != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Profile: %s\n", technique_hint->profile);
	}

	if(technique_hint->ref != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Ref: %s\n", technique_hint->ref);
	}
}

/*-------------------------------------------------------------------------*/

collada_instance_effect_t *collada_instance_effect_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_instance_effect_t *result = collada_ctx_factory(ctx, collada_instance_effect_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_instance_effect_technique_hint_t *technique_hint;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "url", NULL);
	if(str != NULL) {
		result->url = collada_ctx_strdup(ctx, str);
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
			case 0x639B057A: /* technique_hint */
				technique_hint = collada_ctx_parser(ctx, collada_instance_effect_technique_hint_t, node1);

				result->technique_hint = technique_hint;
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

void collada_instance_effect_dump(collada_ctx_t *ctx, collada_instance_effect_t *instance_effect, int indent)
{
	if(instance_effect == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Instance effect:\n");

	indent++;

	if(instance_effect->url != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Url: %s\n", instance_effect->url);
	}

	if(instance_effect->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", instance_effect->sid);
	}

	if(instance_effect->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", instance_effect->name);
	}

	collada_ctx_dump(ctx, collada_instance_effect_technique_hint_t, instance_effect->technique_hint, indent);

	ctnr_list_foreach(instance_effect->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

