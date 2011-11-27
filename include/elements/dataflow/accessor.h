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

#ifndef __COCO_ACCESSOR_H
#define __COCO_ACCESSOR_H

/*-------------------------------------------------------------------------*/

typedef struct coco_accessor_param_s
{
	struct coco_base_s base;

	struct coco_accessor_param_s *prev, *next;

	/**/

	const char *name;
	const char *sid;
	const char *semantic;
	const char *type;

} coco_accessor_param_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_accessor_s
{
	struct coco_base_s base;

	struct coco_accessor_s *prev, *next;

	/**/

	int count;
	int offset;
	const char *source;
	int stride;

	struct coco_accessor_param_s *param_list;

} coco_accessor_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_accessor_param_s *coco_accessor_param_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_accessor_param_check(struct coco_ctx_s *, struct coco_accessor_param_s *);

DLL_PUBLIC void coco_accessor_param_dump(struct coco_ctx_s *, struct coco_accessor_param_s *, int);

/**/

DLL_PUBLIC struct coco_accessor_s *coco_accessor_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_accessor_check(struct coco_ctx_s *, struct coco_accessor_s *);

DLL_PUBLIC void coco_accessor_dump(struct coco_ctx_s *, struct coco_accessor_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_ACCESSOR_H */

/*-------------------------------------------------------------------------*/

