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

#ifndef __COCO_SHININESS_H
#define __COCO_SHININESS_H

/*-------------------------------------------------------------------------*/

typedef struct coco_shininess_s
{
	struct coco_base_s base;

	struct coco_shininess_s *prev, *next;

	/**/

	struct coco_fx_common_float_s *flt;
	struct coco_fx_common_param_s *param_list;

} coco_shininess_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_shininess_s *coco_shininess_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_shininess_check(struct coco_ctx_s *, struct coco_shininess_s *);

DLL_PUBLIC void coco_shininess_dump(struct coco_ctx_s *, struct coco_shininess_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SHININESS_H */

/*-------------------------------------------------------------------------*/

