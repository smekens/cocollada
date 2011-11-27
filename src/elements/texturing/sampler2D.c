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

coco_sampler2D_t *coco_sampler2D_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_sampler2D_t *result = coco_ctx_factory(ctx, coco_sampler2D_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xB10CBC96: /* source */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->source = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x26BB1ABC: /* wrap_s */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->wrap_s = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x46666FF1: /* wrap_t */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->wrap_t = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x5434B10B: /* minfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->minfilter = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0xFE4CB41A: /* magfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->magfilter = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0xA5F63A1A: /* mipfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->mipfilter = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_sampler2D_dump(coco_ctx_t *ctx, coco_sampler2D_t *sampler2D, int indent)
{
	if(sampler2D == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "sampler2D:\n");

	indent++;

	if(sampler2D->source != NULL)
	{
		COCO_DUMP_INDENT(indent, "Source: %s\n", sampler2D->source);
	}

	if(sampler2D->wrap_t != NULL)
	{
		COCO_DUMP_INDENT(indent, "Wrap_t: %s\n", sampler2D->wrap_t);
	}

	if(sampler2D->wrap_s != NULL)
	{
		COCO_DUMP_INDENT(indent, "Wrap_s: %s\n", sampler2D->wrap_s);
	}

	if(sampler2D->minfilter != NULL)
	{
		COCO_DUMP_INDENT(indent, "Minfilter: %s\n", sampler2D->minfilter);
	}

	if(sampler2D->magfilter != NULL)
	{
		COCO_DUMP_INDENT(indent, "Magfilter: %s\n", sampler2D->magfilter);
	}

	if(sampler2D->mipfilter != NULL)
	{
		COCO_DUMP_INDENT(indent, "Mipfilter: %s\n", sampler2D->mipfilter);
	}
}

/*-------------------------------------------------------------------------*/

