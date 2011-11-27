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

coco_technique_core_t *coco_technique_core_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_technique_core_t *result = coco_ctx_factory(ctx, coco_technique_core_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "profile", NULL);
	if(str != NULL) {
		result->profile = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_technique_core_dump(coco_ctx_t *ctx, coco_technique_core_t *technique_core, int indent)
{
	if(technique_core == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Technique (core):\n");

	indent++;

	if(technique_core->profile != NULL)
	{
		COCO_DUMP_INDENT(indent, "Profile: %s\n", technique_core->profile);
	}
}

/*-------------------------------------------------------------------------*/

