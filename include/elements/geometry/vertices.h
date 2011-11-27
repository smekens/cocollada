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

#ifndef __COLLADA_VERTICES_H
#define __COLLADA_VERTICES_H

/*-------------------------------------------------------------------------*/

typedef struct collada_vertices_input_s
{
	struct collada_base_s base;

	struct collada_vertices_input_s *prev, *next;

	/**/

	const char *semantic;
	const char *source;

} collada_vertices_input_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_vertices_s
{
	struct collada_base_s base;

	struct collada_vertices_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_vertices_input_s *input_list;

	struct collada_extra_s *extra_list;

} collada_vertices_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_vertices_input_s *collada_vertices_input_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_vertices_input_check(struct collada_ctx_s *, struct collada_vertices_input_s *);

DLL_PUBLIC void collada_vertices_input_dump(struct collada_ctx_s *, struct collada_vertices_input_s *, int);

/**/

DLL_PUBLIC struct collada_vertices_s *collada_vertices_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_vertices_check(struct collada_ctx_s *, struct collada_vertices_s *);

DLL_PUBLIC void collada_vertices_dump(struct collada_ctx_s *, struct collada_vertices_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_VERTICES_H */

/*-------------------------------------------------------------------------*/

