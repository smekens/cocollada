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

#ifndef __COLLADA_TRIANGLES_H
#define __COLLADA_TRIANGLES_H

/*-------------------------------------------------------------------------*/

typedef struct collada_triangles_s
{
	struct collada_base_s base;

	struct collada_triangles_s *prev, *next;

	/**/

	const char *name;
	int count;
	const char *material;

	struct collada_input_s *input_list;

	struct collada_p_s *p;

	struct collada_extra_s *extra_list;

} collada_triangles_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_triangles_s *collada_triangles_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_triangles_check(struct collada_ctx_s *, struct collada_triangles_s *);

DLL_PUBLIC void collada_triangles_dump(struct collada_ctx_s *, struct collada_triangles_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_TRIANGLES_H */

/*-------------------------------------------------------------------------*/

