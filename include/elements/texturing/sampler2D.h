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

#ifndef __COLLADA_SAMPLER2D_H
#define __COLLADA_SAMPLER2D_H

/*-------------------------------------------------------------------------*/

typedef struct collada_sampler2D_s
{
	struct collada_base_s base;

	struct collada_sampler2D_s *prev, *next;

	/**/

	const char *source;

	const char *wrap_s;
	const char *wrap_t;

	const char *minfilter;
	const char *magfilter;
	const char *mipfilter;

	/* TODO const char *border_color;*/

	/* TODO int mipmap_maxlevel;*/
	/* TODO float mipmap_bias;*/

} collada_sampler2D_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_sampler2D_s *collada_sampler2D_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_sampler2D_check(struct collada_ctx_s *, struct collada_sampler2D_s *);

DLL_PUBLIC void collada_sampler2D_dump(struct collada_ctx_s *, struct collada_sampler2D_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SAMPLER2D_H */

/*-------------------------------------------------------------------------*/

