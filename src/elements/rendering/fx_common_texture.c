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

coco_fx_common_texture_t *coco_fx_common_texture_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_fx_common_texture_t *result = coco_ctx_factory(ctx, coco_fx_common_texture_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "texture", NULL);
	if(str != NULL) {
		result->texture = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "texcoord", NULL);
	if(str != NULL) {
		result->texcoord = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_add(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_fx_common_texture_dump(coco_ctx_t *ctx, coco_fx_common_texture_t *fx_common_texture, int indent)
{
	if(fx_common_texture == NULL) {
		return;
	}

	/**/

	int nr;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Texture:\n");

	indent++;

	if(fx_common_texture->texture != NULL)
	{
		COCO_DUMP_INDENT(indent, "Texture: %s\n", fx_common_texture->texture);
	}

	if(fx_common_texture->texcoord != NULL)
	{
		COCO_DUMP_INDENT(indent, "Texcoord: %s\n", fx_common_texture->texcoord);
	}

	ctnr_list_foreach(fx_common_texture->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

