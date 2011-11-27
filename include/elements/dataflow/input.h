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

#ifndef __COCO_INPUT_H
#define __COCO_INPUT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_input_s
{
	struct coco_base_s base;

	struct coco_input_s *prev, *next;

	/**/

	int offset;
	const char *semantic;
	const char *source;
	int set;

} coco_input_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_input_s *coco_input_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_input_check(struct coco_ctx_s *, struct coco_input_s *);

DLL_PUBLIC void coco_input_dump(struct coco_ctx_s *, struct coco_input_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INPUT_H */

/*-------------------------------------------------------------------------*/

