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

#ifndef __COCO_POINT_H
#define __COCO_POINT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_point_s
{
	struct coco_base_s base;

	struct coco_point_s *prev, *next;

	/**/

	struct coco_color_s *color;

	float constant_attenuation;
	float linear_attenuation;
	float quadratic_attenuation;

} coco_point_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_point_s *coco_point_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_point_check(struct coco_ctx_s *, struct coco_point_s *);

DLL_PUBLIC void coco_point_dump(struct coco_ctx_s *, struct coco_point_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_POINT_H */

/*-------------------------------------------------------------------------*/

