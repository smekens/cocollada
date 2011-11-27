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

#ifndef __COLLADA_PROFILE_COMMON_H
#define __COLLADA_PROFILE_COMMON_H

/*-------------------------------------------------------------------------*/

typedef struct collada_profile_common_technique_s
{
	struct collada_base_s base;

	struct collada_profile_common_technique_s *prev, *next;

	/**/

	const char *id;
	const char *sid;

	struct collada_asset_s *asset;

	struct collada_image_s *image_list;
	struct collada_newparam_s *newparam_list;

	/* TODO struct collada_constant_s *constant;*/
	struct collada_lambert_s *lambert;
	struct collada_phong_s *phong;
	/* TODO struct collada_blinn_s *blinn;*/

	struct collada_extra_s *extra_list;

} collada_profile_common_technique_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_profile_common_s
{
	struct collada_base_s base;

	struct collada_profile_common_s *prev, *next;

	/**/

	struct collada_image_s *image_list;
	struct collada_newparam_s *newparam_list;
	struct collada_profile_common_technique_s *technique;

	struct collada_extra_s *extra_list;

} collada_profile_common_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_profile_common_technique_s *collada_profile_common_technique_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_profile_common_technique_check(struct collada_ctx_s *, struct collada_profile_common_technique_s *);

DLL_PUBLIC void collada_profile_common_technique_dump(struct collada_ctx_s *, struct collada_profile_common_technique_s *, int);

/**/

DLL_PUBLIC struct collada_profile_common_s *collada_profile_common_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_profile_common_check(struct collada_ctx_s *, struct collada_profile_common_s *);

DLL_PUBLIC void collada_profile_common_dump(struct collada_ctx_s *, struct collada_profile_common_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_EFFECT_H */

/*-------------------------------------------------------------------------*/

