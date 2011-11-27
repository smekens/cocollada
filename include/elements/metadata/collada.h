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

#ifndef __COLLADA_COLLADA_H
#define __COLLADA_COLLADA_H

/*-------------------------------------------------------------------------*/

typedef struct collada_s
{
	struct collada_base_s base;

	struct collada_s *prev, *next;

	/**/

	const char *version;

	struct collada_asset_s *asset;

	/* TODO struct collada_library_animation_s *library_animation_list;*/
	/* TODO struct collada_library_animation_clips_s *library_animation_clips_list;*/
	struct collada_library_cameras_s *library_cameras_list;
	/* TODO struct collada_library_controllers_s *library_controllers_list;*/
	struct collada_library_effects_s *library_effects_list;
	/* TODO struct collada_library_force_fields_s *library_force_fields_list;*/
	struct collada_library_geometries_s *library_geometries_list;
	struct collada_library_images_s *library_images_list;
	struct collada_library_lights_s *library_lights_list;
	struct collada_library_materials_s *library_materials_list;
	struct collada_library_nodes_s *library_nodes_list;
	/* TODO struct collada_library_physics_materials_s *library_physics_materials_list;*/
	/* TODO struct collada_library_physics_models_s *library_physics_models_list;*/
	/* TODO struct collada_library_physics_scenes_s *library_physics_scenes_list;*/
	struct collada_library_visual_scenes_s *library_visual_scenes_list;

	struct collada_scene_s *scene;

	struct collada_extra_s *extra_list;

} collada_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_s *collada_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_check(struct collada_ctx_s *, struct collada_s *);

DLL_PUBLIC void collada_dump(struct collada_ctx_s *, struct collada_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_COLLADA_H */

/*-------------------------------------------------------------------------*/

