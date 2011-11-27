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

#ifndef __COLLADA_MATRIX_H
#define __COLLADA_MATRIX_H

/*-------------------------------------------------------------------------*/

typedef struct collada_matrix_s
{
	struct collada_base_s base;

	struct collada_matrix_s *prev, *next;

	/**/

	const char *sid;

	float array[16];

} collada_matrix_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_matrix_s *collada_matrix_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_matrix_check(struct collada_ctx_s *, struct collada_matrix_s *);

DLL_PUBLIC void collada_matrix_dump(struct collada_ctx_s *, struct collada_matrix_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_MATRIX_H */

/*-------------------------------------------------------------------------*/

