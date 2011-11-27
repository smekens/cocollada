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

#include <stdio.h>
#include <string.h>

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_t *collada_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_t *result = collada_ctx_factory(ctx, collada_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_library_cameras_t *library_cameras;
	collada_library_effects_t *library_effects;
	collada_library_geometries_t *library_geometries;
	collada_library_images_t *library_images;
	collada_library_lights_t *library_lights;
	collada_library_materials_t *library_materials;
	collada_library_nodes_t *library_nodes;
	collada_library_visual_scenes_t *library_visual_scenes;
	collada_scene_t *scene;

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3BCDA5FD: /* asset */
				asset = collada_ctx_parser(ctx, collada_asset_t, node1);

				result->asset = asset;
				break;

			case 0xC8EC4766: /* library_cameras */
				library_cameras = collada_ctx_parser(ctx, collada_library_cameras_t, node1);

				ctnr_list_add(result->library_cameras_list, library_cameras);
				break;

			case 0x8630FB77: /* library_effects */
				library_effects = collada_ctx_parser(ctx, collada_library_effects_t, node1);

				ctnr_list_add(result->library_effects_list, library_effects);
				break;

			case 0x913819CF: /* library_geometries */
				library_geometries = collada_ctx_parser(ctx, collada_library_geometries_t, node1);

				ctnr_list_add(result->library_geometries_list, library_geometries);
				break;

			case 0x9EF17CD7: /* library_images */
				library_images = collada_ctx_parser(ctx, collada_library_images_t, node1);

				ctnr_list_add(result->library_images_list, library_images);
				break;

			case 0x7E936CE2: /* library_lights */
				library_lights = collada_ctx_parser(ctx, collada_library_lights_t, node1);

				ctnr_list_add(result->library_lights_list, library_lights);
				break;

			case 0x0C2EE9D6: /* library_materials */
				library_materials = collada_ctx_parser(ctx, collada_library_materials_t, node1);

				ctnr_list_add(result->library_materials_list, library_materials);
				break;

			case 0xE6379657: /* library_nodes */
				library_nodes = collada_ctx_parser(ctx, collada_library_nodes_t, node1);

				ctnr_list_add(result->library_nodes_list, library_nodes);
				break;

			case 0x922656B4: /* library_visual_scenes */
				library_visual_scenes = collada_ctx_parser(ctx, collada_library_visual_scenes_t, node1);

				ctnr_list_add(result->library_visual_scenes_list, library_visual_scenes);
				break;

			case 0x26EC4721: /* scene */
				scene = collada_ctx_parser(ctx, collada_scene_t, node1);

				result->scene = scene;
				break;

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool collada_check(struct collada_ctx_s *ctx, collada_t *collada)
{
	if(collada == NULL)
	{
		return false;
	}

	/**/

	printf("Check: collada_t\n");

	/**/

	return true;
}

/*-------------------------------------------------------------------------*/

void collada_dump(collada_ctx_t *ctx, collada_t *collada, int indent)
{
	if(collada == NULL)
	{
		return;
	}

	/**/

	int nr;

	collada_library_cameras_t *library_cameras;
	collada_library_effects_t *library_effects;
	collada_library_geometries_t *library_geometries;
	collada_library_images_t *library_images;
	collada_library_lights_t *library_lights;
	collada_library_materials_t *library_materials;
	collada_library_nodes_t *library_nodes;
	collada_library_visual_scenes_t *library_visual_scenes;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Colldada:\n");

	indent++;

	collada_ctx_dump(ctx, collada_asset_t, collada->asset, indent);

	ctnr_list_foreach(collada->library_cameras_list, library_cameras, nr) {
		collada_ctx_dump(ctx, collada_library_cameras_t, library_cameras, indent);
	}

	ctnr_list_foreach(collada->library_effects_list, library_effects, nr) {
		collada_ctx_dump(ctx, collada_library_effects_t, library_effects, indent);
	}

	ctnr_list_foreach(collada->library_geometries_list, library_geometries, nr) {
		collada_ctx_dump(ctx, collada_library_geometries_t, library_geometries, indent);
	}

	ctnr_list_foreach(collada->library_images_list, library_images, nr) {
		collada_ctx_dump(ctx, collada_library_images_t, library_images, indent);
	}

	ctnr_list_foreach(collada->library_lights_list, library_lights, nr) {
		collada_ctx_dump(ctx, collada_library_lights_t, library_lights, indent);
	}

	ctnr_list_foreach(collada->library_materials_list, library_materials, nr) {
		collada_ctx_dump(ctx, collada_library_materials_t, library_materials, indent);
	}

	ctnr_list_foreach(collada->library_nodes_list, library_nodes, nr) {
		collada_ctx_dump(ctx, collada_library_nodes_t, library_nodes, indent);
	}

	ctnr_list_foreach(collada->library_visual_scenes_list, library_visual_scenes, nr) {
		collada_ctx_dump(ctx, collada_library_visual_scenes_t, library_visual_scenes, indent);
	}

	collada_ctx_dump(ctx, collada_scene_t, collada->scene, indent);

	ctnr_list_foreach(collada->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

