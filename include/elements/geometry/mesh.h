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

#ifndef __COCO_MESH_H
#define __COCO_MESH_H

/*-------------------------------------------------------------------------*/

typedef struct coco_mesh_s
{
	struct coco_base_s base;

	struct coco_mesh_s *prev, *next;

	/**/

	struct coco_source_s *source_list;
	struct coco_vertices_s *vertices;

	/* TODO struct coco_lines_s *lines_list;*/
	/* TODO struct coco_linestrips_s *linestrips_list;*/
	/* TODO struct coco_polygons_s *polygons_list;*/
	struct coco_polylist_s *polylist_list;
	struct coco_triangles_s *triangles_list;
	/* TODO struct coco_trifans_s *trifans_list;*/
	/* TODO struct coco_tristrips_s *tristrips_list;*/

	struct coco_extra_s *extra_list;

} coco_mesh_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_mesh_s *coco_mesh_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_mesh_check(struct coco_ctx_s *, struct coco_mesh_s *);

DLL_PUBLIC void coco_mesh_dump(struct coco_ctx_s *, struct coco_mesh_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_MESH_H */

/*-------------------------------------------------------------------------*/

