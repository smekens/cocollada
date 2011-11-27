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

collada_sampler2D_t *collada_sampler2D_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_sampler2D_t *result = collada_ctx_factory(ctx, collada_sampler2D_t);

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
					result->source = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x26BB1ABC: /* wrap_s */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->wrap_s = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x46666FF1: /* wrap_t */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->wrap_t = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x5434B10B: /* minfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->minfilter = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0xFE4CB41A: /* magfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->magfilter = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0xA5F63A1A: /* mipfilter */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->mipfilter = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_sampler2D_dump(collada_ctx_t *ctx, collada_sampler2D_t *sampler2D, int indent)
{
	if(sampler2D == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("sampler2D:\n");

	indent++;

	if(sampler2D->source != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Source: %s\n", sampler2D->source);
	}

	if(sampler2D->wrap_t != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Wrap_t: %s\n", sampler2D->wrap_t);
	}

	if(sampler2D->wrap_s != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Wrap_s: %s\n", sampler2D->wrap_s);
	}

	if(sampler2D->minfilter != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Minfilter: %s\n", sampler2D->minfilter);
	}

	if(sampler2D->magfilter != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Magfilter: %s\n", sampler2D->magfilter);
	}

	if(sampler2D->mipfilter != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Mipfilter: %s\n", sampler2D->mipfilter);
	}
}

/*-------------------------------------------------------------------------*/

