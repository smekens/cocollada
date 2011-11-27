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

#ifndef __COLLADA_TRANSPARENCY_H
#define __COLLADA_TRANSPARENCY_H

/*-------------------------------------------------------------------------*/

typedef struct collada_transparency_s
{
	struct collada_base_s base;

	struct collada_transparency_s *prev, *next;

	/**/

	struct collada_fx_common_float_s *flt;
	struct collada_fx_common_param_s *param_list;

} collada_transparency_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_transparency_s *collada_transparency_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_transparency_check(struct collada_ctx_s *, struct collada_transparency_s *);

DLL_PUBLIC void collada_transparency_dump(struct collada_ctx_s *, struct collada_transparency_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_TRANSPARENCY_H */

/*-------------------------------------------------------------------------*/

