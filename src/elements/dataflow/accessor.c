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

collada_accessor_param_t *collada_accessor_param_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_accessor_param_t *result = collada_ctx_factory(ctx, collada_accessor_param_t);

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

void collada_accessor_param_dump(collada_ctx_t *ctx, collada_accessor_param_t *accessor_param, int indent)
{
	if(accessor_param == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Param:\n");

	indent++;

	if(accessor_param->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", accessor_param->name);
	}

	if(accessor_param->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", accessor_param->sid);
	}

	if(accessor_param->semantic != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Semantic: %s\n", accessor_param->semantic);
	}

	if(accessor_param->type != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Type: %s\n", accessor_param->type);
	}
}

/*-------------------------------------------------------------------------*/

collada_accessor_t *collada_accessor_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_accessor_t *result = collada_ctx_factory(ctx, collada_accessor_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_accessor_param_t *param;

	/**/

	const char *str;

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	result->offset = YAXP_GET_INT_ATTR(node0, "offset", "-1");

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = collada_ctx_strdup(ctx, str);
	}

	result->stride = YAXP_GET_INT_ATTR(node0, "stride", "-1");

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x657C2B30: /* param */
			{
				param = collada_ctx_parser(ctx, collada_accessor_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;
			}
			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_accessor_dump(collada_ctx_t *ctx, collada_accessor_t *accessor, int indent)
{
	if(accessor == NULL) {
		return;
	}

	/**/

	int nr;

	collada_accessor_param_t *param;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Accessor:\n");

	indent++;

	if(accessor->count >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Count: %d\n", accessor->count);
	}

	if(accessor->offset >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Offset: %d\n", accessor->offset);
	}

	if(accessor->source != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Source: %s\n", accessor->source);
	}

	if(accessor->stride >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Stride: %d\n", accessor->stride);
	}

	ctnr_list_foreach(accessor->param_list, param, nr) {
		collada_ctx_dump(ctx, collada_accessor_param_t, param, indent);
	}
}

/*-------------------------------------------------------------------------*/

