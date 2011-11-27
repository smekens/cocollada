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

#ifndef __COCO_VCOUNT_H
#define __COCO_VCOUNT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_vcount_s
{
	struct coco_base_s base;

	struct coco_vcount_s *prev, *next;

	/**/

	int count;

	int *array;

} coco_vcount_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_vcount_s *coco_vcount_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_vcount_check(struct coco_ctx_s *, struct coco_vcount_s *);

DLL_PUBLIC void coco_vcount_dump(struct coco_ctx_s *, struct coco_vcount_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_VCOUNT_H */

/*-------------------------------------------------------------------------*/

