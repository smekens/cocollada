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

#include <string.h>

#include "coco_internal.h"

/*-------------------------------------------------------------------------*/

void coco_ctx_initialize(coco_ctx_t *ctx)
{
	memset(ctx, 0x00, sizeof(coco_ctx_t));

	/**/

	ctnr_hash_init(&ctx->hash_list, coco_base_t, id);
	ctnr_hash_init(&ctx->elem_list, coco_ctx_elem_t, name);

	ctnr_pool_init(&ctx->pool);

	/* Animation */

	/* Camera */
	coco_ctx_register_element(ctx, coco_camera_t,				coco_camera_parse,				coco_camera_check,				coco_camera_dump			);
	coco_ctx_register_element(ctx, coco_optics_t,				coco_optics_parse,				coco_optics_check,				coco_optics_dump			);
	coco_ctx_register_element(ctx, coco_optics_technique_common_t,		coco_optics_technique_common_parse,		coco_optics_technique_common_check,		coco_optics_technique_common_dump	);
	coco_ctx_register_element(ctx, coco_orthographic_t,			coco_orthographic_parse,			coco_orthographic_check,			coco_orthographic_dump			);
	coco_ctx_register_element(ctx, coco_perspective_t,			coco_perspective_parse,				coco_perspective_check,				coco_perspective_dump			);

	/* Controller */

	/* Dataflow */
	coco_ctx_register_element(ctx, coco_accessor_t,				coco_accessor_parse,				coco_accessor_check,				coco_accessor_dump			);
	coco_ctx_register_element(ctx, coco_accessor_param_t,			coco_accessor_param_parse,			coco_accessor_param_check,			coco_accessor_param_dump		);
	coco_ctx_register_element(ctx, coco_float_array_t,			coco_float_array_parse,				coco_float_array_check,				coco_float_array_dump			);
	coco_ctx_register_element(ctx, coco_input_t,				coco_input_parse,				coco_input_check,				coco_input_dump				);
	coco_ctx_register_element(ctx, coco_source_t,				coco_source_parse,				coco_source_check,				coco_source_dump			);
	coco_ctx_register_element(ctx, coco_source_technique_common_t,		coco_source_technique_common_parse,		coco_source_technique_common_check,		coco_source_technique_common_dump	);

	/* Effects */
	coco_ctx_register_element(ctx, coco_effect_t,				coco_effect_parse,				coco_effect_check,				coco_effect_dump			);
	coco_ctx_register_element(ctx, coco_profile_common_t,			coco_profile_common_parse,			coco_profile_common_check,			coco_profile_common_dump		);
	coco_ctx_register_element(ctx, coco_profile_common_technique_t,		coco_profile_common_technique_parse,		coco_profile_common_technique_check,		coco_profile_common_technique_dump	);

	/* Extensibility */
	coco_ctx_register_element(ctx, coco_extra_t,				coco_extra_parse,				coco_extra_check,				coco_extra_dump				);
	coco_ctx_register_element(ctx, coco_technique_core_t,			coco_technique_core_parse,			coco_technique_core_check,			coco_technique_core_dump		);

	/* Geometry */
	coco_ctx_register_element(ctx, coco_geometry_t,				coco_geometry_parse,				coco_geometry_check,				coco_geometry_dump			);
	coco_ctx_register_element(ctx, coco_mesh_t,				coco_mesh_parse,				coco_mesh_check,				coco_mesh_dump				);
	coco_ctx_register_element(ctx, coco_p_t,				coco_p_parse,					coco_p_check,					coco_p_dump				);
	coco_ctx_register_element(ctx, coco_polylist_t,				coco_polylist_parse,				coco_polylist_check,				coco_polylist_dump			);
	coco_ctx_register_element(ctx, coco_triangles_t,			coco_triangles_parse,				coco_triangles_check,				coco_triangles_dump			);
	coco_ctx_register_element(ctx, coco_vcount_t,				coco_vcount_parse,				coco_vcount_check,				coco_vcount_dump			);
	coco_ctx_register_element(ctx, coco_vertices_t,				coco_vertices_parse,				coco_vertices_check,				coco_vertices_dump			);
	coco_ctx_register_element(ctx, coco_vertices_input_t,			coco_vertices_input_parse,			coco_vertices_input_check,			coco_vertices_input_dump		);

	/* Lightning */
	coco_ctx_register_element(ctx, coco_color_t,				coco_color_parse,				coco_color_check,				coco_color_dump				);
	coco_ctx_register_element(ctx, coco_light_t,				coco_light_parse,				coco_light_check,				coco_light_dump				);
	coco_ctx_register_element(ctx, coco_light_technique_common_t,		coco_light_technique_common_parse,		coco_light_technique_common_check,		coco_light_technique_common_dump	);
	coco_ctx_register_element(ctx, coco_ambient_core_t,			coco_ambient_core_parse,			coco_ambient_core_check,			coco_ambient_core_dump			);
	coco_ctx_register_element(ctx, coco_directional_t,			coco_directional_parse,				coco_directional_check,				coco_directional_dump			);
	coco_ctx_register_element(ctx, coco_spot_t,				coco_spot_parse,				coco_spot_check,				coco_spot_dump				);
	coco_ctx_register_element(ctx, coco_point_t,				coco_point_parse,				coco_point_check,				coco_point_dump				);

	/* Materials */	
	coco_ctx_register_element(ctx, coco_instance_effect_t,			coco_instance_effect_parse,			coco_instance_effect_check,			coco_instance_effect_dump		);
	coco_ctx_register_element(ctx, coco_instance_effect_technique_hint_t,	coco_instance_effect_technique_hint_parse,	coco_instance_effect_technique_hint_check,	coco_instance_effect_technique_hint_dump);
	coco_ctx_register_element(ctx, coco_material_t,				coco_material_parse,				coco_material_check,				coco_material_dump			);

	/* Metadata */
	coco_ctx_register_element(ctx, coco_asset_t,				coco_asset_parse,				coco_asset_check,				coco_asset_dump				);
	coco_ctx_register_element(ctx, coco_asset_contributor_t,		coco_asset_contributor_parse,			coco_asset_contributor_check,			coco_asset_contributor_dump		);
	coco_ctx_register_element(ctx, coco_collada_t,				coco_collada_parse,				coco_collada_check,				coco_collada_dump			);
	coco_ctx_register_element(ctx, coco_library_cameras_t,			coco_library_cameras_parse,			coco_library_cameras_check,			coco_library_cameras_dump		);
	coco_ctx_register_element(ctx, coco_library_effects_t,			coco_library_effects_parse,			coco_library_effects_check,			coco_library_effects_dump		);
	coco_ctx_register_element(ctx, coco_library_geometries_t,		coco_library_geometries_parse,			coco_library_geometries_check,			coco_library_geometries_dump		);
	coco_ctx_register_element(ctx, coco_library_images_t,			coco_library_images_parse,			coco_library_images_check,			coco_library_images_dump		);
	coco_ctx_register_element(ctx, coco_library_lights_t,			coco_library_lights_parse,			coco_library_lights_check,			coco_library_lights_dump		);
	coco_ctx_register_element(ctx, coco_library_materials_t,		coco_library_materials_parse,			coco_library_materials_check,			coco_library_materials_dump		);
	coco_ctx_register_element(ctx, coco_library_nodes_t,			coco_library_nodes_parse,			coco_library_nodes_check,			coco_library_nodes_dump			);
	coco_ctx_register_element(ctx, coco_library_visual_scenes_t,		coco_library_visual_scenes_parse,		coco_library_visual_scenes_check,		coco_library_visual_scenes_dump		);
	coco_ctx_register_element(ctx, coco_unit_t,				coco_unit_parse,				coco_unit_check,				coco_unit_dump				);

	/* Physics_material */

	/* Physics_model */

	/* Rendering */
	coco_ctx_register_element(ctx, coco_ambient_fx_t,			coco_ambient_fx_parse,				coco_ambient_fx_check,				coco_ambient_fx_dump			);
	coco_ctx_register_element(ctx, coco_diffuse_t,				coco_diffuse_parse,				coco_diffuse_check,				coco_diffuse_dump			);
	coco_ctx_register_element(ctx, coco_emission_t,				coco_emission_parse,				coco_emission_check,				coco_emission_dump			);
	coco_ctx_register_element(ctx, coco_fx_common_float_t,			coco_fx_common_float_parse,			coco_fx_common_float_check,			coco_fx_common_float_dump		);
	coco_ctx_register_element(ctx, coco_fx_common_param_t,			coco_fx_common_param_parse,			coco_fx_common_param_check,			coco_fx_common_param_dump		);
	coco_ctx_register_element(ctx, coco_fx_common_texture_t,		coco_fx_common_texture_parse,			coco_fx_common_texture_check,			coco_fx_common_texture_dump		);
	coco_ctx_register_element(ctx, coco_index_of_refraction_t,		coco_index_of_refraction_parse,			coco_index_of_refraction_check,			coco_index_of_refraction_dump		);
	coco_ctx_register_element(ctx, coco_lambert_t,				coco_lambert_parse,				coco_lambert_check,				coco_lambert_dump			);
	coco_ctx_register_element(ctx, coco_phong_t,				coco_phong_parse,				coco_phong_check,				coco_phong_dump				);
	coco_ctx_register_element(ctx, coco_reflective_t,			coco_reflective_parse,				coco_reflective_check,				coco_reflective_dump			);
	coco_ctx_register_element(ctx, coco_reflectivity_t,			coco_reflectivity_parse,			coco_reflectivity_check,			coco_reflectivity_dump			);
	coco_ctx_register_element(ctx, coco_shininess_t,			coco_shininess_parse,				coco_shininess_check,				coco_shininess_dump			);
	coco_ctx_register_element(ctx, coco_specular_t,				coco_specular_parse,				coco_specular_check,				coco_specular_dump			);
	coco_ctx_register_element(ctx, coco_transparency_t,			coco_transparency_parse,			coco_transparency_check,			coco_transparency_dump			);
	coco_ctx_register_element(ctx, coco_transparent_t,			coco_transparent_parse,				coco_transparent_check,				coco_transparent_dump			);

	/* Scene */
	coco_ctx_register_element(ctx, coco_bind_material_param_t,		coco_bind_material_param_parse,			coco_bind_material_param_check,			coco_bind_material_param_dump		);
	coco_ctx_register_element(ctx, coco_bind_material_technique_common_t,	coco_bind_material_technique_common_parse,	coco_bind_material_technique_common_check,	coco_bind_material_technique_common_dump);
	coco_ctx_register_element(ctx, coco_bind_material_t,			coco_bind_material_parse,			coco_bind_material_check,			coco_bind_material_dump			);
	coco_ctx_register_element(ctx, coco_bind_vertex_input_t,		coco_bind_vertex_input_parse,			coco_bind_vertex_input_check,			coco_bind_vertex_input_dump		);
	coco_ctx_register_element(ctx, coco_instance_camera_t,			coco_instance_camera_parse,			coco_instance_camera_check,			coco_instance_camera_dump		);
	coco_ctx_register_element(ctx, coco_instance_geometry_t,		coco_instance_geometry_parse,			coco_instance_geometry_check,			coco_instance_geometry_dump		);
	coco_ctx_register_element(ctx, coco_instance_light_t,			coco_instance_light_parse,			coco_instance_light_check,			coco_instance_light_dump		);
	coco_ctx_register_element(ctx, coco_instance_material_t,		coco_instance_material_parse,			coco_instance_material_check,			coco_instance_material_dump		);
	coco_ctx_register_element(ctx, coco_instance_node_t,			coco_instance_node_parse,			coco_instance_node_check,			coco_instance_node_dump			);
	coco_ctx_register_element(ctx, coco_instance_visual_scene_t,		coco_instance_visual_scene_parse,		coco_instance_visual_scene_check,		coco_instance_visual_scene_dump		);
	coco_ctx_register_element(ctx, coco_node_t,				coco_node_parse,				coco_node_check,				coco_node_dump				);
	coco_ctx_register_element(ctx, coco_scene_t,				coco_scene_parse,				coco_scene_check,				coco_scene_dump				);
	coco_ctx_register_element(ctx, coco_visual_scene_t,			coco_visual_scene_parse,			coco_visual_scene_check,			coco_visual_scene_dump			);

	/* Shader */
	coco_ctx_register_element(ctx, coco_newparam_t,				coco_newparam_parse,				coco_newparam_check,				coco_newparam_dump			);

	/* Texturing */
	coco_ctx_register_element(ctx, coco_image_t,				coco_image_parse,				coco_image_check,				coco_image_dump				);
	coco_ctx_register_element(ctx, coco_sampler2D_t,			coco_sampler2D_parse,				coco_sampler2D_check,				coco_sampler2D_dump			);
	coco_ctx_register_element(ctx, coco_surface_t,				coco_surface_parse,				coco_surface_check,				coco_surface_dump			);
	coco_ctx_register_element(ctx, coco_surface_init_from_t,		coco_surface_init_from_parse,			coco_surface_init_from_check,			coco_surface_init_from_dump		);

	/* Transform */
	coco_ctx_register_element(ctx, coco_lookat_t,				coco_lookat_parse,				coco_lookat_check,				coco_lookat_dump			);
	coco_ctx_register_element(ctx, coco_matrix_t,				coco_matrix_parse,				coco_matrix_check,				coco_matrix_dump			);
	coco_ctx_register_element(ctx, coco_rotate_t,				coco_rotate_parse,				coco_rotate_check,				coco_rotate_dump			);
	coco_ctx_register_element(ctx, coco_scale_t,				coco_scale_parse,				coco_scale_check,				coco_scale_dump				);
	coco_ctx_register_element(ctx, coco_translate_t,			coco_translate_parse,				coco_translate_check,				coco_translate_dump			);
/*
	coco_ctx_register_element(ctx, coco__t, coco__parse, coco__dump);
*/
}

/*-------------------------------------------------------------------------*/

void coco_ctx_finalize(coco_ctx_t *ctx)
{
	ctnr_pool_flush(&ctx->pool);
}

/*-------------------------------------------------------------------------*/

void __coco_ctx_register_element(coco_ctx_t *ctx, const char *elm_name, void *elm_parse, void *elm_check, void *elm_dump)
{
	coco_ctx_elem_t *element = ctnr_pool_new(&ctx->pool, coco_ctx_elem_t);

	element->name = coco_ctx_strdup(ctx, elm_name);

	element->parser = elm_parse;
	element->check = elm_check;
	element->dump = elm_dump;

	ctnr_hash_add(&ctx->elem_list, element);
}

/*-------------------------------------------------------------------------*/

void *__coco_ctx_get_parse(coco_ctx_t *ctx, unsigned hash)
{
	coco_ctx_elem_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->elem_list, &element, hash) != false) {
		return element->parser;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

void *__coco_ctx_get_check(struct coco_ctx_s *ctx, unsigned hash)
{
	coco_ctx_elem_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->elem_list, &element, hash) != false) {
		return element->check;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

void *__coco_ctx_get_dump(coco_ctx_t *ctx, unsigned hash)
{
	coco_ctx_elem_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->elem_list, &element, hash) != false) {
		return element->dump;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

bool coco_ctx_loader(coco_ctx_t *ctx, BUFF_t buff, size_t size)
{
	yaxp_ctx_t yaxp;

	yaxp_initialize(&yaxp);

	bool result = yaxp_parser(&yaxp, buff, size);

	/**/

	if(result != false)
	{
		ctx->collada = coco_ctx_parse(ctx, coco_collada_t, yaxp.node);

		yaxp_finalize(&yaxp);
	}

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_ctx_check_all(struct coco_ctx_s *ctx)
{
	return coco_ctx_check(ctx, coco_collada_t, ctx->collada);
}

/*-------------------------------------------------------------------------*/

void coco_ctx_dump_all(coco_ctx_t *ctx)
{
	coco_ctx_dump(ctx, coco_collada_t, ctx->collada, 0);
}

/*-------------------------------------------------------------------------*/

const char *coco_ctx_strdup(coco_ctx_t *ctx, const char *str)
{
	return strcpy(ctnr_pool_malloc(&ctx->pool, strlen(str) + 1), str);
}

/*-------------------------------------------------------------------------*/

coco_base_t *__coco_ctx_lookup_by_hash(coco_ctx_t *ctx, unsigned type, unsigned hash)
{
	coco_base_t *base = NULL;

	return ctnr_hash_lookup_item_by_hash(&ctx->hash_list, &base, hash) && base->type == type ? base : NULL;
}

/*-------------------------------------------------------------------------*/

coco_base_t *__coco_ctx_lookup_by_name(coco_ctx_t *ctx, unsigned type, const char *name)
{
	coco_base_t *base = NULL;

	return ctnr_hash_lookup_item_by_name(&ctx->hash_list, &base, name) && base->type == type ? base : NULL;
}

/*-------------------------------------------------------------------------*/

