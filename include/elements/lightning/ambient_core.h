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

#ifndef __COLLADA_AMBIENT_CORE_H
#define __COLLADA_AMBIENT_CORE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_ambient_core_s
{
	struct collada_base_s base;

	struct collada_ambient_core_s *prev, *next;

	/**/

	struct collada_color_s *color;

} collada_ambient_core_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_ambient_core_s *collada_ambient_core_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_ambient_core_check(struct collada_ctx_s *, struct collada_ambient_core_s *);

DLL_PUBLIC void collada_ambient_core_dump(struct collada_ctx_s *, struct collada_ambient_core_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_AMBIENT_CORE_H */

/*-------------------------------------------------------------------------*/

