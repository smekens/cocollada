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

#ifndef __COCO_COLLADA_H
#define __COCO_COLLADA_H

/*-------------------------------------------------------------------------*/

typedef struct coco_collada_s
{
	struct coco_base_s base;

	struct coco_collada_s *prev, *next;

	/**/

	const char *version;

	struct coco_asset_s *asset;

	/* TODO struct coco_library_animation_s *library_animation_list;*/
	/* TODO struct coco_library_animation_clips_s *library_animation_clips_list;*/
	struct coco_library_cameras_s *library_cameras_list;
	/* TODO struct coco_library_controllers_s *library_controllers_list;*/
	struct coco_library_effects_s *library_effects_list;
	/* TODO struct coco_library_force_fields_s *library_force_fields_list;*/
	struct coco_library_geometries_s *library_geometries_list;
	struct coco_library_images_s *library_images_list;
	struct coco_library_lights_s *library_lights_list;
	struct coco_library_materials_s *library_materials_list;
	struct coco_library_nodes_s *library_nodes_list;
	/* TODO struct coco_library_physics_materials_s *library_physics_materials_list;*/
	/* TODO struct coco_library_physics_models_s *library_physics_models_list;*/
	/* TODO struct coco_library_physics_scenes_s *library_physics_scenes_list;*/
	struct coco_library_visual_scenes_s *library_visual_scenes_list;

	struct coco_scene_s *scene;

	struct coco_extra_s *extra_list;

} coco_collada_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_collada_s *coco_collada_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_collada_check(struct coco_ctx_s *, struct coco_collada_s *);

DLL_PUBLIC void coco_collada_dump(struct coco_ctx_s *, struct coco_collada_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_COLLADA_H */

/*-------------------------------------------------------------------------*/

