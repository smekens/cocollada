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

#ifndef __COLLADA_PERSPECTIVE_H
#define __COLLADA_PERSPECTIVE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_perspective_s
{
	struct collada_base_s base;

	struct collada_perspective_s *prev, *next;

	/**/

	float xfov;
	float yfov;
	float aspect_ratio;

	float znear;
	float zfar;

} collada_perspective_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_perspective_s *collada_perspective_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_perspective_check(struct collada_ctx_s *, struct collada_perspective_s *);

DLL_PUBLIC void collada_perspective_dump(struct collada_ctx_s *, struct collada_perspective_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_PERSPECTIVE_H */

/*-------------------------------------------------------------------------*/

