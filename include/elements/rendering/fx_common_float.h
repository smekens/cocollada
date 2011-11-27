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

#ifndef __COCO_FX_COMMON_FLOAT_H
#define __COCO_FX_COMMON_FLOAT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_fx_common_float_s
{
	struct coco_base_s base;

	struct coco_fx_common_float_s *prev, *next;

	/**/

	const char *sid;

	float value;

} coco_fx_common_float_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_fx_common_float_s *coco_fx_common_float_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_fx_common_float_check(struct coco_ctx_s *, struct coco_fx_common_float_s *);

DLL_PUBLIC void coco_fx_common_float_dump(struct coco_ctx_s *, struct coco_fx_common_float_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_FX_COMMON_FLOAT_H */

/*-------------------------------------------------------------------------*/

