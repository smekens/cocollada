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

#ifndef __COLLADA_SPECULAR_H
#define __COLLADA_SPECULAR_H

/*-------------------------------------------------------------------------*/

typedef struct collada_specular_s
{
	struct collada_base_s base;

	struct collada_specular_s *prev, *next;

	/**/

	struct collada_color_s *color;
	struct collada_fx_common_param_s *param_list;
	struct collada_fx_common_texture_s *texture_list;

} collada_specular_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_specular_s *collada_specular_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_specular_check(struct collada_ctx_s *, struct collada_specular_s *);

DLL_PUBLIC void collada_specular_dump(struct collada_ctx_s *, struct collada_specular_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SPECULAR_H */

/*-------------------------------------------------------------------------*/

