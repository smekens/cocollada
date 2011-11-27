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

#ifndef __COLLADA_REFLECTIVITY_H
#define __COLLADA_REFLECTIVITY_H

/*-------------------------------------------------------------------------*/

typedef struct collada_reflectivity_s
{
	struct collada_base_s base;

	struct collada_reflectivity_s *prev, *next;

	/**/

	struct collada_fx_common_float_s *flt;
	struct collada_fx_common_param_s *param_list;

} collada_reflectivity_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_reflectivity_s *collada_reflectivity_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_reflectivity_check(struct collada_ctx_s *, struct collada_reflectivity_s *);

DLL_PUBLIC void collada_reflectivity_dump(struct collada_ctx_s *, struct collada_reflectivity_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_REFLECTIVITY_H */

/*-------------------------------------------------------------------------*/

