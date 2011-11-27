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

collada_image_t *collada_image_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_image_t *result = collada_ctx_factory(ctx, collada_image_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "format", NULL);
	if(str != NULL) {
		result->format = collada_ctx_strdup(ctx, str);
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
				asset = collada_ctx_parser(ctx, collada_asset_t, node1);

				result->asset = asset;
				break;

			case 0x459C759A: /* data */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->data = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no data !\n");
				}
				break;

			case 0x08084E80: /* init_from */
				str = YAXP_GET_STR_TEXT(node1, NULL);
				if(str != NULL) {
					result->init_from = collada_ctx_strdup(ctx, str);
				}
				else {
					collada_log(ctx, TYPE_ERROR, result->base.line, result->base.column, "no init_from !\n");
				}
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

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_image_dump(collada_ctx_t *ctx, collada_image_t *image, int indent)
{
	if(image == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Image:\n");

	indent++;

	if(image->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", image->id);
	}

	if(image->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", image->name);
	}

	if(image->format != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Format: %s\n", image->format);
	}

	if(image->height >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Height: %d\n", image->height);
	}

	if(image->width >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Width: %d\n", image->width);
	}

	if(image->depth >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Depth: %d\n", image->depth);
	}

	collada_ctx_dump(ctx, collada_asset_t, image->asset, indent);

	if(image->data != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Data: %s\n", image->data);
	}

	if(image->init_from != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Init from: %s\n", image->init_from);
	}

	ctnr_list_foreach(image->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

