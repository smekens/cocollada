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

#ifndef __COCO_INDEX_OF_REFRACTION_H
#define __COCO_INDEX_OF_REFRACTION_H

/*-------------------------------------------------------------------------*/

typedef struct coco_index_of_refraction_s
{
	struct coco_base_s base;

	struct coco_index_of_refraction_s *prev, *next;

	/**/

	struct coco_fx_common_float_s *flt;
	struct coco_fx_common_param_s *param_list;

} coco_index_of_refraction_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_index_of_refraction_s *coco_index_of_refraction_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_index_of_refraction_check(struct coco_ctx_s *, struct coco_index_of_refraction_s *);

DLL_PUBLIC void coco_index_of_refraction_dump(struct coco_ctx_s *, struct coco_index_of_refraction_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INDEX_OF_REFRACTION_H */

/*-------------------------------------------------------------------------*/

