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

#ifndef __COLLADA_FLOAT_ARRAY_H
#define __COLLADA_FLOAT_ARRAY_H

/*-------------------------------------------------------------------------*/

typedef struct collada_float_array_s
{
	struct collada_base_s base;

	struct collada_float_array_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	int count;
	int digits;
	int magnitude;

	float *array;

} collada_float_array_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_float_array_s *collada_float_array_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_float_array_check(struct collada_ctx_s *, struct collada_float_array_s *);

DLL_PUBLIC void collada_float_array_dump(struct collada_ctx_s *, struct collada_float_array_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_FLOAT_ARRAY_H */

/*-------------------------------------------------------------------------*/

