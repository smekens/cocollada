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

#ifndef __COCO_P_H
#define __COCO_P_H

/*-------------------------------------------------------------------------*/

typedef struct coco_p_s
{
	struct coco_base_s base;

	struct coco_p_s *prev, *next;

	/**/

	int count;

	int *array;

} coco_p_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_p_s *coco_p_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_p_check(struct coco_ctx_s *, struct coco_p_s *);

DLL_PUBLIC void coco_p_dump(struct coco_ctx_s *, struct coco_p_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_P_H */

/*-------------------------------------------------------------------------*/

