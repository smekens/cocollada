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

collada_node_t *collada_node_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_node_t *result = collada_ctx_factory(ctx, collada_node_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_lookat_t *lookat;
	collada_matrix_t *matrix;
	collada_rotate_t *rotate;
	collada_scale_t *scale;
	/* TODO collada_skew_t *skew;*/
	collada_translate_t *translate;

	collada_instance_camera_t *instance_camera;
	/* TODO collada_instance_controller_t *instance_controller; */
	collada_instance_geometry_t *instance_geometry;
	collada_instance_light_t *instance_light;
	collada_instance_node_t *instance_node;

	collada_node_t *child;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "layer", NULL);
	if(str != NULL) {
		result->layer = collada_ctx_strdup(ctx, str);
	}

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

			case 0xEDE531F3: /* lookat */
				lookat = collada_ctx_parser(ctx, collada_lookat_t, node1);

				ctnr_list_add(result->lookat_list, lookat);
				break;

			case 0x26E42922: /* matrix */
				matrix = collada_ctx_parser(ctx, collada_matrix_t, node1);

				ctnr_list_add(result->matrix_list, matrix);
				break;

			case 0x7A097F9F: /* rotate */
				rotate = collada_ctx_parser(ctx, collada_rotate_t, node1);

				ctnr_list_add(result->rotate_list, rotate);
				break;

			case 0x47CD74C6: /* scale */
				scale = collada_ctx_parser(ctx, collada_scale_t, node1);

				ctnr_list_add(result->scale_list, scale);
				break;

			case 0x1DC7DF9C: /* skew */
				/* TODO skew = collada_skew_parser(ctx, node1);					*/
				/* TODO										*/
				/* TODO ctnr_list_add(result->skew_list, skew);					*/
				/* TODO break;									*/
				goto __warning;

			case 0x3FD64B97: /* translate */
				translate = collada_ctx_parser(ctx, collada_translate_t, node1);

				ctnr_list_add(result->translate_list, translate);
				break;

			case 0x08C881B5: /* instance_camera */
				instance_camera = collada_ctx_parser(ctx, collada_instance_camera_t, node1);

				ctnr_list_add(result->instance_camera_list, instance_camera);
				break;

			case 0xF386B9C6: /* instance_controller */
				/* TODO instance_controller = collada_instance_controller_parser(ctx, node1);	*/
				/* TODO										*/
				/* TODO ctnr_list_add(result->instance_controller_list, instance_controller);	*/
				/* TODO break;									*/
				goto __warning;

			case 0x0957AC9B: /* instance_geometry */
				instance_geometry = collada_ctx_parser(ctx, collada_instance_geometry_t, node1);

				ctnr_list_add(result->instance_geometry_list, instance_geometry);
				break;

			case 0x8ADC99D4: /* instance_light */
				instance_light = collada_ctx_parser(ctx, collada_instance_light_t, node1);

				ctnr_list_add(result->instance_light_list, instance_light);
				break;

			case 0xA1BF1129: /* instance_node */
				instance_node = collada_ctx_parser(ctx, collada_instance_node_t, node1);

				ctnr_list_add(result->instance_node_list, instance_node);
				break;

			case 0xA173AB66: /* node */
				child = collada_ctx_parser(ctx, collada_node_t, node1);

				ctnr_list_add(result->node_list, child);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = collada_ctx_parser(ctx, collada_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

__warning:		default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_node_dump(collada_ctx_t *ctx, collada_node_t *node, int indent)
{
	if(node == NULL) {
		return;
	}

	/**/

	int nr;

	collada_lookat_t *lookat;
	collada_matrix_t *matrix;
	collada_rotate_t *rotate;
	collada_scale_t *scale;
	/* TODO collada_skew_t *skew;*/
	collada_translate_t *translate;

	collada_instance_camera_t *instance_camera;
	/* TODO collada_instance_controller_t *instance_controller; */
	collada_instance_geometry_t *instance_geometry;
	collada_instance_light_t *instance_light;
	collada_instance_node_t *instance_node;

	collada_node_t *child;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Node:\n");

	indent++;

	if(node->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", node->id);
	}

	if(node->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", node->name);
	}

	if(node->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", node->sid);
	}

	if(node->type != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Type: %s\n", node->type);
	}

	if(node->layer != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Layer: %s\n", node->layer);
	}

	collada_ctx_dump(ctx, collada_asset_t, node->asset, indent);

	ctnr_list_foreach(node->lookat_list, lookat, nr) {
		collada_ctx_dump(ctx, collada_lookat_t, lookat, indent);
	}

	ctnr_list_foreach(node->matrix_list, matrix, nr) {
		collada_ctx_dump(ctx, collada_matrix_t, matrix, indent);
	}

	ctnr_list_foreach(node->rotate_list, rotate, nr) {
		collada_ctx_dump(ctx, collada_rotate_t, rotate, indent);
	}

	ctnr_list_foreach(node->scale_list, scale, nr) {
		collada_ctx_dump(ctx, collada_scale_t, scale, indent);
	}

	/* TODO ctnr_list_foreach(node->skew_list, skew, nr) {					*/
	/* TODO 	collada_skew_dump(skew, indent);					*/
	/* TODO }										*/

	ctnr_list_foreach(node->translate_list, translate, nr) {
		collada_ctx_dump(ctx, collada_translate_t, translate, indent);
	}

	ctnr_list_foreach(node->instance_camera_list, instance_camera, nr) {
		collada_ctx_dump(ctx, collada_instance_camera_t, instance_camera, indent);
	}

	/* TODO ctnr_list_foreach(node->instance_controller_list, instance_controller, nr) { 	*/
	/* TODO 	collada_instance_controller_dump(instance_controller, indent);		*/
	/* TODO }										*/

	ctnr_list_foreach(node->instance_geometry_list, instance_geometry, nr) {
		collada_ctx_dump(ctx, collada_instance_geometry_t, instance_geometry, indent);
	}

	ctnr_list_foreach(node->instance_light_list, instance_light, nr) {
		collada_ctx_dump(ctx, collada_instance_light_t, instance_light, indent);
	}

	ctnr_list_foreach(node->instance_node_list, instance_node, nr) {
		collada_ctx_dump(ctx, collada_instance_node_t, instance_node, indent);
	}

	ctnr_list_foreach(node->node_list, child, nr) {
		collada_ctx_dump(ctx, collada_node_t, child, indent);
	}

	ctnr_list_foreach(node->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

