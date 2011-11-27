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

#ifndef __COCO_INSTANCE_VISUAL_SCENE_H
#define __COCO_INSTANCE_VISUAL_SCENE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_instance_visual_scene_s
{
	struct coco_base_s base;

	struct coco_instance_visual_scene_s *prev, *next;

	/**/

	const char *url;
	const char *sid;
	const char *name;

	struct coco_extra_s *extra_list;

} coco_instance_visual_scene_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_instance_visual_scene_s *coco_instance_visual_scene_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_instance_visual_scene_check(struct coco_ctx_s *, struct coco_instance_visual_scene_s *);

DLL_PUBLIC void coco_instance_visual_scene_dump(struct coco_ctx_s *, struct coco_instance_visual_scene_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INSTANCE_VISUAL_SCENE_H */

/*-------------------------------------------------------------------------*/

