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

collada_fx_common_texture_t *collada_fx_common_texture_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_fx_common_texture_t *result = collada_ctx_factory(ctx, collada_fx_common_texture_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "texture", NULL);
	if(str != NULL) {
		result->texture = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "texcoord", NULL);
	if(str != NULL) {
		result->texcoord = collada_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
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

void collada_fx_common_texture_dump(collada_ctx_t *ctx, collada_fx_common_texture_t *fx_common_texture, int indent)
{
	if(fx_common_texture == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Texture:\n");

	indent++;

	if(fx_common_texture->texture != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Texture: %s\n", fx_common_texture->texture);
	}

	if(fx_common_texture->texcoord != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Texcoord: %s\n", fx_common_texture->texcoord);
	}

	ctnr_list_foreach(fx_common_texture->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

