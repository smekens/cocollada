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

#ifndef __COCO_VERTICES_H
#define __COCO_VERTICES_H

/*-------------------------------------------------------------------------*/

typedef struct coco_vertices_input_s
{
	struct coco_base_s base;

	struct coco_vertices_input_s *prev, *next;

	/**/

	const char *semantic;
	const char *source;

} coco_vertices_input_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_vertices_s
{
	struct coco_base_s base;

	struct coco_vertices_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_vertices_input_s *input_list;

	struct coco_extra_s *extra_list;

} coco_vertices_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_vertices_input_s *coco_vertices_input_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_vertices_input_check(struct coco_ctx_s *, struct coco_vertices_input_s *);

DLL_PUBLIC void coco_vertices_input_dump(struct coco_ctx_s *, struct coco_vertices_input_s *, int);

/**/

DLL_PUBLIC struct coco_vertices_s *coco_vertices_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_vertices_check(struct coco_ctx_s *, struct coco_vertices_s *);

DLL_PUBLIC void coco_vertices_dump(struct coco_ctx_s *, struct coco_vertices_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_VERTICES_H */

/*-------------------------------------------------------------------------*/

