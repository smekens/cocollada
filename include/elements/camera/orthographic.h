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

#ifndef __COCO_ORTHOGRAPHIC_H
#define __COCO_ORTHOGRAPHIC_H

/*-------------------------------------------------------------------------*/

typedef struct coco_orthographic_s
{
	struct coco_base_s base;

	struct coco_orthographic_s *prev, *next;

	/**/

	float xmag;
	float ymag;
	float aspect_ratio;

	float znear;
	float zfar;

} coco_orthographic_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_orthographic_s *coco_orthographic_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_orthographic_check(struct coco_ctx_s *, struct coco_orthographic_s *);

DLL_PUBLIC void coco_orthographic_dump(struct coco_ctx_s *, struct coco_orthographic_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_ORTHOGRAPHIC_H */

/*-------------------------------------------------------------------------*/

