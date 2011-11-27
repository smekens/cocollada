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

#ifndef __COCO_LIBRARY_NODES_H
#define __COCO_LIBRARY_NODES_H

/*-------------------------------------------------------------------------*/

typedef struct coco_library_nodes_s
{
	struct coco_base_s base;

	struct coco_library_nodes_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_asset_s *asset;

	struct coco_node_s *node_list;

	struct coco_extra_s *extra_list;

} coco_library_nodes_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_library_nodes_s *coco_library_nodes_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_library_nodes_check(struct coco_ctx_s *, struct coco_library_nodes_s *);

DLL_PUBLIC void coco_library_nodes_dump(struct coco_ctx_s *, struct coco_library_nodes_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_LIBRARY_NODES_H */

/*-------------------------------------------------------------------------*/

