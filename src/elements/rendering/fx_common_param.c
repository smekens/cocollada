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

coco_fx_common_param_t *coco_fx_common_param_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_fx_common_param_t *result = coco_ctx_factory(ctx, coco_fx_common_param_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "ref", NULL);
	if(str != NULL) {
		result->ref = coco_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_fx_common_param_dump(coco_ctx_t *ctx, coco_fx_common_param_t *fx_common_param, int indent)
{
	if(fx_common_param == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Param (FX):\n");

	indent++;

	if(fx_common_param->ref != NULL)
	{
		COCO_DUMP_INDENT(indent, "Ref: %s\n", fx_common_param->ref);
	}
}

/*-------------------------------------------------------------------------*/

