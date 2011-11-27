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

#ifndef __COLLADA_POINT_H
#define __COLLADA_POINT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_point_s
{
	struct collada_base_s base;

	struct collada_point_s *prev, *next;

	/**/

	struct collada_color_s *color;

	float constant_attenuation;
	float linear_attenuation;
	float quadratic_attenuation;

} collada_point_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_point_s *collada_point_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_point_check(struct collada_ctx_s *, struct collada_point_s *);

DLL_PUBLIC void collada_point_dump(struct collada_ctx_s *, struct collada_point_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_POINT_H */

/*-------------------------------------------------------------------------*/

