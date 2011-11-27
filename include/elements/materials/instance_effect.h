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

#ifndef __COLLADA_INSTANCE_EFFECT_H
#define __COLLADA_INSTANCE_EFFECT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_instance_effect_technique_hint_s
{
	struct collada_base_s base;

	struct collada_instance_effect_s *prev, *next;

	/**/

	const char *platform;
	const char *profile;
	const char *ref;

} collada_instance_effect_technique_hint_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_instance_effect_s
{
	struct collada_base_s base;

	struct collada_instance_effect_s *prev, *next;

	/**/

	const char *url;
	const char *sid;
	const char *name;

	struct collada_instance_effect_technique_hint_s *technique_hint;

	/* TODO setparam */

	struct collada_extra_s *extra_list;

} collada_instance_effect_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_instance_effect_technique_hint_s *collada_instance_effect_technique_hint_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_instance_effect_technique_hint_check(struct collada_ctx_s *, struct collada_instance_effect_technique_hint_s *);

DLL_PUBLIC void collada_instance_effect_technique_hint_dump(struct collada_ctx_s *, struct collada_instance_effect_technique_hint_s *, int);

/**/

DLL_PUBLIC struct collada_instance_effect_s *collada_instance_effect_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_instance_effect_check(struct collada_ctx_s *, struct collada_instance_effect_s *);

DLL_PUBLIC void collada_instance_effect_dump(struct collada_ctx_s *, struct collada_instance_effect_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_INSTANCE_EFFECT_H */

/*-------------------------------------------------------------------------*/

