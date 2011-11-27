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

#ifndef __COCO_NODE_H
#define __COCO_NODE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_node_s
{
	struct coco_base_s base;

	struct coco_node_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *sid;
	const char *type;
	const char *layer;

	struct coco_asset_s *asset;

	struct coco_lookat_s *lookat_list;
	struct coco_matrix_s *matrix_list;
	struct coco_rotate_s *rotate_list;
	struct coco_scale_s *scale_list;
	/* TODO struct coco_skew_s *skew_list;*/
	struct coco_translate_s *translate_list;

	struct coco_instance_camera_s *instance_camera_list;
	/* TODO struct coco_instance_controller_s *instance_controller_list; */
	struct coco_instance_geometry_s *instance_geometry_list;
	struct coco_instance_light_s *instance_light_list;
	struct coco_instance_node_s *instance_node_list;

	struct coco_node_s *node_list;

	struct coco_extra_s *extra_list;

} coco_node_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_node_s *coco_node_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_node_check(struct coco_ctx_s *, struct coco_node_s *);

DLL_PUBLIC void coco_node_dump(struct coco_ctx_s *, struct coco_node_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_NODE_H */

/*-------------------------------------------------------------------------*/

