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

coco_surface_init_from_t *coco_surface_init_from_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_surface_init_from_t *result = coco_ctx_factory(ctx, coco_surface_init_from_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "mip", NULL);
	if(str != NULL) {
		result->mip = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "slice", NULL);
	if(str != NULL) {
		result->slice = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "face", NULL);
	if(str != NULL) {
		result->face = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_TEXT(node0, NULL);
	if(str != NULL) {
		result->ref = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_surface_init_from_check(coco_ctx_t *ctx, coco_surface_init_from_t *surface_init_from)
{
	if(surface_init_from == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_surface_init_from_dump(coco_ctx_t *ctx, coco_surface_init_from_t *init_from, int indent)
{
	if(init_from == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Init from:\n");

	indent++;

	if(init_from->mip != NULL)
	{
		COCO_DUMP_INDENT(indent, "Mip: %s\n", init_from->mip);
	}

	if(init_from->slice != NULL)
	{
		COCO_DUMP_INDENT(indent, "Slice: %s\n", init_from->slice);
	}

	if(init_from->face != NULL)
	{
		COCO_DUMP_INDENT(indent, "Face: %s\n", init_from->face);
	}

	if(init_from->ref != NULL)
	{
		COCO_DUMP_INDENT(indent, "Ref: %s\n", init_from->ref);
	}
}

/*-------------------------------------------------------------------------*/

coco_surface_t *coco_surface_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_surface_t *result = coco_ctx_factory(ctx, coco_surface_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_surface_init_from_t *init_from;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x08084E80: /* init_from */
				init_from = coco_ctx_parse(ctx, coco_surface_init_from_t, node1);

				result->init_from = init_from;
				break;

			case 0x8BD63C2F: /* format */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->format = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}

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

bool coco_surface_check(coco_ctx_t *ctx, coco_surface_t *surface)
{
	if(surface == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_surface_dump(coco_ctx_t *ctx, coco_surface_t *surface, int indent)
{
	if(surface == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Surface:\n");

	indent++;

	if(surface->type != NULL)
	{
		COCO_DUMP_INDENT(indent, "Type: %s\n", surface->type);
	}

	coco_ctx_dump(ctx, coco_surface_init_from_t, surface->init_from, indent);

	if(surface->format != NULL)
	{
		COCO_DUMP_INDENT(indent, "Format: %s\n", surface->format);
	}

	ctnr_list_foreach(surface->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

