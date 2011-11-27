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

#ifndef __COCO_LOOKAT_H
#define __COCO_LOOKAT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_lookat_s
{
	struct coco_base_s base;

	struct coco_lookat_s *prev, *next;

	/**/

	const char *sid;

	float array[9];

} coco_lookat_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_lookat_s *coco_lookat_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_lookat_check(struct coco_ctx_s *, struct coco_lookat_s *);

DLL_PUBLIC void coco_lookat_dump(struct coco_ctx_s *, struct coco_lookat_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_LOOKAT_H */

/*-------------------------------------------------------------------------*/

