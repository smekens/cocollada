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
#include <stdlib.h>

#include "../../coco_internal.h"

/*-------------------------------------------------------------------------*/

coco_newparam_t *coco_newparam_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_newparam_t *result = coco_ctx_factory(ctx, coco_newparam_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_surface_t *surface;
	coco_sampler2D_t *sampler2D;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x6666F60A: /* surface */
				surface = coco_ctx_parse(ctx, coco_surface_t, node1);

				result->surface = surface;
				break;

			case 0xA0EAB93A: /* sampler2D */
				sampler2D = coco_ctx_parse(ctx, coco_sampler2D_t, node1);

				result->sampler2D = sampler2D;
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->sid);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_newparam_check(coco_ctx_t *ctx, coco_newparam_t *newparam)
{
	if(newparam == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_newparam_dump(coco_ctx_t *ctx, coco_newparam_t *newparam, int indent)
{
	if(newparam == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Newparam:\n");

	indent++;

	if(newparam->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", newparam->sid);
	}

	coco_ctx_dump(ctx, coco_surface_t, newparam->surface, indent);

	coco_ctx_dump(ctx, coco_sampler2D_t, newparam->sampler2D, indent);
}

/*-------------------------------------------------------------------------*/

