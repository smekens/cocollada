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

#ifndef __COLLADA_P_H
#define __COLLADA_P_H

/*-------------------------------------------------------------------------*/

typedef struct collada_p_s
{
	struct collada_base_s base;

	struct collada_p_s *prev, *next;

	/**/

	int count;

	int *array;

} collada_p_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_p_s *collada_p_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_p_check(struct collada_ctx_s *, struct collada_p_s *);

DLL_PUBLIC void collada_p_dump(struct collada_ctx_s *, struct collada_p_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_P_H */

/*-------------------------------------------------------------------------*/

