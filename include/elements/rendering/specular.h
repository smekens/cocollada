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

#ifndef __COCO_SPECULAR_H
#define __COCO_SPECULAR_H

/*-------------------------------------------------------------------------*/

typedef struct coco_specular_s
{
	struct coco_base_s base;

	struct coco_specular_s *prev, *next;

	/**/

	struct coco_color_s *color;
	struct coco_fx_common_param_s *param_list;
	struct coco_fx_common_texture_s *texture_list;

} coco_specular_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_specular_s *coco_specular_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_specular_check(struct coco_ctx_s *, struct coco_specular_s *);

DLL_PUBLIC void coco_specular_dump(struct coco_ctx_s *, struct coco_specular_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SPECULAR_H */

/*-------------------------------------------------------------------------*/

