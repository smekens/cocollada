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

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_geometry_t *collada_geometry_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_geometry_t *result = collada_ctx_factory(ctx, collada_geometry_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	/* TODO collada_convex_mesh_t *convex_mesh;*/
	collada_mesh_t *mesh;
	/* TODO collada_spline_t *spline;*/

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

			case 0x44F65A3B: /* convex_mesh */
				/* TODO convex_mesh = collada_convex_mesh_parser(ctx, node1);	*/
				/* TODO								*/
				/* TODO result->convex_mesh = convex_mesh;			*/
				goto __warning;

			case 0x025B744F: /* mesh */
				mesh = collada_ctx_parser(ctx, collada_mesh_t, node1);

				result->mesh = mesh;
				break;

			case 0xDC726BD8: /* spline */
				/* TODO spline = collada_spline_parser(ctx, node1);		*/
				/* TODO								*/
				/* TODO result->spline = spline;				*/
				goto __warning;

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

__warning:		default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_geometry_dump(collada_ctx_t *ctx, collada_geometry_t *geometry, int indent)
{
	if(geometry == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Geometry:\n");

	indent++;

	if(geometry->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", geometry->id);
	}

	if(geometry->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", geometry->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, geometry->asset, indent);

	/* TODO collada_convex_mesh_dump(geometry->convex_mesh, indent);*/
	collada_ctx_dump(ctx, collada_mesh_t, geometry->mesh, indent);
	/* TODO collada_spline_dump(geometry->spline, indent);*/

	ctnr_list_foreach(geometry->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

