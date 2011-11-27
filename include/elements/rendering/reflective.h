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

#ifndef __COLLADA_REFLECTIVE_H
#define __COLLADA_REFLECTIVE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_reflective_s
{
	struct collada_base_s base;

	struct collada_reflective_s *prev, *next;

	/**/

	struct collada_color_s *color;
	struct collada_fx_common_param_s *param_list;
	struct collada_fx_common_texture_s *texture_list;

} collada_reflective_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_reflective_s *collada_reflective_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_reflective_check(struct collada_ctx_s *, struct collada_reflective_s *);

DLL_PUBLIC void collada_reflective_dump(struct collada_ctx_s *, struct collada_reflective_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_REFLECTIVE_H */

/*-------------------------------------------------------------------------*/

