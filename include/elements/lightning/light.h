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

#ifndef __COLLADA_LIGHT_H
#define __COLLADA_LIGHT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_light_technique_common_s
{
	struct collada_base_s base;

	struct collada_light_technique_common_s *prev, *next;

	/**/

	struct collada_ambient_core_s *ambient;
	struct collada_directional_s *directional;
	struct collada_point_s *point;
	struct collada_spot_s *spot;

} collada_light_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_light_s
{
	struct collada_base_s base;

	struct collada_light_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	struct collada_light_technique_common_s *technique_common;
	struct collada_technique_core_s *technique_list;

	struct collada_extra_s *extra_list;

} collada_light_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_light_technique_common_s *collada_light_technique_common_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_light_technique_common_check(struct collada_ctx_s *, struct collada_light_technique_common_s *);

DLL_PUBLIC void collada_light_technique_common_dump(struct collada_ctx_s *, struct collada_light_technique_common_s *, int);

/**/

DLL_PUBLIC struct collada_light_s *collada_light_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_light_check(struct collada_ctx_s *, struct collada_light_s *);

DLL_PUBLIC void collada_light_dump(struct collada_ctx_s *, struct collada_light_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_LIGHT_H */

/*-------------------------------------------------------------------------*/

