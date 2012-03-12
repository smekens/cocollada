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

coco_geometry_t *coco_geometry_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_geometry_t *result = coco_ctx_factory(ctx, coco_geometry_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	/* TODO coco_convex_mesh_t *convex_mesh;*/
	coco_mesh_t *mesh;
	/* TODO coco_spline_t *spline;*/

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

			case 0x44F65A3B: /* convex_mesh */
				/* TODO convex_mesh = coco_convex_mesh_parse(ctx, node1);	*/
				/* TODO								*/
				/* TODO result->convex_mesh = convex_mesh;			*/
				goto __warning;

			case 0x025B744F: /* mesh */
				mesh = coco_ctx_parse(ctx, coco_mesh_t, node1);

				result->mesh = mesh;
				break;

			case 0xDC726BD8: /* spline */
				/* TODO spline = coco_spline_parse(ctx, node1);		*/
				/* TODO								*/
				/* TODO result->spline = spline;				*/
				goto __warning;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_append(result->extra_list, extra);
				break;

__warning:		default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_geometry_check(coco_ctx_t *ctx, coco_geometry_t *geometry)
{
	if(geometry == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_geometry_dump(coco_ctx_t *ctx, coco_geometry_t *geometry, int indent)
{
	if(geometry == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Geometry:\n");

	indent++;

	if(geometry->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", geometry->id);
	}

	if(geometry->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", geometry->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, geometry->asset, indent);

	/* TODO coco_convex_mesh_dump(geometry->convex_mesh, indent);*/
	coco_ctx_dump(ctx, coco_mesh_t, geometry->mesh, indent);
	/* TODO coco_spline_dump(geometry->spline, indent);*/

	ctnr_list_foreach(geometry->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

