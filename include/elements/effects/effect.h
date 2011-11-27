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

#ifndef __COCO_EFFECT_H
#define __COCO_EFFECT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_effect_s
{
	struct coco_base_s base;

	struct coco_effect_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_asset_s *asset;

	/* TODO struct coco_anotate_s *anotate_list;*/
	struct coco_image_s *image_list;
	struct coco_newparam_s *newparam_list;
	struct coco_profile_common_s *profile_common_list;
	/* TODO struct coco_profile_gles_s *profile_gles_list;*/
	/* TODO struct coco_profile_cg_s *profile_cg_list;*/
	/* TODO struct coco_profile_glsl_s *profile_glsl_list;*/

	struct coco_extra_s *extra_list;

} coco_effect_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_effect_s *coco_effect_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_effect_check(struct coco_ctx_s *, struct coco_effect_s *);

DLL_PUBLIC void coco_effect_dump(struct coco_ctx_s *, struct coco_effect_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_EFFECT_H */

/*-------------------------------------------------------------------------*/

