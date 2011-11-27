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

collada_extra_t *collada_extra_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_extra_t *result = collada_ctx_factory(ctx, collada_extra_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;
	collada_technique_core_t *technique_core;

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

	str = YAXP_GET_STR_ATTR(node0, "type", NULL);
	if(str != NULL) {
		result->type = collada_ctx_strdup(ctx, str);
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

			case 0x2477201A: /* technique */
				technique_core = collada_ctx_parser(ctx, collada_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique_core);
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_extra_dump(collada_ctx_t *ctx, collada_extra_t *extra, int indent)
{
	if(extra == NULL) {
		return;
	}

	/**/

	int nr1;

	collada_technique_core_t *technique_core;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Extra:\n");

	indent++;

	if(extra->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", extra->id);
	}

	if(extra->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", extra->name);
	}

	if(extra->type != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Type: %s\n", extra->type);
	}

	collada_ctx_dump(ctx, collada_asset_t, extra->asset, indent);

	ctnr_list_foreach(extra->technique_list, technique_core, nr1) {
		collada_ctx_dump(ctx, collada_technique_core_t, technique_core, indent);
	}
}

/*-------------------------------------------------------------------------*/

