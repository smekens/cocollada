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

#ifndef __COCO_ROTATE_H
#define __COCO_ROTATE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_rotate_s
{
	struct coco_base_s base;

	struct coco_rotate_s *prev, *next;

	/**/

	const char *sid;

	float array[4];

} coco_rotate_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_rotate_s *coco_rotate_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_rotate_check(struct coco_ctx_s *, struct coco_rotate_s *);

DLL_PUBLIC void coco_rotate_dump(struct coco_ctx_s *, struct coco_rotate_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_ROTATE_H */

/*-------------------------------------------------------------------------*/

