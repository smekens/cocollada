/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of COCO.
 *
 */

/*-------------------------------------------------------------------------*/

#ifndef __COCO_IMAGE_H
#define __COCO_IMAGE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_image_s
{
	struct coco_base_s base;

	struct coco_image_s *prev, *next;

	/**/

	const char *id;
	const char *name;
	const char *format;

	int height;
	int width;
	int depth;

	struct coco_asset_s *asset;

	const char *data;
	const char *init_from;

	struct coco_extra_s *extra_list;

} coco_image_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_image_s *coco_image_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_image_check(struct coco_ctx_s *, struct coco_image_s *);

DLL_PUBLIC void coco_image_dump(struct coco_ctx_s *, struct coco_image_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_IMAGE_H */

/*-------------------------------------------------------------------------*/

