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

#ifndef __COLLADA_OPTICS_H
#define __COLLADA_OPTICS_H

/*-------------------------------------------------------------------------*/

typedef struct collada_optics_technique_common_s
{
	struct collada_base_s base;

	struct collada_optics_technique_common_s *prev, *next;

	/**/

	struct collada_orthographic_s *orthographic;
	struct collada_perspective_s *perspective;

} collada_optics_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_optics_s
{
	struct collada_base_s base;

	struct collada_optics_s *prev, *next;

	/**/

	struct collada_optics_technique_common_s *technique_common;
	struct collada_technique_core_s *technique_list;

	struct collada_extra_s *extra_list;

} collada_optics_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_optics_technique_common_s *collada_optics_technique_common_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_optics_technique_common_check(struct collada_ctx_s *, struct collada_optics_technique_common_s *);

DLL_PUBLIC void collada_optics_technique_common_dump(struct collada_ctx_s *, struct collada_optics_technique_common_s *, int);

/**/

DLL_PUBLIC struct collada_optics_s *collada_optics_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_optics_check(struct collada_ctx_s *, struct collada_optics_s *);

DLL_PUBLIC void collada_optics_dump(struct collada_ctx_s *, struct collada_optics_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_OPTICS_H */

/*-------------------------------------------------------------------------*/

