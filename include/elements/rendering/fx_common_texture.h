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

#ifndef __COCO_FX_COMMON_TEXTURE_H
#define __COCO_FX_COMMON_TEXTURE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_fx_common_texture_s
{
	struct coco_base_s base;

	struct coco_fx_common_texture_s *prev, *next;

	/**/

	const char *texture;
	const char *texcoord;

	struct coco_extra_s *extra_list;

} coco_fx_common_texture_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_fx_common_texture_s *coco_fx_common_texture_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_fx_common_texture_check(struct coco_ctx_s *, struct coco_fx_common_texture_s *);

DLL_PUBLIC void coco_fx_common_texture_dump(struct coco_ctx_s *, struct coco_fx_common_texture_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_FX_COMMON_TEXTURE_H */

/*-------------------------------------------------------------------------*/

