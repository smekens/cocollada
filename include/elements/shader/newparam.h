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

#ifndef __COCO_NEWPARAM_H
#define __COCO_NEWPARAM_H

/*-------------------------------------------------------------------------*/

typedef struct coco_newparam_s
{
	struct coco_base_s base;

	struct coco_newparam_s *prev, *next;

	/**/

	const char *sid;

	/* TODO struct coco_annotate_s *annotate_list;*/
	/* TODO struct coco_semantic_s *semantic;*/
	/* TODO struct coco_modifier_s *modifier;*/

	struct coco_surface_s *surface;
	struct coco_sampler2D_s *sampler2D;

} coco_newparam_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_newparam_s *coco_newparam_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_newparam_check(struct coco_ctx_s *, struct coco_newparam_s *);

DLL_PUBLIC void coco_newparam_dump(struct coco_ctx_s *, struct coco_newparam_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_NEWPARAM_H */

/*-------------------------------------------------------------------------*/

