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

coco_mesh_t *coco_mesh_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_mesh_t *result = coco_ctx_factory(ctx, coco_mesh_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_source_t *source;
	coco_vertices_t *vertices;

	/* TODO coco_lines_t *lines;*/
	/* TODO coco_linestrips_t *linestrips;*/
	/* TODO coco_polygons_t *polygons;*/
	coco_polylist_t *polylist;
	coco_triangles_t *triangles;
	/* TODO coco_trifans_t *trifans;*/
	/* TODO coco_tristrips_t *tristrips;*/

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xB10CBC96: /* source */
				source = coco_ctx_parse(ctx, coco_source_t, node1);

				ctnr_list_add(result->source_list, source);
				break;

			case 0x752E6661: /* vertices */
				vertices = coco_ctx_parse(ctx, coco_vertices_t, node1);

				result->vertices = vertices;
				break;

			case 0x5A583A75: /* lines */
				/* TODO lines = coco_lines_parse(ctx, node1);		*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->lines_list, lines);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xCD2B3CF2: /* linestrips */
				/* TODO linestrips = coco_linestrips_parse(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->linestrips_list, linestrips);	*/
				/* TODO break;							*/
				goto __warning;

			case 0xC21AE5BC: /* polygons */
				/* TODO polygons = coco_polygons_parse(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->polygons_list, polygons);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xFB99F1AC: /* polylist */
				polylist = coco_ctx_parse(ctx, coco_polylist_t, node1);

				ctnr_list_add(result->polylist_list, polylist);
				break;

			case 0x288B8C15: /* triangles */
				triangles = coco_ctx_parse(ctx, coco_triangles_t, node1);

				ctnr_list_add(result->triangles_list, triangles);
				break;

			case 0x8D7658F7: /* trifans */
				/* TODO trifans = coco_trifans_parse(ctx, node1);		*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->trifans_list, trifans);		*/
				/* TODO break;							*/
				goto __warning;

			case 0xF4A0A8E5: /* tristrips */
				/* TODO tristrips = coco_tristrips_parse(ctx, node1);	*/
				/* TODO								*/
				/* TODO ctnr_list_add(result->tristrips_list, tristrips);	*/
				/* TODO break;							*/
				goto __warning;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

__warning:			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_mesh_dump(coco_ctx_t *ctx, coco_mesh_t *mesh, int indent)
{
	if(mesh == NULL) {
		return;
	}

	/**/

	int nr;

	coco_source_t *source;

	/* TODO coco_lines_t *lines;*/
	/* TODO coco_linestrips_t *linestrips;*/
	/* TODO coco_polygons_t *polygons;*/
	coco_polylist_t *polylist;
	coco_triangles_t *triangles;
	/* TODO coco_trifans_t *trifans;*/
	/* TODO coco_tristrips_t *tristrips;*/

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Mesh:\n");

	indent++;

	ctnr_list_foreach(mesh->source_list, source, nr) {
		coco_ctx_dump(ctx, coco_source_t, source, indent);
	}

	coco_ctx_dump(ctx, coco_vertices_t, mesh->vertices, indent);

	/* TODO ctnr_list_foreach(mesh->lines_list, lines, nr) {		*/
	/* TODO 	coco_lines_dump(lines, indent);			*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->linestrips_list, linestrips, nr) {	*/
	/* TODO 	coco_linestrips_dump(linestrips, indent);		*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->polygons_list, polygons, nr) {		*/
	/* TODO 	coco_polygons_dump(polygons, indent);		*/
	/* TODO }								*/

	ctnr_list_foreach(mesh->polylist_list, polylist, nr) {
		coco_ctx_dump(ctx, coco_polylist_t, polylist, indent);
	}

	ctnr_list_foreach(mesh->triangles_list, triangles, nr) {
		coco_ctx_dump(ctx, coco_triangles_t, triangles, indent);
	}

	/* TODO ctnr_list_foreach(mesh->trifans_list, trifans, nr) {		*/
	/* TODO 	coco_trifans_dump(trifans, indent);			*/
	/* TODO }								*/

	/* TODO ctnr_list_foreach(mesh->tristrips_list, tristrips, nr) {	*/
	/* TODO 	coco_tristrips_dump(tristrips, indent);		*/
	/* TODO }								*/

	ctnr_list_foreach(mesh->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

