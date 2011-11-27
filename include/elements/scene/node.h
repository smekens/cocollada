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

#ifndef __COLLADA_NODE_H
#define __COLLADA_NODE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_node_s
{
	struct collada_base_s base;

	struct collada_node_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *sid;
	const char *type;
	const char *layer;

	struct collada_asset_s *asset;

	struct collada_lookat_s *lookat_list;
	struct collada_matrix_s *matrix_list;
	struct collada_rotate_s *rotate_list;
	struct collada_scale_s *scale_list;
	/* TODO struct collada_skew_s *skew_list;*/
	struct collada_translate_s *translate_list;

	struct collada_instance_camera_s *instance_camera_list;
	/* TODO struct collada_instance_controller_s *instance_controller_list; */
	struct collada_instance_geometry_s *instance_geometry_list;
	struct collada_instance_light_s *instance_light_list;
	struct collada_instance_node_s *instance_node_list;

	struct collada_node_s *node_list;

	struct collada_extra_s *extra_list;

} collada_node_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_node_s *collada_node_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_node_check(struct collada_ctx_s *, struct collada_node_s *);

DLL_PUBLIC void collada_node_dump(struct collada_ctx_s *, struct collada_node_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_NODE_H */

/*-------------------------------------------------------------------------*/

