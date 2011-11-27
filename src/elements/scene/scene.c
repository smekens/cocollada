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
#include <stdlib.h>

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_scene_t *coco_scene_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_scene_t *result = coco_ctx_factory(ctx, coco_scene_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_instance_visual_scene_t *instance_visual_scene;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x4149755F: /* instance_visual_scene */
				instance_visual_scene = coco_ctx_parse(ctx, coco_instance_visual_scene_t, node1);

				result->instance_visual_scene = instance_visual_scene;
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_scene_check(coco_ctx_t *ctx, coco_scene_t *scene)
{
	if(scene == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_scene_dump(coco_ctx_t *ctx, coco_scene_t *scene, int indent)
{
	if(scene == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Scene:\n");

	indent++;

	coco_ctx_dump(ctx, coco_instance_visual_scene_t, scene->instance_visual_scene, indent);

	ctnr_list_foreach(scene->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

