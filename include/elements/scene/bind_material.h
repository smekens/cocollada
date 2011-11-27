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

#ifndef __COLLADA_BIND_MATERIAL_H
#define __COLLADA_BIND_MATERIAL_H

/*-------------------------------------------------------------------------*/

typedef struct collada_bind_material_param_s
{
	struct collada_base_s base;

	struct collada_bind_material_param_s *prev, *next;

	/**/

	const char *name;
	const char *sid;
	const char *semantic;
	const char *type;

} collada_bind_material_param_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_bind_material_technique_common_s
{
	struct collada_base_s base;

	struct collada_bind_material_technique_common_s *prev, *next;

	/**/

	struct collada_instance_material_s *instance_material_list;

} collada_bind_material_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_bind_material_s
{
	struct collada_base_s base;

	struct collada_bind_material_s *prev, *next;

	/**/

	struct collada_bind_material_param_s *param_list;

	struct collada_bind_material_technique_common_s *technique_common;
	
	struct collada_technique_core_s *technique_list;

	struct collada_extra_s *extra_list;

} collada_bind_material_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_bind_material_param_s *collada_bind_material_param_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_bind_material_param_check(struct collada_ctx_s *, struct collada_bind_material_param_s *);

DLL_PUBLIC void collada_bind_material_param_dump(struct collada_ctx_s *, struct collada_bind_material_param_s *, int);

/**/

DLL_PUBLIC struct collada_bind_material_technique_common_s *collada_bind_material_technique_common_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_bind_material_technique_common_check(struct collada_ctx_s *, struct collada_bind_material_technique_common_s *);

DLL_PUBLIC void collada_bind_material_technique_common_dump(struct collada_ctx_s *, struct collada_bind_material_technique_common_s *, int);

/**/

DLL_PUBLIC struct collada_bind_material_s *collada_bind_material_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_bind_material_check(struct collada_ctx_s *, struct collada_bind_material_s *);

DLL_PUBLIC void collada_bind_material_dump(struct collada_ctx_s *, struct collada_bind_material_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_BIND_MATERIAL_H */

/*-------------------------------------------------------------------------*/

