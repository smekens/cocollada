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

#ifndef __COLLADA_EXTRA_H
#define __COLLADA_EXTRA_H

/*-------------------------------------------------------------------------*/

typedef struct collada_extra_s
{
	struct collada_base_s base;

	struct collada_extra_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *type;

	struct collada_asset_s *asset;

	struct collada_technique_core_s *technique_list;

} collada_extra_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_extra_s *collada_extra_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_extra_check(struct collada_ctx_s *, struct collada_extra_s *);

DLL_PUBLIC void collada_extra_dump(struct collada_ctx_s *, struct collada_extra_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_EXTRA_H */

/*-------------------------------------------------------------------------*/

