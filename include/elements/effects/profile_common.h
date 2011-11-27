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

#ifndef __COCO_PROFILE_COMMON_H
#define __COCO_PROFILE_COMMON_H

/*-------------------------------------------------------------------------*/

typedef struct coco_profile_common_technique_s
{
	struct coco_base_s base;

	struct coco_profile_common_technique_s *prev, *next;

	/**/

	const char *id;
	const char *sid;

	struct coco_asset_s *asset;

	struct coco_image_s *image_list;
	struct coco_newparam_s *newparam_list;

	/* TODO struct coco_constant_s *constant;*/
	struct coco_lambert_s *lambert;
	struct coco_phong_s *phong;
	/* TODO struct coco_blinn_s *blinn;*/

	struct coco_extra_s *extra_list;

} coco_profile_common_technique_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_profile_common_s
{
	struct coco_base_s base;

	struct coco_profile_common_s *prev, *next;

	/**/

	struct coco_image_s *image_list;
	struct coco_newparam_s *newparam_list;
	struct coco_profile_common_technique_s *technique;

	struct coco_extra_s *extra_list;

} coco_profile_common_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_profile_common_technique_s *coco_profile_common_technique_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_profile_common_technique_check(struct coco_ctx_s *, struct coco_profile_common_technique_s *);

DLL_PUBLIC void coco_profile_common_technique_dump(struct coco_ctx_s *, struct coco_profile_common_technique_s *, int);

/**/

DLL_PUBLIC struct coco_profile_common_s *coco_profile_common_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_profile_common_check(struct coco_ctx_s *, struct coco_profile_common_s *);

DLL_PUBLIC void coco_profile_common_dump(struct coco_ctx_s *, struct coco_profile_common_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_EFFECT_H */

/*-------------------------------------------------------------------------*/

