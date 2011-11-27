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

#ifndef __COLLADA_BIND_VERTEX_INPUT_H
#define __COLLADA_BIND_VERTEX_INPUT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_bind_vertex_input_s
{
	struct collada_base_s base;

	struct collada_bind_vertex_input_s *prev, *next;

	/**/

	const char *semantic;
	const char *input_semantic;
	const char *input_set;

} collada_bind_vertex_input_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_bind_vertex_input_s *collada_bind_vertex_input_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_bind_vertex_input_check(struct collada_ctx_s *, struct collada_bind_vertex_input_s *);

DLL_PUBLIC void collada_bind_vertex_input_dump(struct collada_ctx_s *, struct collada_bind_vertex_input_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_BIND_VERTEX_INPUT_H */

/*-------------------------------------------------------------------------*/

