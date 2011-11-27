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

coco_extra_t *coco_extra_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_extra_t *result = coco_ctx_factory(ctx, coco_extra_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;
	coco_technique_core_t *technique_core;

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

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = coco_ctx_strdup(ctx, str);
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

			case 0x2477201A: /* technique */
				technique_core = coco_ctx_parse(ctx, coco_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique_core);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_extra_check(coco_ctx_t *ctx, coco_extra_t *extra)
{
	if(extra == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_extra_dump(coco_ctx_t *ctx, coco_extra_t *extra, int indent)
{
	if(extra == NULL) {
		return;
	}

	/**/

	int nr1;

	coco_technique_core_t *technique_core;

	/**/

	COCO_DUMP_INDENT(indent, "Extra:\n");

	indent++;

	if(extra->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", extra->id);
	}

	if(extra->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", extra->name);
	}

	if(extra->type != NULL)
	{
		COCO_DUMP_INDENT(indent, "Type: %s\n", extra->type);
	}

	coco_ctx_dump(ctx, coco_asset_t, extra->asset, indent);

	ctnr_list_foreach(extra->technique_list, technique_core, nr1) {
		coco_ctx_dump(ctx, coco_technique_core_t, technique_core, indent);
	}
}

/*-------------------------------------------------------------------------*/

