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

#ifndef __COLLADA_NEWPARAM_H
#define __COLLADA_NEWPARAM_H

/*-------------------------------------------------------------------------*/

typedef struct collada_newparam_s
{
	struct collada_base_s base;

	struct collada_newparam_s *prev, *next;

	/**/

	const char *sid;

	/* TODO struct collada_annotate_s *annotate_list;*/
	/* TODO struct collada_semantic_s *semantic;*/
	/* TODO struct collada_modifier_s *modifier;*/

	struct collada_surface_s *surface;
	struct collada_sampler2D_s *sampler2D;

} collada_newparam_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_newparam_s *collada_newparam_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_newparam_check(struct collada_ctx_s *, struct collada_newparam_s *);

DLL_PUBLIC void collada_newparam_dump(struct collada_ctx_s *, struct collada_newparam_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_NEWPARAM_H */

/*-------------------------------------------------------------------------*/

