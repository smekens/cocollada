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

coco_camera_t *coco_camera_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_camera_t *result = coco_ctx_factory(ctx, coco_camera_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	/*-----------------------------------------------------------------*/
	/* id								   */
	/*-----------------------------------------------------------------*/

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);

	if(str != NULL)
	{
		result->id = coco_ctx_strdup(ctx, str);
	}

	/*-----------------------------------------------------------------*/
	/* name								   */
	/*-----------------------------------------------------------------*/

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);

	if(str != NULL)
	{
		result->name = coco_ctx_strdup(ctx, str);
	}

	/*-----------------------------------------------------------------*/

	int nr1;
	yaxp_node_t * node1;

	coco_asset_t *asset;
	coco_optics_t *optics;
	coco_extra_t *extra;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			/*-------------------------------------------------*/
			/* asset					   */
			/*-------------------------------------------------*/

			case 0x3BCDA5FD: /* asset */
				asset = coco_ctx_parse(ctx, coco_asset_t, node1);

				ctnr_list_add(result->asset, asset);
				break;

			/*-------------------------------------------------*/
			/* optics					   */
			/*-------------------------------------------------*/

			case 0x752C065A: /* optics */
				optics = coco_ctx_parse(ctx, coco_optics_t, node1);

				ctnr_list_add(result->optics, optics);
				break;

			/*-------------------------------------------------*/
			/* extra					   */
			/*-------------------------------------------------*/

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			/*-------------------------------------------------*/

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
				break;

			/*-------------------------------------------------*/
		}
	}

	/*-----------------------------------------------------------------*/

	coco_ctx_register(ctx, result, result->id);

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_camera_check(coco_ctx_t *ctx, coco_camera_t *camera)
{
	if(camera == NULL)
	{
		return false;
	}

	/**/

	int nr;

	coco_asset_t *asset;
	coco_optics_t *optics;
	coco_extra_t *extra;

	bool result = true;

	/*-----------------------------------------------------------------*/
	/* asset							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->asset, asset, nr)
	{
		result = result && coco_ctx_check(ctx, coco_asset_t, camera->asset);
	}
	if(nr > 1)
	{
		coco_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/
	/* optics							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->optics, optics, nr)
	{
		result = result && coco_ctx_check(ctx, coco_optics_t, camera->optics);
	}
	if(nr > 1)
	{
		coco_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/
	/* extra							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->extra_list, extra, nr)
	{
		result = result && coco_ctx_check(ctx, coco_extra_t, extra);
	}
	if(nr > 1)
	{
		coco_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_camera_dump(coco_ctx_t *ctx, coco_camera_t *camera, int indent)
{
	if(camera == NULL)
	{
		return;
	}

	/**/

	int nr;

	coco_asset_t *asset;
	coco_optics_t *optics;
	coco_extra_t *extra;

	/*-----------------------------------------------------------------*/

	COCO_DUMP_INDENT(indent, "Camera:\n");

	indent++;

	/*-----------------------------------------------------------------*/
	/* id								   */
	/*-----------------------------------------------------------------*/

	if(camera->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", camera->id);
	}

	/*-----------------------------------------------------------------*/
	/* name								   */
	/*-----------------------------------------------------------------*/

	if(camera->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", camera->name);
	}

	/*-----------------------------------------------------------------*/
	/* asset							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->asset, asset, nr)
	{
		coco_ctx_dump(ctx, coco_asset_t, camera->asset, indent);
	}

	/*-----------------------------------------------------------------*/
	/* optics							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->optics, optics, nr)
	{
		coco_ctx_dump(ctx, coco_optics_t, camera->optics, indent);
	}

	/*-----------------------------------------------------------------*/
	/* extra							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->extra_list, extra, nr)
	{
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}

	/*-----------------------------------------------------------------*/
}

/*-------------------------------------------------------------------------*/

