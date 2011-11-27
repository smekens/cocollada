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

#ifndef __COCO_SURFACE_H
#define __COCO_SURFACE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_surface_init_from_s
{
	struct coco_base_s base;

	struct coco_surface_init_from_s *prev, *next;

	/**/

	const char *mip;
	const char *slice;
	const char *face;

	const char *ref;

} coco_surface_init_from_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_surface_s
{
	struct coco_base_s base;

	struct coco_surface_s *prev, *next;

	/**/

	const char *type;

	/* TODO struct coco_surface_init_as_null_s *init_as_null;*/
	/* TODO struct coco_surface_init_as_target_s *init_as_target;*/
	/* TODO struct coco_surface_init_cube_s *init_cube;*/
	/* TODO struct coco_surface_init_volume_s *init_volume;*/
	/* TODO struct coco_surface_init_planar_s *init_planar;*/
	struct coco_surface_init_from_s *init_from;

	const char *format;
	/* TODO const char *format_hint;*/

	/* TODO int size[3];*/

	/* TODO float viewport_ratio[2];*/

	/* TODO int mip_levels;*/
	/* TODO bool mipmap_generate;*/

	struct coco_extra_s *extra_list;

} coco_surface_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_surface_init_from_s *coco_surface_init_from_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_surface_init_from_check(struct coco_ctx_s *, struct coco_surface_init_from_s *);

DLL_PUBLIC void coco_surface_init_from_dump(struct coco_ctx_s *, struct coco_surface_init_from_s *, int);

/**/

DLL_PUBLIC struct coco_surface_s *coco_surface_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_surface_check(struct coco_ctx_s *, struct coco_surface_s *);

DLL_PUBLIC void coco_surface_dump(struct coco_ctx_s *, struct coco_surface_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SURFACE_H */

/*-------------------------------------------------------------------------*/

