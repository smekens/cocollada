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

#ifndef __COCO_AMBIENT_CORE_H
#define __COCO_AMBIENT_CORE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_ambient_core_s
{
	struct coco_base_s base;

	struct coco_ambient_core_s *prev, *next;

	/**/

	struct coco_color_s *color;

} coco_ambient_core_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_ambient_core_s *coco_ambient_core_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_ambient_core_check(struct coco_ctx_s *, struct coco_ambient_core_s *);

DLL_PUBLIC void coco_ambient_core_dump(struct coco_ctx_s *, struct coco_ambient_core_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_AMBIENT_CORE_H */

/*-------------------------------------------------------------------------*/

