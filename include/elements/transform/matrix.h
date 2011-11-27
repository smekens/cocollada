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

#ifndef __COCO_MATRIX_H
#define __COCO_MATRIX_H

/*-------------------------------------------------------------------------*/

typedef struct coco_matrix_s
{
	struct coco_base_s base;

	struct coco_matrix_s *prev, *next;

	/**/

	const char *sid;

	float array[16];

} coco_matrix_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_matrix_s *coco_matrix_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_matrix_check(struct coco_ctx_s *, struct coco_matrix_s *);

DLL_PUBLIC void coco_matrix_dump(struct coco_ctx_s *, struct coco_matrix_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_MATRIX_H */

/*-------------------------------------------------------------------------*/

