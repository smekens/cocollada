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
#include <stdlib.h>

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_scene_t *collada_scene_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_scene_t *result = collada_ctx_factory(ctx, collada_scene_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_instance_visual_scene_t *instance_visual_scene;

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x4149755F: /* instance_visual_scene */
				instance_visual_scene = collada_ctx_parser(ctx, collada_instance_visual_scene_t, node1);

				result->instance_visual_scene = instance_visual_scene;
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

void collada_scene_dump(collada_ctx_t *ctx, collada_scene_t *scene, int indent)
{
	if(scene == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Scene:\n");

	indent++;

	collada_ctx_dump(ctx, collada_instance_visual_scene_t, scene->instance_visual_scene, indent);

	ctnr_list_foreach(scene->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

