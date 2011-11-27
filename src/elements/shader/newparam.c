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

collada_newparam_t *collada_newparam_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_newparam_t *result = collada_ctx_factory(ctx, collada_newparam_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_surface_t *surface;
	collada_sampler2D_t *sampler2D;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x6666F60A: /* surface */
				surface = collada_ctx_parser(ctx, collada_surface_t, node1);

				result->surface = surface;
				break;

			case 0xA0EAB93A: /* sampler2D */
				sampler2D = collada_ctx_parser(ctx, collada_sampler2D_t, node1);

				result->sampler2D = sampler2D;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	collada_ctx_register(ctx, result, result->sid);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_newparam_dump(collada_ctx_t *ctx, collada_newparam_t *newparam, int indent)
{
	if(newparam == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Newparam:\n");

	indent++;

	if(newparam->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", newparam->sid);
	}

	collada_ctx_dump(ctx, collada_surface_t, newparam->surface, indent);

	collada_ctx_dump(ctx, collada_sampler2D_t, newparam->sampler2D, indent);
}

/*-------------------------------------------------------------------------*/

