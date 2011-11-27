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

collada_library_nodes_t *collada_library_nodes_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_library_nodes_t *result = collada_ctx_factory(ctx, collada_library_nodes_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_node_t *node;

	collada_extra_t *extra;

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

void collada_library_nodes_dump(collada_ctx_t *ctx, collada_library_nodes_t *library_nodes, int indent)
{
	if(library_nodes == NULL) {
		return;
	}

	/**/

	int nr1;

	collada_node_t *node;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Library nodes:\n");

	indent++;

	collada_ctx_dump(ctx, collada_asset_t, library_nodes->asset, indent);

	ctnr_list_foreach(library_nodes->node_list, node, nr1) {
		collada_ctx_dump(ctx, collada_node_t, node, indent);
	}

	ctnr_list_foreach(library_nodes->extra_list, extra, nr1) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

