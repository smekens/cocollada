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

collada_visual_scene_t *collada_visual_scene_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_visual_scene_t *result = collada_ctx_factory(ctx, collada_visual_scene_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_node_t *node;
	/* TODO collada_evaluate_scene_t *evaluate_scene;*/

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

			case 0xA173AB66: /* node */
				node = collada_ctx_parser(ctx, collada_node_t, node1);

				ctnr_list_add(result->node_list, node);
				break;

			case 0x9711B324: /* evaluate_scene */
				/* TODO evaluate_scene = collada_sevaluate_scene_parser(ctx, node1);	*/
				/* TODO									*/
				/* TODO ctnr_list_add(result->evaluate_scene, evaluate_scene);	*/
				goto __warning;

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

void collada_visual_scene_dump(collada_ctx_t *ctx, collada_visual_scene_t *visual_scene, int indent)
{
	if(visual_scene == NULL) {
		return;
	}

	/**/

	int nr;

	collada_node_t *node;
	/* TODO collada_evaluate_scene_t *evaluate_scene;*/

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Visual scene:\n");

	indent++;

	if(visual_scene->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", visual_scene->id);
	}

	if(visual_scene->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", visual_scene->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, visual_scene->asset, indent);

	ctnr_list_foreach(visual_scene->node_list, node, nr) {
		collada_ctx_dump(ctx, collada_node_t, node, indent);
	}

	/* TODO ctnr_list_foreach(visual_scene->extra_list, evaluate_scene, nr) { 	*/
	/* TODO 	collada_evaluate_scene_dump(evaluate_scene, indent);		*/
	/* TODO }									*/

	ctnr_list_foreach(visual_scene->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

