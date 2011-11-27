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

#ifndef __COCO_SPOT_H
#define __COCO_SPOT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_spot_s
{
	struct coco_base_s base;

	struct coco_spot_s *prev, *next;

	/**/

	struct coco_color_s *color;

	float constant_attenuation;
	float linear_attenuation;
	float quadratic_attenuation;

	float falloff_angle;
	float falloff_exponent;

} coco_spot_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_spot_s *coco_spot_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_spot_check(struct coco_ctx_s *, struct coco_spot_s *);

DLL_PUBLIC void coco_spot_dump(struct coco_ctx_s *, struct coco_spot_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SPOT_H */

/*-------------------------------------------------------------------------*/

