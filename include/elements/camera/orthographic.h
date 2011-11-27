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

#ifndef __COLLADA_ORTHOGRAPHIC_H
#define __COLLADA_ORTHOGRAPHIC_H

/*-------------------------------------------------------------------------*/

typedef struct collada_orthographic_s
{
	struct collada_base_s base;

	struct collada_orthographic_s *prev, *next;

	/**/

	float xmag;
	float ymag;
	float aspect_ratio;

	float znear;
	float zfar;

} collada_orthographic_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_orthographic_s *collada_orthographic_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_orthographic_check(struct collada_ctx_s *, struct collada_orthographic_s *);

DLL_PUBLIC void collada_orthographic_dump(struct collada_ctx_s *, struct collada_orthographic_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_ORTHOGRAPHIC_H */

/*-------------------------------------------------------------------------*/

