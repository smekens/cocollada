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

#ifndef __COCO_LAMBERT_H
#define __COCO_LAMBERT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_lambert_s
{
	struct coco_base_s base;

	struct coco_lambert_s *prev, *next;

	/**/

	struct coco_emission_s *emission;
	struct coco_ambient_fx_s *ambient;
	struct coco_diffuse_s *diffuse;
	struct coco_reflective_s *reflective;
	struct coco_reflectivity_s *reflectivity;
	struct coco_transparent_s *transparent;
	struct coco_transparency_s *transparency;
	struct coco_index_of_refraction_s *index_of_refraction;

} coco_lambert_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_lambert_s *coco_lambert_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_lambert_check(struct coco_ctx_s *, struct coco_lambert_s *);

DLL_PUBLIC void coco_lambert_dump(struct coco_ctx_s *, struct coco_lambert_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_LAMBERT_H */

/*-------------------------------------------------------------------------*/

