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

coco_library_images_t *coco_library_images_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_library_images_t *result = coco_ctx_factory(ctx, coco_library_images_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_image_t *image;

	coco_extra_t *extra;

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

			case 0x585AC335: /* image */
				image = coco_ctx_parse(ctx, coco_image_t, node1);

				ctnr_list_add(result->image_list, image);
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

bool coco_library_images_check(coco_ctx_t *ctx, coco_library_images_t *library_images)
{
	if(library_images == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_library_images_dump(coco_ctx_t *ctx, coco_library_images_t *library_images, int indent)
{
	if(library_images == NULL) {
		return;
	}

	/**/

	int nr1;

	coco_image_t *image;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Library images:\n");

	indent++;

	coco_ctx_dump(ctx, coco_asset_t, library_images->asset, indent);

	ctnr_list_foreach(library_images->image_list, image, nr1) {
		coco_ctx_dump(ctx, coco_image_t, image, indent);
	}

	ctnr_list_foreach(library_images->extra_list, extra, nr1) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

