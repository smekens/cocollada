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

#ifndef __COCO_PERSPECTIVE_H
#define __COCO_PERSPECTIVE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_perspective_s
{
	struct coco_base_s base;

	struct coco_perspective_s *prev, *next;

	/**/

	float xfov;
	float yfov;
	float aspect_ratio;

	float znear;
	float zfar;

} coco_perspective_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_perspective_s *coco_perspective_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_perspective_check(struct coco_ctx_s *, struct coco_perspective_s *);

DLL_PUBLIC void coco_perspective_dump(struct coco_ctx_s *, struct coco_perspective_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_PERSPECTIVE_H */

/*-------------------------------------------------------------------------*/

