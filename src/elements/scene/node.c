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

coco_node_t *coco_node_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_node_t *result = coco_ctx_factory(ctx, coco_node_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_lookat_t *lookat;
	coco_matrix_t *matrix;
	coco_rotate_t *rotate;
	coco_scale_t *scale;
	/* TODO coco_skew_t *skew;*/
	coco_translate_t *translate;

	coco_instance_camera_t *instance_camera;
	/* TODO coco_instance_controller_t *instance_controller; */
	coco_instance_geometry_t *instance_geometry;
	coco_instance_light_t *instance_light;
	coco_instance_node_t *instance_node;

	coco_node_t *child;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "layer", NULL);
	if(str != NULL) {
		result->layer = coco_ctx_strdup(ctx, str);
	}

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

			case 0xEDE531F3: /* lookat */
				lookat = coco_ctx_parse(ctx, coco_lookat_t, node1);

				ctnr_list_append(result->lookat_list, lookat);
				break;

			case 0x26E42922: /* matrix */
				matrix = coco_ctx_parse(ctx, coco_matrix_t, node1);

				ctnr_list_append(result->matrix_list, matrix);
				break;

			case 0x7A097F9F: /* rotate */
				rotate = coco_ctx_parse(ctx, coco_rotate_t, node1);

				ctnr_list_append(result->rotate_list, rotate);
				break;

			case 0x47CD74C6: /* scale */
				scale = coco_ctx_parse(ctx, coco_scale_t, node1);

				ctnr_list_append(result->scale_list, scale);
				break;

			case 0x1DC7DF9C: /* skew */
				/* TODO skew = coco_skew_parse(ctx, node1);					*/
				/* TODO										*/
				/* TODO ctnr_list_append(result->skew_list, skew);					*/
				/* TODO break;									*/
				goto __warning;

			case 0x3FD64B97: /* translate */
				translate = coco_ctx_parse(ctx, coco_translate_t, node1);

				ctnr_list_append(result->translate_list, translate);
				break;

			case 0x08C881B5: /* instance_camera */
				instance_camera = coco_ctx_parse(ctx, coco_instance_camera_t, node1);

				ctnr_list_append(result->instance_camera_list, instance_camera);
				break;

			case 0xF386B9C6: /* instance_controller */
				/* TODO instance_controller = coco_instance_controller_parse(ctx, node1);	*/
				/* TODO										*/
				/* TODO ctnr_list_append(result->instance_controller_list, instance_controller);	*/
				/* TODO break;									*/
				goto __warning;

			case 0x0957AC9B: /* instance_geometry */
				instance_geometry = coco_ctx_parse(ctx, coco_instance_geometry_t, node1);

				ctnr_list_append(result->instance_geometry_list, instance_geometry);
				break;

			case 0x8ADC99D4: /* instance_light */
				instance_light = coco_ctx_parse(ctx, coco_instance_light_t, node1);

				ctnr_list_append(result->instance_light_list, instance_light);
				break;

			case 0xA1BF1129: /* instance_node */
				instance_node = coco_ctx_parse(ctx, coco_instance_node_t, node1);

				ctnr_list_append(result->instance_node_list, instance_node);
				break;

			case 0xA173AB66: /* node */
				child = coco_ctx_parse(ctx, coco_node_t, node1);

				ctnr_list_append(result->node_list, child);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_append(result->extra_list, extra);
				break;

__warning:		default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_node_check(coco_ctx_t *ctx, coco_node_t *node)
{
	if(node == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_node_dump(coco_ctx_t *ctx, coco_node_t *node, int indent)
{
	if(node == NULL) {
		return;
	}

	/**/

	int nr;

	coco_lookat_t *lookat;
	coco_matrix_t *matrix;
	coco_rotate_t *rotate;
	coco_scale_t *scale;
	/* TODO coco_skew_t *skew;*/
	coco_translate_t *translate;

	coco_instance_camera_t *instance_camera;
	/* TODO coco_instance_controller_t *instance_controller; */
	coco_instance_geometry_t *instance_geometry;
	coco_instance_light_t *instance_light;
	coco_instance_node_t *instance_node;

	coco_node_t *child;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Node:\n");

	indent++;

	if(node->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", node->id);
	}

	if(node->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", node->name);
	}

	if(node->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", node->sid);
	}

	if(node->type != NULL)
	{
		COCO_DUMP_INDENT(indent, "Type: %s\n", node->type);
	}

	if(node->layer != NULL)
	{
		COCO_DUMP_INDENT(indent, "Layer: %s\n", node->layer);
	}

	coco_ctx_dump(ctx, coco_asset_t, node->asset, indent);

	ctnr_list_foreach(node->lookat_list, lookat, nr) {
		coco_ctx_dump(ctx, coco_lookat_t, lookat, indent);
	}

	ctnr_list_foreach(node->matrix_list, matrix, nr) {
		coco_ctx_dump(ctx, coco_matrix_t, matrix, indent);
	}

	ctnr_list_foreach(node->rotate_list, rotate, nr) {
		coco_ctx_dump(ctx, coco_rotate_t, rotate, indent);
	}

	ctnr_list_foreach(node->scale_list, scale, nr) {
		coco_ctx_dump(ctx, coco_scale_t, scale, indent);
	}

	/* TODO ctnr_list_foreach(node->skew_list, skew, nr) {					*/
	/* TODO 	coco_skew_dump(skew, indent);					*/
	/* TODO }										*/

	ctnr_list_foreach(node->translate_list, translate, nr) {
		coco_ctx_dump(ctx, coco_translate_t, translate, indent);
	}

	ctnr_list_foreach(node->instance_camera_list, instance_camera, nr) {
		coco_ctx_dump(ctx, coco_instance_camera_t, instance_camera, indent);
	}

	/* TODO ctnr_list_foreach(node->instance_controller_list, instance_controller, nr) { 	*/
	/* TODO 	coco_instance_controller_dump(instance_controller, indent);		*/
	/* TODO }										*/

	ctnr_list_foreach(node->instance_geometry_list, instance_geometry, nr) {
		coco_ctx_dump(ctx, coco_instance_geometry_t, instance_geometry, indent);
	}

	ctnr_list_foreach(node->instance_light_list, instance_light, nr) {
		coco_ctx_dump(ctx, coco_instance_light_t, instance_light, indent);
	}

	ctnr_list_foreach(node->instance_node_list, instance_node, nr) {
		coco_ctx_dump(ctx, coco_instance_node_t, instance_node, indent);
	}

	ctnr_list_foreach(node->node_list, child, nr) {
		coco_ctx_dump(ctx, coco_node_t, child, indent);
	}

	ctnr_list_foreach(node->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

