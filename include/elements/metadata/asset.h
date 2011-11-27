/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of COLLADA.
 *
 */

/*-------------------------------------------------------------------------*/

#ifndef __COLLADA_ASSET_H
#define __COLLADA_ASSET_H

/*-------------------------------------------------------------------------*/

typedef struct collada_asset_contributor_s
{
	struct collada_base_s base;

	struct collada_asset_contributor_s *prev, *next;

	/**/

	const char *author;
	const char *authoring_tool;
	const char *comments;
	const char *copyright;
	const char *source_data;

} collada_asset_contributor_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_asset_s
{
	struct collada_base_s base;

	struct collada_asset_s *prev, *next;

	/**/

	struct collada_asset_contributor_s *contributor_list;

	const char *created;
	const char *keywords;
	const char *modified;
	const char *revision;
	const char *subject;
	const char *title;

	struct collada_unit_s *unit;

	const char *up_axis;

} collada_asset_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_asset_contributor_s *collada_asset_contributor_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_asset_contributor_check(struct collada_ctx_s *, struct collada_asset_contributor_s *);

DLL_PUBLIC void collada_asset_contributor_dump(struct collada_ctx_s *, struct collada_asset_contributor_s *, int);

/**/

DLL_PUBLIC struct collada_asset_s *collada_asset_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_asset_check(struct collada_ctx_s *, struct collada_asset_s *);

DLL_PUBLIC void collada_asset_dump(struct collada_ctx_s *, struct collada_asset_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_ASSET_H */

/*-------------------------------------------------------------------------*/

