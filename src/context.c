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

#include <string.h>

#include "collada_internal.h"

/*-------------------------------------------------------------------------*/

void collada_ctx_initialize(collada_ctx_t *ctx)
{
	memset(ctx, 0x00, sizeof(collada_ctx_t));

	/**/

	ctnr_hash_init(&ctx->hash_list, collada_base_t, id);
	ctnr_hash_init(&ctx->element_list, collada_ctx_element_t, name);

	ctnr_pool_init(&ctx->pool);

	/* Animation */

	/* Camera */
	collada_ctx_register_element(ctx, collada_camera_t,				collada_camera_parse,				collada_camera_check,				collada_camera_dump				);
	collada_ctx_register_element(ctx, collada_optics_t,				collada_optics_parse,				collada_optics_check,				collada_optics_dump				);
	collada_ctx_register_element(ctx, collada_optics_technique_common_t,		collada_optics_technique_common_parse,		collada_optics_technique_common_check,		collada_optics_technique_common_dump		);
	collada_ctx_register_element(ctx, collada_orthographic_t,			collada_orthographic_parse,			collada_orthographic_check,			collada_orthographic_dump			);
	collada_ctx_register_element(ctx, collada_perspective_t,			collada_perspective_parse,			collada_perspective_check,			collada_perspective_dump			);

	/* Controller */

	/* Dataflow */
	collada_ctx_register_element(ctx, collada_accessor_t,				collada_accessor_parse,				collada_accessor_check,				collada_accessor_dump				);
	collada_ctx_register_element(ctx, collada_accessor_param_t,			collada_accessor_param_parse,			collada_accessor_param_check,			collada_accessor_param_dump			);
	collada_ctx_register_element(ctx, collada_float_array_t,			collada_float_array_parse,			collada_float_array_check,			collada_float_array_dump			);
	collada_ctx_register_element(ctx, collada_input_t,				collada_input_parse,				collada_input_check,				collada_input_dump				);
	collada_ctx_register_element(ctx, collada_source_t,				collada_source_parse,				collada_source_check,				collada_source_dump				);
	collada_ctx_register_element(ctx, collada_source_technique_common_t,		collada_source_technique_common_parse,		collada_source_technique_common_check,		collada_source_technique_common_dump		);

	/* Effects */
	collada_ctx_register_element(ctx, collada_effect_t,				collada_effect_parse,				collada_effect_check,				collada_effect_dump				);
	collada_ctx_register_element(ctx, collada_profile_common_t,			collada_profile_common_parse,			collada_profile_common_check,			collada_profile_common_dump			);
	collada_ctx_register_element(ctx, collada_profile_common_technique_t,		collada_profile_common_technique_parse,		collada_profile_common_technique_check,		collada_profile_common_technique_dump		);

	/* Extensibility */
	collada_ctx_register_element(ctx, collada_extra_t,				collada_extra_parse,				collada_extra_check,				collada_extra_dump				);
	collada_ctx_register_element(ctx, collada_technique_core_t,			collada_technique_core_parse,			collada_technique_core_check,			collada_technique_core_dump			);

	/* Geometry */
	collada_ctx_register_element(ctx, collada_geometry_t,				collada_geometry_parse,				collada_geometry_check,				collada_geometry_dump				);
	collada_ctx_register_element(ctx, collada_mesh_t,				collada_mesh_parse,				collada_mesh_check,				collada_mesh_dump				);
	collada_ctx_register_element(ctx, collada_p_t,					collada_p_parse,				collada_p_check,				collada_p_dump					);
	collada_ctx_register_element(ctx, collada_polylist_t,				collada_polylist_parse,				collada_polylist_check,				collada_polylist_dump				);
	collada_ctx_register_element(ctx, collada_triangles_t,				collada_triangles_parse,			collada_triangles_check,			collada_triangles_dump				);
	collada_ctx_register_element(ctx, collada_vcount_t,				collada_vcount_parse,				collada_vcount_check,				collada_vcount_dump				);
	collada_ctx_register_element(ctx, collada_vertices_t,				collada_vertices_parse,				collada_vertices_check,				collada_vertices_dump				);
	collada_ctx_register_element(ctx, collada_vertices_input_t,			collada_vertices_input_parse,			collada_vertices_input_check,			collada_vertices_input_dump			);

	/* Lightning */
	collada_ctx_register_element(ctx, collada_color_t,				collada_color_parse,				collada_color_check,				collada_color_dump				);
	collada_ctx_register_element(ctx, collada_light_t,				collada_light_parse,				collada_light_check,				collada_light_dump				);
	collada_ctx_register_element(ctx, collada_light_technique_common_t,		collada_light_technique_common_parse,		collada_light_technique_common_check,		collada_light_technique_common_dump		);
	collada_ctx_register_element(ctx, collada_ambient_core_t,			collada_ambient_core_parse,			collada_ambient_core_check,			collada_ambient_core_dump			);
	collada_ctx_register_element(ctx, collada_directional_t,			collada_directional_parse,			collada_directional_check,			collada_directional_dump			);
	collada_ctx_register_element(ctx, collada_spot_t,				collada_spot_parse,				collada_spot_check,				collada_spot_dump				);
	collada_ctx_register_element(ctx, collada_point_t,				collada_point_parse,				collada_point_check,				collada_point_dump				);

	/* Materials */	
	collada_ctx_register_element(ctx, collada_instance_effect_t,			collada_instance_effect_parse,			collada_instance_effect_check,			collada_instance_effect_dump			);
	collada_ctx_register_element(ctx, collada_instance_effect_technique_hint_t,	collada_instance_effect_technique_hint_parse,	collada_instance_effect_technique_hint_check,	collada_instance_effect_technique_hint_dump	);
	collada_ctx_register_element(ctx, collada_material_t,				collada_material_parse,				collada_material_check,				collada_material_dump				);

	/* Metadata */
	collada_ctx_register_element(ctx, collada_asset_t,				collada_asset_parse,				collada_asset_check,				collada_asset_dump				);
	collada_ctx_register_element(ctx, collada_asset_contributor_t,			collada_asset_contributor_parse,		collada_asset_contributor_check,		collada_asset_contributor_dump			);
	collada_ctx_register_element(ctx, collada_t,					collada_parse,					collada_check,					collada_dump					);
	collada_ctx_register_element(ctx, collada_library_cameras_t,			collada_library_cameras_parse,			collada_library_cameras_check,			collada_library_cameras_dump			);
	collada_ctx_register_element(ctx, collada_library_effects_t,			collada_library_effects_parse,			collada_library_effects_check,			collada_library_effects_dump			);
	collada_ctx_register_element(ctx, collada_library_geometries_t,			collada_library_geometries_parse,		collada_library_geometries_check,		collada_library_geometries_dump			);
	collada_ctx_register_element(ctx, collada_library_images_t,			collada_library_images_parse,			collada_library_images_check,			collada_library_images_dump			);
	collada_ctx_register_element(ctx, collada_library_lights_t,			collada_library_lights_parse,			collada_library_lights_check,			collada_library_lights_dump			);
	collada_ctx_register_element(ctx, collada_library_materials_t,			collada_library_materials_parse,		collada_library_materials_check,		collada_library_materials_dump			);
	collada_ctx_register_element(ctx, collada_library_nodes_t,			collada_library_nodes_parse,			collada_library_nodes_check,			collada_library_nodes_dump			);
	collada_ctx_register_element(ctx, collada_library_visual_scenes_t,		collada_library_visual_scenes_parse,		collada_library_visual_scenes_check,		collada_library_visual_scenes_dump		);
	collada_ctx_register_element(ctx, collada_unit_t,				collada_unit_parse,				collada_unit_check,				collada_unit_dump				);

	/* Physics_material */

	/* Physics_model */

	/* Rendering */
	collada_ctx_register_element(ctx, collada_ambient_fx_t,				collada_ambient_fx_parse,			collada_ambient_fx_check,			collada_ambient_fx_dump				);
	collada_ctx_register_element(ctx, collada_diffuse_t,				collada_diffuse_parse,				collada_diffuse_check,				collada_diffuse_dump				);
	collada_ctx_register_element(ctx, collada_emission_t,				collada_emission_parse,				collada_emission_check,				collada_emission_dump				);
	collada_ctx_register_element(ctx, collada_fx_common_float_t,			collada_fx_common_float_parse,			collada_fx_common_float_check,			collada_fx_common_float_dump			);
	collada_ctx_register_element(ctx, collada_fx_common_param_t,			collada_fx_common_param_parse,			collada_fx_common_param_check,			collada_fx_common_param_dump			);
	collada_ctx_register_element(ctx, collada_fx_common_texture_t,			collada_fx_common_texture_parse,		collada_fx_common_texture_check,		collada_fx_common_texture_dump			);
	collada_ctx_register_element(ctx, collada_index_of_refraction_t,		collada_index_of_refraction_parse,		collada_index_of_refraction_check,		collada_index_of_refraction_dump		);
	collada_ctx_register_element(ctx, collada_lambert_t,				collada_lambert_parse,				collada_lambert_check,				collada_lambert_dump				);
	collada_ctx_register_element(ctx, collada_phong_t,				collada_phong_parse,				collada_phong_check,				collada_phong_dump				);
	collada_ctx_register_element(ctx, collada_reflective_t,				collada_reflective_parse,			collada_reflective_check,			collada_reflective_dump				);
	collada_ctx_register_element(ctx, collada_reflectivity_t,			collada_reflectivity_parse,			collada_reflectivity_check,			collada_reflectivity_dump			);
	collada_ctx_register_element(ctx, collada_shininess_t,				collada_shininess_parse,			collada_shininess_check,			collada_shininess_dump				);
	collada_ctx_register_element(ctx, collada_specular_t,				collada_specular_parse,				collada_specular_check,				collada_specular_dump				);
	collada_ctx_register_element(ctx, collada_transparency_t,			collada_transparency_parse,			collada_transparency_check,			collada_transparency_dump			);
	collada_ctx_register_element(ctx, collada_transparent_t,			collada_transparent_parse,			collada_transparent_check,			collada_transparent_dump			);

	/* Scene */
	collada_ctx_register_element(ctx, collada_bind_material_param_t,		collada_bind_material_param_parse,		collada_bind_material_param_check,		collada_bind_material_param_dump		);
	collada_ctx_register_element(ctx, collada_bind_material_technique_common_t,	collada_bind_material_technique_common_parse,	collada_bind_material_technique_common_check,	collada_bind_material_technique_common_dump	);
	collada_ctx_register_element(ctx, collada_bind_material_t,			collada_bind_material_parse,			collada_bind_material_check,			collada_bind_material_dump			);
	collada_ctx_register_element(ctx, collada_bind_vertex_input_t,			collada_bind_vertex_input_parse,		collada_bind_vertex_input_check,		collada_bind_vertex_input_dump			);
	collada_ctx_register_element(ctx, collada_instance_camera_t,			collada_instance_camera_parse,			collada_instance_camera_check,			collada_instance_camera_dump			);
	collada_ctx_register_element(ctx, collada_instance_geometry_t,			collada_instance_geometry_parse,		collada_instance_geometry_check,		collada_instance_geometry_dump			);
	collada_ctx_register_element(ctx, collada_instance_light_t,			collada_instance_light_parse,			collada_instance_light_check,			collada_instance_light_dump			);
	collada_ctx_register_element(ctx, collada_instance_material_t,			collada_instance_material_parse,		collada_instance_material_check,		collada_instance_material_dump			);
	collada_ctx_register_element(ctx, collada_instance_node_t,			collada_instance_node_parse,			collada_instance_node_check,			collada_instance_node_dump			);
	collada_ctx_register_element(ctx, collada_instance_visual_scene_t,		collada_instance_visual_scene_parse,		collada_instance_visual_scene_check,		collada_instance_visual_scene_dump		);
	collada_ctx_register_element(ctx, collada_node_t,				collada_node_parse,				collada_node_check,				collada_node_dump				);
	collada_ctx_register_element(ctx, collada_scene_t,				collada_scene_parse,				collada_scene_check,				collada_scene_dump				);
	collada_ctx_register_element(ctx, collada_visual_scene_t,			collada_visual_scene_parse,			collada_visual_scene_check,			collada_visual_scene_dump			);

	/* Shader */
	collada_ctx_register_element(ctx, collada_newparam_t,				collada_newparam_parse,				collada_newparam_check,				collada_newparam_dump				);

	/* Texturing */
	collada_ctx_register_element(ctx, collada_image_t,				collada_image_parse,				collada_image_check,				collada_image_dump				);
	collada_ctx_register_element(ctx, collada_sampler2D_t,				collada_sampler2D_parse,			collada_sampler2D_check,			collada_sampler2D_dump				);
	collada_ctx_register_element(ctx, collada_surface_t,				collada_surface_parse,				collada_surface_check,				collada_surface_dump				);
	collada_ctx_register_element(ctx, collada_surface_init_from_t,			collada_surface_init_from_parse,		collada_surface_init_from_check,		collada_surface_init_from_dump			);

	/* Transform */
	collada_ctx_register_element(ctx, collada_lookat_t,				collada_lookat_parse,				collada_lookat_check,				collada_lookat_dump				);
	collada_ctx_register_element(ctx, collada_matrix_t,				collada_matrix_parse,				collada_matrix_check,				collada_matrix_dump				);
	collada_ctx_register_element(ctx, collada_rotate_t,				collada_rotate_parse,				collada_rotate_check,				collada_rotate_dump				);
	collada_ctx_register_element(ctx, collada_scale_t,				collada_scale_parse,				collada_scale_check,				collada_scale_dump				);
	collada_ctx_register_element(ctx, collada_translate_t,				collada_translate_parse,			collada_translate_check,			collada_translate_dump				);
/*
	collada_ctx_register_element(ctx, collada__t, collada__parser, collada__dump);
*/
}

/*-------------------------------------------------------------------------*/

void collada_ctx_finalize(collada_ctx_t *ctx)
{
	ctnr_pool_flush(&ctx->pool);
}

/*-------------------------------------------------------------------------*/

void __collada_ctx_register_element(collada_ctx_t *ctx, const char *elm_name, void *elm_parser, void *elm_check, void *elm_dump)
{
	collada_ctx_element_t *element = ctnr_pool_new(&ctx->pool, collada_ctx_element_t);

	element->name = collada_ctx_strdup(ctx, elm_name);

	element->parser = elm_parser;
	element->check = elm_check;
	element->dump = elm_dump;

	ctnr_hash_add(&ctx->element_list, element);
}

/*-------------------------------------------------------------------------*/

void *__collada_ctx_get_parser(collada_ctx_t *ctx, unsigned hash)
{
	collada_ctx_element_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->element_list, &element, hash) != false) {
		return element->parser;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

void *__collada_ctx_get_check(struct collada_ctx_s *ctx, unsigned hash)
{
	collada_ctx_element_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->element_list, &element, hash) != false) {
		return element->check;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

void *__collada_ctx_get_dump(collada_ctx_t *ctx, unsigned hash)
{
	collada_ctx_element_t *element = NULL;

	if(ctnr_hash_lookup_item_by_hash(&ctx->element_list, &element, hash) != false) {
		return element->dump;
	}
	else {
		return NULL;
	}
}

/*-------------------------------------------------------------------------*/

bool collada_ctx_loader(collada_ctx_t *ctx, BUFF_t buff, size_t size)
{
	yaxp_ctx_t yaxp;

	yaxp_parser_initialize(&yaxp);

	bool result = yaxp_parser(&yaxp, buff, size);

	/**/

	if(result != false)
	{
		ctx->collada = collada_ctx_parser(ctx, collada_t, yaxp.node);

		yaxp_parser_finalize(&yaxp);
	}

	return result;
}

/*-------------------------------------------------------------------------*/

bool collada_ctx_check_all(struct collada_ctx_s *ctx)
{
	return collada_ctx_check(ctx, collada_t, ctx->collada);
}

/*-------------------------------------------------------------------------*/

void collada_ctx_dump_all(collada_ctx_t *ctx)
{
	collada_ctx_dump(ctx, collada_t, ctx->collada, 0);
}

/*-------------------------------------------------------------------------*/

const char *collada_ctx_strdup(collada_ctx_t *ctx, const char *str)
{
	return strcpy(ctnr_pool_malloc(&ctx->pool, strlen(str) + 1), str);
}

/*-------------------------------------------------------------------------*/

collada_base_t *__collada_ctx_lookup_by_hash(collada_ctx_t *ctx, unsigned type, unsigned hash)
{
	collada_base_t *base = NULL;

	return ctnr_hash_lookup_item_by_hash(&ctx->hash_list, &base, hash) && base->type == type ? base : NULL;
}

/*-------------------------------------------------------------------------*/

collada_base_t *__collada_ctx_lookup_by_name(collada_ctx_t *ctx, unsigned type, const char *name)
{
	collada_base_t *base = NULL;

	return ctnr_hash_lookup_item_by_name(&ctx->hash_list, &base, name) && base->type == type ? base : NULL;
}

/*-------------------------------------------------------------------------*/

