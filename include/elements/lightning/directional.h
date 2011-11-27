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

#ifndef __COCO_DIRECTIONAL_H
#define __COCO_DIRECTIONAL_H

/*-------------------------------------------------------------------------*/

typedef struct coco_directional_s
{
	struct coco_base_s base;

	struct coco_directional_s *prev, *next;

	/**/

	struct coco_color_s *color;

} coco_directional_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_directional_s *coco_directional_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_directional_check(struct coco_ctx_s *, struct coco_directional_s *);

DLL_PUBLIC void coco_directional_dump(struct coco_ctx_s *, struct coco_directional_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_DIRECTIONAL_H */

/*-------------------------------------------------------------------------*/

