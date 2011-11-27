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

#ifndef __COLLADA_PHONG_H
#define __COLLADA_PHONG_H

/*-------------------------------------------------------------------------*/

typedef struct collada_phong_s
{
	struct collada_base_s base;

	struct collada_phong_s *prev, *next;

	/**/

	struct collada_emission_s *emission;
	struct collada_ambient_fx_s *ambient;
	struct collada_diffuse_s *diffuse;
	struct collada_specular_s *specular;
	struct collada_shininess_s *shininess;
	struct collada_reflective_s *reflective;
	struct collada_reflectivity_s *reflectivity;
	struct collada_transparent_s *transparent;
	struct collada_transparency_s *transparency;
	struct collada_index_of_refraction_s *index_of_refraction;

} collada_phong_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_phong_s *collada_phong_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_phong_check(struct collada_ctx_s *, struct collada_phong_s *);

DLL_PUBLIC void collada_phong_dump(struct collada_ctx_s *, struct collada_phong_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_PHONG_H */

/*-------------------------------------------------------------------------*/

