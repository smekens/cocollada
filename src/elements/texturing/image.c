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

coco_image_t *coco_image_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_image_t *result = coco_ctx_factory(ctx, coco_image_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "format", NULL);
	if(str != NULL) {
		result->format = coco_ctx_strdup(ctx, str);
	}

	result->height = YAXP_GET_INT_ATTR(node0, "height", "-9999");

	result->width = YAXP_GET_INT_ATTR(node0, "width", "-9999");

	result->depth = YAXP_GET_INT_ATTR(node0, "depth", "-9999");

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3BCDA5FD: /* asset */
				asset = coco_ctx_parse(ctx, coco_asset_t, node1);

				result->asset = asset;
				break;

			case 0x459C759A: /* data */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->data = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x08084E80: /* init_from */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->init_from = coco_ctx_strdup(ctx, str);
				}
				else {
					coco_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no init_from !\n");
				}
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_append(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_image_check(coco_ctx_t *ctx, coco_image_t *image)
{
	if(image == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_image_dump(coco_ctx_t *ctx, coco_image_t *image, int indent)
{
	if(image == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Image:\n");

	indent++;

	if(image->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", image->id);
	}

	if(image->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", image->name);
	}

	if(image->format != NULL)
	{
		COCO_DUMP_INDENT(indent, "Format: %s\n", image->format);
	}

	if(image->height >= 0)
	{
		COCO_DUMP_INDENT(indent, "Height: %d\n", image->height);
	}

	if(image->width >= 0)
	{
		COCO_DUMP_INDENT(indent, "Width: %d\n", image->width);
	}

	if(image->depth >= 0)
	{
		COCO_DUMP_INDENT(indent, "Depth: %d\n", image->depth);
	}

	coco_ctx_dump(ctx, coco_asset_t, image->asset, indent);

	if(image->data != NULL)
	{
		COCO_DUMP_INDENT(indent, "Data: %s\n", image->data);
	}

	if(image->init_from != NULL)
	{
		COCO_DUMP_INDENT(indent, "Init from: %s\n", image->init_from);
	}

	ctnr_list_foreach(image->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

