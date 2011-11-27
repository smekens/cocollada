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

#ifndef __COLLADA_SHININESS_H
#define __COLLADA_SHININESS_H

/*-------------------------------------------------------------------------*/

typedef struct collada_shininess_s
{
	struct collada_base_s base;

	struct collada_shininess_s *prev, *next;

	/**/

	struct collada_fx_common_float_s *flt;
	struct collada_fx_common_param_s *param_list;

} collada_shininess_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_shininess_s *collada_shininess_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_shininess_check(struct collada_ctx_s *, struct collada_shininess_s *);

DLL_PUBLIC void collada_shininess_dump(struct collada_ctx_s *, struct collada_shininess_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SHININESS_H */

/*-------------------------------------------------------------------------*/

