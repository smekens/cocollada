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

#ifndef __COLLADA_LIBRARY_CAMERAS_H
#define __COLLADA_LIBRARY_CAMERAS_H

/*-------------------------------------------------------------------------*/

typedef struct collada_library_cameras_s
{
	struct collada_base_s base;

	struct collada_library_cameras_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	struct collada_camera_s *camera_list;

	struct collada_extra_s *extra_list;

} collada_library_cameras_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_library_cameras_s *collada_library_cameras_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_library_cameras_check(struct collada_ctx_s *, struct collada_library_cameras_s *);

DLL_PUBLIC void collada_library_cameras_dump(struct collada_ctx_s *, struct collada_library_cameras_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_LIBRARY_CAMERAS_H */

/*-------------------------------------------------------------------------*/

