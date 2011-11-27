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

#ifndef __COCO_BIND_VERTEX_INPUT_H
#define __COCO_BIND_VERTEX_INPUT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_bind_vertex_input_s
{
	struct coco_base_s base;

	struct coco_bind_vertex_input_s *prev, *next;

	/**/

	const char *semantic;
	const char *input_semantic;
	const char *input_set;

} coco_bind_vertex_input_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_bind_vertex_input_s *coco_bind_vertex_input_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_bind_vertex_input_check(struct coco_ctx_s *, struct coco_bind_vertex_input_s *);

DLL_PUBLIC void coco_bind_vertex_input_dump(struct coco_ctx_s *, struct coco_bind_vertex_input_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_BIND_VERTEX_INPUT_H */

/*-------------------------------------------------------------------------*/

