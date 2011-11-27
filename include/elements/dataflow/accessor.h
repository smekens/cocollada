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

#ifndef __COLLADA_ACCESSOR_H
#define __COLLADA_ACCESSOR_H

/*-------------------------------------------------------------------------*/

typedef struct collada_accessor_param_s
{
	struct collada_base_s base;

	struct collada_accessor_param_s *prev, *next;

	/**/

	const char *name;
	const char *sid;
	const char *semantic;
	const char *type;

} collada_accessor_param_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_accessor_s
{
	struct collada_base_s base;

	struct collada_accessor_s *prev, *next;

	/**/

	int count;
	int offset;
	const char *source;
	int stride;

	struct collada_accessor_param_s *param_list;

} collada_accessor_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_accessor_param_s *collada_accessor_param_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_accessor_param_check(struct collada_ctx_s *, struct collada_accessor_param_s *);

DLL_PUBLIC void collada_accessor_param_dump(struct collada_ctx_s *, struct collada_accessor_param_s *, int);

/**/

DLL_PUBLIC struct collada_accessor_s *collada_accessor_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_accessor_check(struct collada_ctx_s *, struct collada_accessor_s *);

DLL_PUBLIC void collada_accessor_dump(struct collada_ctx_s *, struct collada_accessor_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_ACCESSOR_H */

/*-------------------------------------------------------------------------*/

