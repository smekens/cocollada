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

#ifndef __COCO_SAMPLER2D_H
#define __COCO_SAMPLER2D_H

/*-------------------------------------------------------------------------*/

typedef struct coco_sampler2D_s
{
	struct coco_base_s base;

	struct coco_sampler2D_s *prev, *next;

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

} coco_sampler2D_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_sampler2D_s *coco_sampler2D_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_sampler2D_check(struct coco_ctx_s *, struct coco_sampler2D_s *);

DLL_PUBLIC void coco_sampler2D_dump(struct coco_ctx_s *, struct coco_sampler2D_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SAMPLER2D_H */

/*-------------------------------------------------------------------------*/

