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

coco_triangles_t *coco_triangles_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_triangles_t *result = coco_ctx_factory(ctx, coco_triangles_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_input_t *input;
	coco_p_t *p;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	result->count = YAXP_GET_INT_ATTR(node0, "count", "-1");

	str = YAXP_GET_STR_ATTR(node0, "material", NULL);
	if(str != NULL) {
		result->material = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x9F642814: /* input */
				input = coco_ctx_parse(ctx, coco_input_t, node1);

				ctnr_list_add(result->input_list, input);
				break;

			case 0x64E723F2: /* p */
				p = coco_ctx_parse(ctx, coco_p_t, node1);

				result->p = p;
				break;

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

bool coco_triangles_check(coco_ctx_t *ctx, coco_triangles_t *triangles)
{
	if(triangles == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_triangles_dump(coco_ctx_t *ctx, coco_triangles_t *triangles, int indent)
{
	if(triangles == NULL) {
		return;
	}

	/**/

	int nr;

	coco_input_t *input;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Triangles:\n");

	indent++;

	if(triangles->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", triangles->name);
	}

	if(triangles->count >= 0)
	{
		COCO_DUMP_INDENT(indent, "Count: %d\n", triangles->count);
	}

	if(triangles->material != NULL)
	{
		COCO_DUMP_INDENT(indent, "Material: %s\n", triangles->material);
	}

	ctnr_list_foreach(triangles->input_list, input, nr) {
		coco_ctx_dump(ctx, coco_input_t, input, indent);
	}

	coco_ctx_dump(ctx, coco_p_t, triangles->p, indent);

	ctnr_list_foreach(triangles->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

