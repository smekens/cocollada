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

#ifndef __COCO_TRANSPARENCY_H
#define __COCO_TRANSPARENCY_H

/*-------------------------------------------------------------------------*/

typedef struct coco_transparency_s
{
	struct coco_base_s base;

	struct coco_transparency_s *prev, *next;

	/**/

	struct coco_fx_common_float_s *flt;
	struct coco_fx_common_param_s *param_list;

} coco_transparency_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_transparency_s *coco_transparency_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_transparency_check(struct coco_ctx_s *, struct coco_transparency_s *);

DLL_PUBLIC void coco_transparency_dump(struct coco_ctx_s *, struct coco_transparency_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_TRANSPARENCY_H */

/*-------------------------------------------------------------------------*/

