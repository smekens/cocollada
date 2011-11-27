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

collada_camera_t *collada_camera_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_camera_t *result = collada_ctx_factory(ctx, collada_camera_t);

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
		result->id = collada_ctx_strdup(ctx, str);
	}

	/*-----------------------------------------------------------------*/
	/* name								   */
	/*-----------------------------------------------------------------*/

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);

	if(str != NULL)
	{
		result->name = collada_ctx_strdup(ctx, str);
	}

	/*-----------------------------------------------------------------*/

	int nr1;
	yaxp_node_t * node1;

	collada_asset_t *asset;
	collada_optics_t *optics;
	collada_extra_t *extra;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			/*-------------------------------------------------*/
			/* asset					   */
			/*-------------------------------------------------*/

			case 0x3BCDA5FD: /* asset */
				asset = collada_ctx_parser(ctx, collada_asset_t, node1);

				ctnr_list_add(result->asset, asset);
				break;

			/*-------------------------------------------------*/
			/* optics					   */
			/*-------------------------------------------------*/

			case 0x752C065A: /* optics */
				optics = collada_ctx_parser(ctx, collada_optics_t, node1);

				ctnr_list_add(result->optics, optics);
				break;

			/*-------------------------------------------------*/
			/* extra					   */
			/*-------------------------------------------------*/

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			/*-------------------------------------------------*/

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
				break;

			/*-------------------------------------------------*/
		}
	}

	/*-----------------------------------------------------------------*/

	collada_ctx_register(ctx, result, result->id);

	return result;
}

/*-------------------------------------------------------------------------*/

bool collada_camera_check(collada_ctx_t *ctx, collada_camera_t *camera)
{
	if(camera == NULL)
	{
		return false;
	}

	/**/

	int nr;

	collada_asset_t *asset;
	collada_optics_t *optics;
	collada_extra_t *extra;

	bool result = true;

	/*-----------------------------------------------------------------*/
	/* asset							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->asset, asset, nr)
	{
		result = result && collada_ctx_check(ctx, collada_asset_t, camera->asset);
	}
	if(nr > 1)
	{
		collada_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/
	/* optics							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->optics, optics, nr)
	{
		result = result && collada_ctx_check(ctx, collada_optics_t, camera->optics);
	}
	if(nr > 1)
	{
		collada_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/
	/* extra							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->extra_list, extra, nr)
	{
		result = result && collada_ctx_check(ctx, collada_extra_t, extra);
	}
	if(nr > 1)
	{
		collada_log(ctx, TYPE_ERROR, camera->base.line, camera->base.column, "too many asset node\n");
	}

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_camera_dump(collada_ctx_t *ctx, collada_camera_t *camera, int indent)
{
	if(camera == NULL)
	{
		return;
	}

	/**/

	int nr;

	collada_asset_t *asset;
	collada_optics_t *optics;
	collada_extra_t *extra;

	/*-----------------------------------------------------------------*/

	COLLADA_DUMP_INDENT(indent, "Camera:\n");

	indent++;

	/*-----------------------------------------------------------------*/
	/* id								   */
	/*-----------------------------------------------------------------*/

	if(camera->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", camera->id);
	}

	/*-----------------------------------------------------------------*/
	/* name								   */
	/*-----------------------------------------------------------------*/

	if(camera->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", camera->name);
	}

	/*-----------------------------------------------------------------*/
	/* asset							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->asset, asset, nr)
	{
		collada_ctx_dump(ctx, collada_asset_t, camera->asset, indent);
	}

	/*-----------------------------------------------------------------*/
	/* optics							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->optics, optics, nr)
	{
		collada_ctx_dump(ctx, collada_optics_t, camera->optics, indent);
	}

	/*-----------------------------------------------------------------*/
	/* extra							   */
	/*-----------------------------------------------------------------*/

	ctnr_list_foreach(camera->extra_list, extra, nr)
	{
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}

	/*-----------------------------------------------------------------*/
}

/*-------------------------------------------------------------------------*/

