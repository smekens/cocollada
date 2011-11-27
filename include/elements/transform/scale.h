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

#ifndef __COLLADA_SCALE_H
#define __COLLADA_SCALE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_scale_s
{
	struct collada_base_s base;

	struct collada_scale_s *prev, *next;

	/**/

	const char *sid;

	float array[3];

} collada_scale_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_scale_s *collada_scale_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_scale_check(struct collada_ctx_s *, struct collada_scale_s *);

DLL_PUBLIC void collada_scale_dump(struct collada_ctx_s *, struct collada_scale_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SCALE_H */

/*-------------------------------------------------------------------------*/

