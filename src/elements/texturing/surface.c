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

collada_surface_init_from_t *collada_surface_init_from_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_surface_init_from_t *result = collada_ctx_factory(ctx, collada_surface_init_from_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "mip", NULL);
	if(str != NULL) {
		result->mip = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "slice", NULL);
	if(str != NULL) {
		result->slice = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "face", NULL);
	if(str != NULL) {
		result->face = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_TEXT(node0, NULL);
	if(str != NULL) {
		result->ref = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_surface_init_from_dump(collada_ctx_t *ctx, collada_surface_init_from_t *init_from, int indent)
{
	if(init_from == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Init from:\n");

	indent++;

	if(init_from->mip != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Mip: %s\n", init_from->mip);
	}

	if(init_from->slice != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Slice: %s\n", init_from->slice);
	}

	if(init_from->face != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Face: %s\n", init_from->face);
	}

	if(init_from->ref != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Ref: %s\n", init_from->ref);
	}
}

/*-------------------------------------------------------------------------*/

collada_surface_t *collada_surface_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_surface_t *result = collada_ctx_factory(ctx, collada_surface_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_surface_init_from_t *init_from;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = collada_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x08084E80: /* init_from */
				init_from = collada_ctx_parser(ctx, collada_surface_init_from_t, node1);

				result->init_from = init_from;
				break;

			case 0x8BD63C2F: /* format */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->format = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}

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

void collada_surface_dump(collada_ctx_t *ctx, collada_surface_t *surface, int indent)
{
	if(surface == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Surface:\n");

	indent++;

	if(surface->type != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Type: %s\n", surface->type);
	}

	collada_ctx_dump(ctx, collada_surface_init_from_t, surface->init_from, indent);

	if(surface->format != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Format: %s\n", surface->format);
	}

	ctnr_list_foreach(surface->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

