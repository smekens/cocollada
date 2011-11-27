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

collada_mesh_t *collada_mesh_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_mesh_t *result = collada_ctx_factory(ctx, collada_mesh_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_source_t *source;
	collada_vertices_t *vertices;

	/* TODO collada_lines_t *lines;*/
	/* TODO collada_linestrips_t *linestrips;*/
	/* TODO collada_polygons_t *polygons;*/
	collada_polylist_t *polylist;
	collada_triangles_t *triangles;
	/* TODO collada_trifans_t *trifans;*/
	/* TODO collada_tristrips_t *tristrips;*/

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xB10CBC96: /* source */
				source = collada_ctx_parser(ctx, collada_source_t, node1);

				ctnr_list_add(result->source_list, source);
				break;

			case 0x752E6661: /* vertices */
				vertices = collada_ctx_parser(ctx, collada_vertices_t, node1);

				result->vertices = vertices;
				break;

			case 0x5A583A75: /* lines */
				/* TODO lines = collada_lines_parser(ctx, node1);		*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->lines_list, lines);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xCD2B3CF2: /* linestrips */
				/* TODO linestrips = collada_linestrips_parser(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->linestrips_list, linestrips);	*/
				/* TODO break;							*/
				goto __warning;

			case 0xC21AE5BC: /* polygons */
				/* TODO polygons = collada_polygons_parser(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->polygons_list, polygons);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xFB99F1AC: /* polylist */
				polylist = collada_ctx_parser(ctx, collada_polylist_t, node1);

				ctnr_list_add(result->polylist_list, polylist);
				break;

			case 0x288B8C15: /* triangles */
				triangles = collada_ctx_parser(ctx, collada_triangles_t, node1);

				ctnr_list_add(result->triangles_list, triangles);
				break;

			case 0x8D7658F7: /* trifans */
				/* TODO trifans = collada_trifans_parser(ctx, node1);		*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->trifans_list, trifans);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xF4A0A8E5: /* tristrips */
				/* TODO tristrips = collada_tristrips_parser(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->tristrips_list, tristrips);	*/
				/* TODO break;							*/
				goto __warning;

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

__warning:			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_mesh_dump(collada_ctx_t *ctx, collada_mesh_t *mesh, int indent)
{
	if(mesh == NULL) {
		return;
	}

	/**/

	int nr;

	collada_source_t *source;

	/* TODO collada_lines_t *lines;*/
	/* TODO collada_linestrips_t *linestrips;*/
	/* TODO collada_polygons_t *polygons;*/
	collada_polylist_t *polylist;
	collada_triangles_t *triangles;
	/* TODO collada_trifans_t *trifans;*/
	/* TODO collada_tristrips_t *tristrips;*/

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Mesh:\n");

	indent++;

	ctnr_list_foreach(mesh->source_list, source, nr) {
		collada_ctx_dump(ctx, collada_source_t, source, indent);
	}

	collada_ctx_dump(ctx, collada_vertices_t, mesh->vertices, indent);

	/* TODO ctnr_list_foreach(mesh->lines_list, lines, nr) {		*/
	/* TODO 	collada_lines_dump(lines, indent);			*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->linestrips_list, linestrips, nr) {	*/
	/* TODO 	collada_linestrips_dump(linestrips, indent);		*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->polygons_list, polygons, nr) {		*/
	/* TODO 	collada_polygons_dump(polygons, indent);		*/
	/* TODO }								*/

	ctnr_list_foreach(mesh->polylist_list, polylist, nr) {
		collada_ctx_dump(ctx, collada_polylist_t, polylist, indent);
	}

	ctnr_list_foreach(mesh->triangles_list, triangles, nr) {
		collada_ctx_dump(ctx, collada_triangles_t, triangles, indent);
	}

	/* TODO ctnr_list_foreach(mesh->trifans_list, trifans, nr) {		*/
	/* TODO 	collada_trifans_dump(trifans, indent);			*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->tristrips_list, tristrips, nr) {	*/
	/* TODO 	collada_tristrips_dump(tristrips, indent);		*/
	/* TODO }								*/

	ctnr_list_foreach(mesh->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

