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

coco_shininess_t *coco_shininess_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_shininess_t *result = coco_ctx_factory(ctx, coco_shininess_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_fx_common_float_t *flt;
	coco_fx_common_param_t *param;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x767C3C00: /* float */
				flt = coco_ctx_parse(ctx, coco_fx_common_float_t, node1);

				result->flt = flt;
				break;

			case 0x657C2B30: /* param */
				param = coco_ctx_parse(ctx, coco_fx_common_param_t, node1);

				ctnr_list_append(result->param_list, param);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_shininess_check(coco_ctx_t *ctx, coco_shininess_t *shininess)
{
	if(shininess == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_shininess_dump(coco_ctx_t *ctx, coco_shininess_t *shininess, int indent)
{
	if(shininess == NULL) {
		return;
	}

	/**/

	int nr;

	coco_fx_common_param_t *param;

	/**/

	COCO_DUMP_INDENT(indent, "Shininess:\n");

	indent++;

	coco_ctx_dump(ctx, coco_fx_common_float_t, shininess->flt, indent);

	ctnr_list_foreach(shininess->param_list, param, nr) {
		coco_ctx_dump(ctx, coco_fx_common_param_t, param, indent);
	}
}

/*-------------------------------------------------------------------------*/

