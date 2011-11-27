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

#ifndef __COLLADA_FX_COMMON_PARAM_H
#define __COLLADA_FX_COMMON_PARAM_H

/*-------------------------------------------------------------------------*/

typedef struct collada_fx_common_param_s
{
	struct collada_base_s base;

	struct collada_fx_common_param_s *prev, *next;

	/**/

	const char *ref;

} collada_fx_common_param_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_fx_common_param_s *collada_fx_common_param_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_fx_common_param_check(struct collada_ctx_s *, struct collada_fx_common_param_s *);

DLL_PUBLIC void collada_fx_common_param_dump(struct collada_ctx_s *, struct collada_fx_common_param_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_FX_COMMON_PARAM_H */

/*-------------------------------------------------------------------------*/

