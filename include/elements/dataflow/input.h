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

#ifndef __COLLADA_INPUT_H
#define __COLLADA_INPUT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_input_s
{
	struct collada_base_s base;

	struct collada_input_s *prev, *next;

	/**/

	int offset;
	const char *semantic;
	const char *source;
	int set;

} collada_input_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_input_s *collada_input_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_input_check(struct collada_ctx_s *, struct collada_input_s *);

DLL_PUBLIC void collada_input_dump(struct collada_ctx_s *, struct collada_input_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_INPUT_H */

/*-------------------------------------------------------------------------*/

