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

#ifndef __COLLADA_INSTANCE_LIGHT_H
#define __COLLADA_INSTANCE_LIGHT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_instance_light_s
{
	struct collada_base_s base;

	struct collada_instance_light_s *prev, *next;

	/**/

	const char *url;
	const char *sid;
	const char *name;

	struct collada_extra_s *extra_list;

} collada_instance_light_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_instance_light_s *collada_instance_light_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_instance_light_check(struct collada_ctx_s *, struct collada_instance_light_s *);

DLL_PUBLIC void collada_instance_light_dump(struct collada_ctx_s *, struct collada_instance_light_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_INSTANCE_LIGHT_H */

/*-------------------------------------------------------------------------*/

