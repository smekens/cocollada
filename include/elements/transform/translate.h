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

#ifndef __COLLADA_TRANSLATE_H
#define __COLLADA_TRANSLATE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_translate_s
{
	struct collada_base_s base;

	struct collada_translate_s *prev, *next;

	/**/

	const char *sid;

	float array[3];

} collada_translate_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_translate_s *collada_translate_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_translate_check(struct collada_ctx_s *, struct collada_translate_s *);

DLL_PUBLIC void collada_translate_dump(struct collada_ctx_s *, struct collada_translate_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_TRANSLATE_H */

/*-------------------------------------------------------------------------*/

