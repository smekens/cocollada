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

#ifndef __COCO_INSTANCE_EFFECT_H
#define __COCO_INSTANCE_EFFECT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_instance_effect_technique_hint_s
{
	struct coco_base_s base;

	struct coco_instance_effect_s *prev, *next;

	/**/

	const char *platform;
	const char *profile;
	const char *ref;

} coco_instance_effect_technique_hint_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_instance_effect_s
{
	struct coco_base_s base;

	struct coco_instance_effect_s *prev, *next;

	/**/

	const char *url;
	const char *sid;
	const char *name;

	struct coco_instance_effect_technique_hint_s *technique_hint;

	/* TODO setparam */

	struct coco_extra_s *extra_list;

} coco_instance_effect_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_instance_effect_technique_hint_s *coco_instance_effect_technique_hint_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_instance_effect_technique_hint_check(struct coco_ctx_s *, struct coco_instance_effect_technique_hint_s *);

DLL_PUBLIC void coco_instance_effect_technique_hint_dump(struct coco_ctx_s *, struct coco_instance_effect_technique_hint_s *, int);

/**/

DLL_PUBLIC struct coco_instance_effect_s *coco_instance_effect_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_instance_effect_check(struct coco_ctx_s *, struct coco_instance_effect_s *);

DLL_PUBLIC void coco_instance_effect_dump(struct coco_ctx_s *, struct coco_instance_effect_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INSTANCE_EFFECT_H */

/*-------------------------------------------------------------------------*/

