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

#ifndef __COCO_SCALE_H
#define __COCO_SCALE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_scale_s
{
	struct coco_base_s base;

	struct coco_scale_s *prev, *next;

	/**/

	const char *sid;

	float array[3];

} coco_scale_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_scale_s *coco_scale_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_scale_check(struct coco_ctx_s *, struct coco_scale_s *);

DLL_PUBLIC void coco_scale_dump(struct coco_ctx_s *, struct coco_scale_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SCALE_H */

/*-------------------------------------------------------------------------*/

