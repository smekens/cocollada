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

#ifndef __COLLADA_COLOR_H
#define __COLLADA_COLOR_H

/*-------------------------------------------------------------------------*/

typedef struct collada_color_s
{
	struct collada_base_s base;

	struct collada_color_s *prev, *next;

	/**/

	const char *sid;

	float r;
	float g;
	float b;
	float a;

} collada_color_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_color_s *collada_color_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_color_check(struct collada_ctx_s *, struct collada_color_s *);

DLL_PUBLIC void collada_color_dump(struct collada_ctx_s *, struct collada_color_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_COLOR_H */

/*-------------------------------------------------------------------------*/

