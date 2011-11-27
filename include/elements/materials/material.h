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

#ifndef __COLLADA_MATERIAL_H
#define __COLLADA_MATERIAL_H

/*-------------------------------------------------------------------------*/

typedef struct collada_material_s
{
	struct collada_base_s base;

	struct collada_material_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	struct collada_instance_effect_s *instance_effect;

	struct collada_extra_s *extra_list;

} collada_material_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_material_s *collada_material_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_material_check(struct collada_ctx_s *, struct collada_material_s *);

DLL_PUBLIC void collada_material_dump(struct collada_ctx_s *, struct collada_material_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_MATERIAL_H */

/*-------------------------------------------------------------------------*/

