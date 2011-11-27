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

coco_visual_scene_t *coco_visual_scene_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_visual_scene_t *result = coco_ctx_factory(ctx, coco_visual_scene_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_node_t *node;
	/* TODO coco_evaluate_scene_t *evaluate_scene;*/

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

			case 0xA173AB66: /* node */
				node = coco_ctx_parse(ctx, coco_node_t, node1);

				ctnr_list_add(result->node_list, node);
				break;

			case 0x9711B324: /* evaluate_scene */
				/* TODO evaluate_scene = coco_sevaluate_scene_parse(ctx, node1);	*/
				/* TODO									*/
				/* TODO ctnr_list_add(result->evaluate_scene, evaluate_scene);	*/
				goto __warning;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
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

void coco_visual_scene_dump(coco_ctx_t *ctx, coco_visual_scene_t *visual_scene, int indent)
{
	if(visual_scene == NULL) {
		return;
	}

	/**/

	int nr;

	coco_node_t *node;
	/* TODO coco_evaluate_scene_t *evaluate_scene;*/

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Visual scene:\n");

	indent++;

	if(visual_scene->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", visual_scene->id);
	}

	if(visual_scene->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", visual_scene->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, visual_scene->asset, indent);

	ctnr_list_foreach(visual_scene->node_list, node, nr) {
		coco_ctx_dump(ctx, coco_node_t, node, indent);
	}

	/* TODO ctnr_list_foreach(visual_scene->extra_list, evaluate_scene, nr) { 	*/
	/* TODO 	coco_evaluate_scene_dump(evaluate_scene, indent);		*/
	/* TODO }									*/

	ctnr_list_foreach(visual_scene->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

