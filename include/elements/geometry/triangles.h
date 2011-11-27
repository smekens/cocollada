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

#ifndef __COCO_TRIANGLES_H
#define __COCO_TRIANGLES_H

/*-------------------------------------------------------------------------*/

typedef struct coco_triangles_s
{
	struct coco_base_s base;

	struct coco_triangles_s *prev, *next;

	/**/

	const char *name;
	int count;
	const char *material;

	struct coco_input_s *input_list;

	struct coco_p_s *p;

	struct coco_extra_s *extra_list;

} coco_triangles_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_triangles_s *coco_triangles_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_triangles_check(struct coco_ctx_s *, struct coco_triangles_s *);

DLL_PUBLIC void coco_triangles_dump(struct coco_ctx_s *, struct coco_triangles_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_TRIANGLES_H */

/*-------------------------------------------------------------------------*/

