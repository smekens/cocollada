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

collada_perspective_t *collada_perspective_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_perspective_t *result = collada_ctx_factory(ctx, collada_perspective_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	result->xfov = -9999.0f;
	result->yfov = -9999.0f;
	result->aspect_ratio = -9999.0f;
	result->znear = -9999.0f;
	result->zfar = -9999.0f;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x39507E72: /* xfov */
				result->xfov = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x125C3615: /* yfov */
				result->yfov = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x7BB27608: /* aspect_ratio */
				result->aspect_ratio = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0xF4C1F012: /* znear */
				result->znear = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0xA55F0E06: /* zfar */
				result->zfar = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_perspective_dump(collada_ctx_t *ctx, collada_perspective_t *perspective, int indent)
{
	if(perspective == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("perspective:\n");

	indent++;

	if(perspective->xfov != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Xfov: %f\n", perspective->xfov);
	}

	if(perspective->yfov != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Yfov: %f\n", perspective->yfov);
	}

	if(perspective->aspect_ratio != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Aspect ratio: %f\n", perspective->aspect_ratio);
	}

	if(perspective->znear != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Znear: %f\n", perspective->znear);
	}

	if(perspective->zfar != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Zfar: %f\n", perspective->zfar);
	}
}

/*-------------------------------------------------------------------------*/

