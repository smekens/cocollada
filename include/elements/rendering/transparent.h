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

#ifndef __COCO_TRANSPARENT_H
#define __COCO_TRANSPARENT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_transparent_s
{
	struct coco_base_s base;

	struct coco_transparent_s *prev, *next;

	/**/

	const char *opaque;

	struct coco_color_s *color;
	struct coco_fx_common_param_s *param_list;
	struct coco_fx_common_texture_s *texture_list;

} coco_transparent_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_transparent_s *coco_transparent_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_transparent_check(struct coco_ctx_s *, struct coco_transparent_s *);

DLL_PUBLIC void coco_transparent_dump(struct coco_ctx_s *, struct coco_transparent_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_TRANSPARENT_H */

/*-------------------------------------------------------------------------*/

