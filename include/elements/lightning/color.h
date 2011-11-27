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

#ifndef __COCO_COLOR_H
#define __COCO_COLOR_H

/*-------------------------------------------------------------------------*/

typedef struct coco_color_s
{
	struct coco_base_s base;

	struct coco_color_s *prev, *next;

	/**/

	const char *sid;

	float r;
	float g;
	float b;
	float a;

} coco_color_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_color_s *coco_color_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_color_check(struct coco_ctx_s *, struct coco_color_s *);

DLL_PUBLIC void coco_color_dump(struct coco_ctx_s *, struct coco_color_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_COLOR_H */

/*-------------------------------------------------------------------------*/

