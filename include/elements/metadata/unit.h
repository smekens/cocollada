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

#ifndef __COCO_UNIT_H
#define __COCO_UNIT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_unit_s
{
	struct coco_base_s base;

	struct coco_unit_s *prev, *next;

	/**/

	float meter;

	const char *name;

} coco_unit_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_unit_s *coco_unit_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_unit_check(struct coco_ctx_s *, struct coco_unit_s *);

DLL_PUBLIC void coco_unit_dump(struct coco_ctx_s *, struct coco_unit_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_UNIT_H */

/*-------------------------------------------------------------------------*/

