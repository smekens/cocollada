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

#ifndef __COCO_FLOAT_ARRAY_H
#define __COCO_FLOAT_ARRAY_H

/*-------------------------------------------------------------------------*/

typedef struct coco_float_array_s
{
	struct coco_base_s base;

	struct coco_float_array_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	int count;
	int digits;
	int magnitude;

	float *array;

} coco_float_array_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_float_array_s *coco_float_array_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_float_array_check(struct coco_ctx_s *, struct coco_float_array_s *);

DLL_PUBLIC void coco_float_array_dump(struct coco_ctx_s *, struct coco_float_array_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_FLOAT_ARRAY_H */

/*-------------------------------------------------------------------------*/

