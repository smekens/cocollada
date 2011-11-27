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

#ifndef __COLLADA_EFFECT_H
#define __COLLADA_EFFECT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_effect_s
{
	struct collada_base_s base;

	struct collada_effect_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	/* TODO struct collada_anotate_s *anotate_list;*/
	struct collada_image_s *image_list;
	struct collada_newparam_s *newparam_list;
	struct collada_profile_common_s *profile_common_list;
	/* TODO struct collada_profile_gles_s *profile_gles_list;*/
	/* TODO struct collada_profile_cg_s *profile_cg_list;*/
	/* TODO struct collada_profile_glsl_s *profile_glsl_list;*/

	struct collada_extra_s *extra_list;

} collada_effect_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_effect_s *collada_effect_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_effect_check(struct collada_ctx_s *, struct collada_effect_s *);

DLL_PUBLIC void collada_effect_dump(struct collada_ctx_s *, struct collada_effect_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_EFFECT_H */

/*-------------------------------------------------------------------------*/

