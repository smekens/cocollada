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

#ifndef __COLLADA_LOOKAT_H
#define __COLLADA_LOOKAT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_lookat_s
{
	struct collada_base_s base;

	struct collada_lookat_s *prev, *next;

	/**/

	const char *sid;

	float array[9];

} collada_lookat_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_lookat_s *collada_lookat_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_lookat_check(struct collada_ctx_s *, struct collada_lookat_s *);

DLL_PUBLIC void collada_lookat_dump(struct collada_ctx_s *, struct collada_lookat_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_LOOKAT_H */

/*-------------------------------------------------------------------------*/

