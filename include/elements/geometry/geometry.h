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

#ifndef __COLLADA_GEOMETRY_H
#define __COLLADA_GEOMETRY_H

/*-------------------------------------------------------------------------*/

typedef struct collada_geometry_s
{
	struct collada_base_s base;

	struct collada_geometry_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	/* TODO struct collada_convex_mesh_s *convex_mesh;*/
	struct collada_mesh_s *mesh;
	/* TODO struct collada_spline_s *spline;*/

	struct collada_extra_s *extra_list;

} collada_geometry_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_geometry_s *collada_geometry_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_geometry_check(struct collada_ctx_s *, struct collada_geometry_s *);

DLL_PUBLIC void collada_geometry_dump(struct collada_ctx_s *, struct collada_geometry_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_GEOMETRY_H */

/*-------------------------------------------------------------------------*/

