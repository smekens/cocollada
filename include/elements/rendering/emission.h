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

#ifndef __COLLADA_EMISSION_H
#define __COLLADA_EMISSION_H

/*-------------------------------------------------------------------------*/

typedef struct collada_emission_s
{
	struct collada_base_s base;

	struct collada_emission_s *prev, *next;

	/**/

	struct collada_color_s *color;
	struct collada_fx_common_param_s *param_list;
	struct collada_fx_common_texture_s *texture_list;

} collada_emission_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_emission_s *collada_emission_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_emission_check(struct collada_ctx_s *, struct collada_emission_s *);

DLL_PUBLIC void collada_emission_dump(struct collada_ctx_s *, struct collada_emission_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_EMISSION_H */

/*-------------------------------------------------------------------------*/

