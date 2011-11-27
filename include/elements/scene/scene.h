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

#ifndef __COLLADA_SCENE_H
#define __COLLADA_SCENE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_scene_s
{
	struct collada_base_s base;

	struct collada_scene_s *prev, *next;

	/**/

	/* TODO struct collada_instance_physics_scene_s *physics_scene_list;*/
	struct collada_instance_visual_scene_s *instance_visual_scene;

	struct collada_extra_s *extra_list;

} collada_scene_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_scene_s *collada_scene_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_scene_check(struct collada_ctx_s *, struct collada_scene_s *);

DLL_PUBLIC void collada_scene_dump(struct collada_ctx_s *, struct collada_scene_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SCENE_H */

/*-------------------------------------------------------------------------*/

