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

#ifndef __COLLADA_INDEX_OF_REFRACTION_H
#define __COLLADA_INDEX_OF_REFRACTION_H

/*-------------------------------------------------------------------------*/

typedef struct collada_index_of_refraction_s
{
	struct collada_base_s base;

	struct collada_index_of_refraction_s *prev, *next;

	/**/

	struct collada_fx_common_float_s *flt;
	struct collada_fx_common_param_s *param_list;

} collada_index_of_refraction_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_index_of_refraction_s *collada_index_of_refraction_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_index_of_refraction_check(struct collada_ctx_s *, struct collada_index_of_refraction_s *);

DLL_PUBLIC void collada_index_of_refraction_dump(struct collada_ctx_s *, struct collada_index_of_refraction_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_INDEX_OF_REFRACTION_H */

/*-------------------------------------------------------------------------*/

