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

#ifndef __COLLADA_IMAGE_H
#define __COLLADA_IMAGE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_image_s
{
	struct collada_base_s base;

	struct collada_image_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *format;

	int height;
	int width;
	int depth;

	struct collada_asset_s *asset;

	const char *data;
	const char *init_from;

	struct collada_extra_s *extra_list;

} collada_image_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_image_s *collada_image_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_image_check(struct collada_ctx_s *, struct collada_image_s *);

DLL_PUBLIC void collada_image_dump(struct collada_ctx_s *, struct collada_image_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_IMAGE_H */

/*-------------------------------------------------------------------------*/

