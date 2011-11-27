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

#ifndef __COLLADA_MESH_H
#define __COLLADA_MESH_H

/*-------------------------------------------------------------------------*/

typedef struct collada_mesh_s
{
	struct collada_base_s base;

	struct collada_mesh_s *prev, *next;

	/**/

	struct collada_source_s *source_list;
	struct collada_vertices_s *vertices;

	/* TODO struct collada_lines_s *lines_list;*/
	/* TODO struct collada_linestrips_s *linestrips_list;*/
	/* TODO struct collada_polygons_s *polygons_list;*/
	struct collada_polylist_s *polylist_list;
	struct collada_triangles_s *triangles_list;
	/* TODO struct collada_trifans_s *trifans_list;*/
	/* TODO struct collada_tristrips_s *tristrips_list;*/

	struct collada_extra_s *extra_list;

} collada_mesh_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_mesh_s *collada_mesh_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_mesh_check(struct collada_ctx_s *, struct collada_mesh_s *);

DLL_PUBLIC void collada_mesh_dump(struct collada_ctx_s *, struct collada_mesh_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_MESH_H */

/*-------------------------------------------------------------------------*/

