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

#ifndef __COLLADA_AMBIENT_FX_H
#define __COLLADA_AMBIENT_FX_H

/*-------------------------------------------------------------------------*/

typedef struct collada_ambient_fx_s
{
	struct collada_base_s base;

	struct collada_ambient_fx_s *prev, *next;

	/**/

	struct collada_color_s *color;
	struct collada_fx_common_param_s *param_list;
	struct collada_fx_common_texture_s *texture_list;

} collada_ambient_fx_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_ambient_fx_s *collada_ambient_fx_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_ambient_fx_check(struct collada_ctx_s *, struct collada_ambient_fx_s *);

DLL_PUBLIC void collada_ambient_fx_dump(struct collada_ctx_s *, struct collada_ambient_fx_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_AMBIENT_FX_H */

/*-------------------------------------------------------------------------*/

