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

#include <stdio.h>
#include <string.h>

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_collada_t *coco_collada_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_collada_t *result = coco_ctx_factory(ctx, coco_collada_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_library_cameras_t *library_cameras;
	coco_library_effects_t *library_effects;
	coco_library_geometries_t *library_geometries;
	coco_library_images_t *library_images;
	coco_library_lights_t *library_lights;
	coco_library_materials_t *library_materials;
	coco_library_nodes_t *library_nodes;
	coco_library_visual_scenes_t *library_visual_scenes;
	coco_scene_t *scene;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3BCDA5FD: /* asset */
				asset = coco_ctx_parse(ctx, coco_asset_t, node1);

				result->asset = asset;
				break;

			case 0xC8EC4766: /* library_cameras */
				library_cameras = coco_ctx_parse(ctx, coco_library_cameras_t, node1);

				ctnr_list_append(result->library_cameras_list, library_cameras);
				break;

			case 0x8630FB77: /* library_effects */
				library_effects = coco_ctx_parse(ctx, coco_library_effects_t, node1);

				ctnr_list_append(result->library_effects_list, library_effects);
				break;

			case 0x913819CF: /* library_geometries */
				library_geometries = coco_ctx_parse(ctx, coco_library_geometries_t, node1);

				ctnr_list_append(result->library_geometries_list, library_geometries);
				break;

			case 0x9EF17CD7: /* library_images */
				library_images = coco_ctx_parse(ctx, coco_library_images_t, node1);

				ctnr_list_append(result->library_images_list, library_images);
				break;

			case 0x7E936CE2: /* library_lights */
				library_lights = coco_ctx_parse(ctx, coco_library_lights_t, node1);

				ctnr_list_append(result->library_lights_list, library_lights);
				break;

			case 0x0C2EE9D6: /* library_materials */
				library_materials = coco_ctx_parse(ctx, coco_library_materials_t, node1);

				ctnr_list_append(result->library_materials_list, library_materials);
				break;

			case 0xE6379657: /* library_nodes */
				library_nodes = coco_ctx_parse(ctx, coco_library_nodes_t, node1);

				ctnr_list_append(result->library_nodes_list, library_nodes);
				break;

			case 0x922656B4: /* library_visual_scenes */
				library_visual_scenes = coco_ctx_parse(ctx, coco_library_visual_scenes_t, node1);

				ctnr_list_append(result->library_visual_scenes_list, library_visual_scenes);
				break;

			case 0x26EC4721: /* scene */
				scene = coco_ctx_parse(ctx, coco_scene_t, node1);

				result->scene = scene;
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_append(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_collada_check(struct coco_ctx_s *ctx, coco_collada_t *collada)
{
	if(collada == NULL)
	{
		return false;
	}

	/**/

	printf("Check: coco_collada_t\n");

	/**/

	return true;
}

/*-------------------------------------------------------------------------*/

void coco_collada_dump(coco_ctx_t *ctx, coco_collada_t *collada, int indent)
{
	if(collada == NULL)
	{
		return;
	}

	/**/

	int nr;

	coco_library_cameras_t *library_cameras;
	coco_library_effects_t *library_effects;
	coco_library_geometries_t *library_geometries;
	coco_library_images_t *library_images;
	coco_library_lights_t *library_lights;
	coco_library_materials_t *library_materials;
	coco_library_nodes_t *library_nodes;
	coco_library_visual_scenes_t *library_visual_scenes;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Colldada:\n");

	indent++;

	coco_ctx_dump(ctx, coco_asset_t, collada->asset, indent);

	ctnr_list_foreach(collada->library_cameras_list, library_cameras, nr) {
		coco_ctx_dump(ctx, coco_library_cameras_t, library_cameras, indent);
	}

	ctnr_list_foreach(collada->library_effects_list, library_effects, nr) {
		coco_ctx_dump(ctx, coco_library_effects_t, library_effects, indent);
	}

	ctnr_list_foreach(collada->library_geometries_list, library_geometries, nr) {
		coco_ctx_dump(ctx, coco_library_geometries_t, library_geometries, indent);
	}

	ctnr_list_foreach(collada->library_images_list, library_images, nr) {
		coco_ctx_dump(ctx, coco_library_images_t, library_images, indent);
	}

	ctnr_list_foreach(collada->library_lights_list, library_lights, nr) {
		coco_ctx_dump(ctx, coco_library_lights_t, library_lights, indent);
	}

	ctnr_list_foreach(collada->library_materials_list, library_materials, nr) {
		coco_ctx_dump(ctx, coco_library_materials_t, library_materials, indent);
	}

	ctnr_list_foreach(collada->library_nodes_list, library_nodes, nr) {
		coco_ctx_dump(ctx, coco_library_nodes_t, library_nodes, indent);
	}

	ctnr_list_foreach(collada->library_visual_scenes_list, library_visual_scenes, nr) {
		coco_ctx_dump(ctx, coco_library_visual_scenes_t, library_visual_scenes, indent);
	}

	coco_ctx_dump(ctx, coco_scene_t, collada->scene, indent);

	ctnr_list_foreach(collada->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

