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

#ifndef __COCO_PHONG_H
#define __COCO_PHONG_H

/*-------------------------------------------------------------------------*/

typedef struct coco_phong_s
{
	struct coco_base_s base;

	struct coco_phong_s *prev, *next;

	/**/

	struct coco_emission_s *emission;
	struct coco_ambient_fx_s *ambient;
	struct coco_diffuse_s *diffuse;
	struct coco_specular_s *specular;
	struct coco_shininess_s *shininess;
	struct coco_reflective_s *reflective;
	struct coco_reflectivity_s *reflectivity;
	struct coco_transparent_s *transparent;
	struct coco_transparency_s *transparency;
	struct coco_index_of_refraction_s *index_of_refraction;

} coco_phong_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_phong_s *coco_phong_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_phong_check(struct coco_ctx_s *, struct coco_phong_s *);

DLL_PUBLIC void coco_phong_dump(struct coco_ctx_s *, struct coco_phong_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_PHONG_H */

/*-------------------------------------------------------------------------*/

