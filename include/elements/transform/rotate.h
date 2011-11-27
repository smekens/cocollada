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

#ifndef __COLLADA_ROTATE_H
#define __COLLADA_ROTATE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_rotate_s
{
	struct collada_base_s base;

	struct collada_rotate_s *prev, *next;

	/**/

	const char *sid;

	float array[4];

} collada_rotate_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_rotate_s *collada_rotate_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_rotate_check(struct collada_ctx_s *, struct collada_rotate_s *);

DLL_PUBLIC void collada_rotate_dump(struct collada_ctx_s *, struct collada_rotate_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_ROTATE_H */

/*-------------------------------------------------------------------------*/

