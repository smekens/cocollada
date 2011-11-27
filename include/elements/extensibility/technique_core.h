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

#ifndef __COCO_TECHNIQUE_CORE_H
#define __COCO_TECHNIQUE_CORE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_technique_core_s
{
	struct coco_base_s base;

	struct coco_technique_core_s *prev, *next;

	/**/

	const char *profile;

} coco_technique_core_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_technique_core_s *coco_technique_core_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_technique_core_check(struct coco_ctx_s *, struct coco_technique_core_s *);

DLL_PUBLIC void coco_technique_core_dump(struct coco_ctx_s *, struct coco_technique_core_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_TECHNIQUE_CORE_H */

/*-------------------------------------------------------------------------*/

