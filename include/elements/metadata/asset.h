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

#ifndef __COCO_ASSET_H
#define __COCO_ASSET_H

/*-------------------------------------------------------------------------*/

typedef struct coco_asset_contributor_s
{
	struct coco_base_s base;

	struct coco_asset_contributor_s *prev, *next;

	/**/

	const char *author;
	const char *authoring_tool;
	const char *comments;
	const char *copyright;
	const char *source_data;

} coco_asset_contributor_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_asset_s
{
	struct coco_base_s base;

	struct coco_asset_s *prev, *next;

	/**/

	struct coco_asset_contributor_s *contributor_list;

	const char *created;
	const char *keywords;
	const char *modified;
	const char *revision;
	const char *subject;
	const char *title;

	struct coco_unit_s *unit;

	const char *up_axis;

} coco_asset_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_asset_contributor_s *coco_asset_contributor_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_asset_contributor_check(struct coco_ctx_s *, struct coco_asset_contributor_s *);

DLL_PUBLIC void coco_asset_contributor_dump(struct coco_ctx_s *, struct coco_asset_contributor_s *, int);

/**/

DLL_PUBLIC struct coco_asset_s *coco_asset_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_asset_check(struct coco_ctx_s *, struct coco_asset_s *);

DLL_PUBLIC void coco_asset_dump(struct coco_ctx_s *, struct coco_asset_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_ASSET_H */

/*-------------------------------------------------------------------------*/

