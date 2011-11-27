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

#ifndef __COLLADA_UNIT_H
#define __COLLADA_UNIT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_unit_s
{
	struct collada_base_s base;

	struct collada_unit_s *prev, *next;

	/**/

	float meter;

	const char *name;

} collada_unit_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_unit_s *collada_unit_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_unit_check(struct collada_ctx_s *, struct collada_unit_s *);

DLL_PUBLIC void collada_unit_dump(struct collada_ctx_s *, struct collada_unit_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_UNIT_H */

/*-------------------------------------------------------------------------*/

