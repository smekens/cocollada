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

#ifndef __COCO_EXTRA_H
#define __COCO_EXTRA_H

/*-------------------------------------------------------------------------*/

typedef struct coco_extra_s
{
	struct coco_base_s base;

	struct coco_extra_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *type;

	struct coco_asset_s *asset;

	struct coco_technique_core_s *technique_list;

} coco_extra_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_extra_s *coco_extra_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_extra_check(struct coco_ctx_s *, struct coco_extra_s *);

DLL_PUBLIC void coco_extra_dump(struct coco_ctx_s *, struct coco_extra_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_EXTRA_H */

/*-------------------------------------------------------------------------*/

