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

#ifndef __COLLADA_DIRECTIONAL_H
#define __COLLADA_DIRECTIONAL_H

/*-------------------------------------------------------------------------*/

typedef struct collada_directional_s
{
	struct collada_base_s base;

	struct collada_directional_s *prev, *next;

	/**/

	struct collada_color_s *color;

} collada_directional_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_directional_s *collada_directional_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_directional_check(struct collada_ctx_s *, struct collada_directional_s *);

DLL_PUBLIC void collada_directional_dump(struct collada_ctx_s *, struct collada_directional_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_DIRECTIONAL_H */

/*-------------------------------------------------------------------------*/

