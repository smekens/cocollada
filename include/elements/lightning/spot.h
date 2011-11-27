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

#ifndef __COLLADA_SPOT_H
#define __COLLADA_SPOT_H

/*-------------------------------------------------------------------------*/

typedef struct collada_spot_s
{
	struct collada_base_s base;

	struct collada_spot_s *prev, *next;

	/**/

	struct collada_color_s *color;

	float constant_attenuation;
	float linear_attenuation;
	float quadratic_attenuation;

	float falloff_angle;
	float falloff_exponent;

} collada_spot_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_spot_s *collada_spot_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_spot_check(struct collada_ctx_s *, struct collada_spot_s *);

DLL_PUBLIC void collada_spot_dump(struct collada_ctx_s *, struct collada_spot_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SPOT_H */

/*-------------------------------------------------------------------------*/

