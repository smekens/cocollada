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

coco_accessor_param_t *coco_accessor_param_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_accessor_param_t *result = coco_ctx_factory(ctx, coco_accessor_param_t);

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

bool coco_accessor_param_check(coco_ctx_t *ctx, coco_accessor_param_t *accessor_param)
{
	if(accessor_param == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_accessor_param_dump(coco_ctx_t *ctx, coco_accessor_param_t *accessor_param, int indent)
{
	if(accessor_param == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Param:\n");

	indent++;

	if(accessor_param->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", accessor_param->name);
	}

	if(accessor_param->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", accessor_param->sid);
	}

	if(accessor_param->semantic != NULL)
	{
		COCO_DUMP_INDENT(indent, "Semantic: %s\n", accessor_param->semantic);
	}

	if(accessor_param->type != NULL)
	{
		COCO_DUMP_INDENT(indent, "Type: %s\n", accessor_param->type);
	}
}

/*-------------------------------------------------------------------------*/

coco_accessor_t *coco_accessor_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_accessor_t *result = coco_ctx_factory(ctx, coco_accessor_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_accessor_param_t *param;

	/**/

	const char *str;

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	result->offset = YAXP_GET_INT_ATTR(node0, "offset", "-1");

	str = YAXP_GET_STR_ATTR(node0, "source", NULL);
	if(str != NULL) {
		result->source = coco_ctx_strdup(ctx, str);
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
				param = coco_ctx_parse(ctx, coco_accessor_param_t, node1);

				ctnr_list_add(result->param_list, param);
				break;
			}
			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_accessor_check(coco_ctx_t *ctx, coco_accessor_t *accessor)
{
	if(accessor == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_accessor_dump(coco_ctx_t *ctx, coco_accessor_t *accessor, int indent)
{
	if(accessor == NULL) {
		return;
	}

	/**/

	int nr;

	coco_accessor_param_t *param;

	/**/

	COCO_DUMP_INDENT(indent, "Accessor:\n");

	indent++;

	if(accessor->count >= 0)
	{
		COCO_DUMP_INDENT(indent, "Count: %d\n", accessor->count);
	}

	if(accessor->offset >= 0)
	{
		COCO_DUMP_INDENT(indent, "Offset: %d\n", accessor->offset);
	}

	if(accessor->source != NULL)
	{
		COCO_DUMP_INDENT(indent, "Source: %s\n", accessor->source);
	}

	if(accessor->stride >= 0)
	{
		COCO_DUMP_INDENT(indent, "Stride: %d\n", accessor->stride);
	}

	ctnr_list_foreach(accessor->param_list, param, nr) {
		coco_ctx_dump(ctx, coco_accessor_param_t, param, indent);
	}
}

/*-------------------------------------------------------------------------*/

