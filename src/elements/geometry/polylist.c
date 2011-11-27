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

collada_polylist_t *collada_polylist_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_polylist_t *result = collada_ctx_factory(ctx, collada_polylist_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_input_t *input;
	collada_vcount_t *vcount;
	collada_p_t *p;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = collada_ctx_strdup(ctx, str);
	}

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	str = YAXP_GET_STR_ATTR(node0, "material", NULL);
	if(str != NULL) {
		result->material = collada_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x9F642814: /* input */
				input = collada_ctx_parser(ctx, collada_input_t, node1);

				ctnr_list_add(result->input_list, input);
				break;

			case 0xED4611FC: /* vcount */
				vcount = collada_ctx_parser(ctx, collada_vcount_t, node1);

				result->vcount = vcount;
				break;

			case 0x64E723F2: /* p */
				p = collada_ctx_parser(ctx, collada_p_t, node1);

				result->p = p;
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

void collada_polylist_dump(collada_ctx_t *ctx, collada_polylist_t *polylist, int indent)
{
	if(polylist == NULL) {
		return;
	}

	/**/

	int nr;

	collada_input_t *input;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Polylist:\n");

	indent++;

	if(polylist->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", polylist->name);
	}

	if(polylist->count >= 0)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Count: %d\n", polylist->count);
	}

	if(polylist->material != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Material: %s\n", polylist->material);
	}

	ctnr_list_foreach(polylist->input_list, input, nr) {
		collada_ctx_dump(ctx, collada_input_t, input, indent);
	}

	collada_ctx_dump(ctx, collada_vcount_t, polylist->vcount, indent);

	collada_ctx_dump(ctx, collada_p_t, polylist->p, indent);

	ctnr_list_foreach(polylist->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

