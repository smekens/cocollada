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

collada_spot_t *collada_spot_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_spot_t *result = collada_ctx_factory(ctx, collada_spot_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_color_t *color;

	/**/

	result->constant_attenuation = -9999.0f;
	result->linear_attenuation = -9999.0f;
	result->quadratic_attenuation = -9999.0f;

	result->falloff_angle = -9999.0f;
	result->falloff_exponent = -9999.0f;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x2802D184: /* color */
				color = collada_ctx_parser(ctx, collada_color_t, node1);

				result->color = color;
				break;

			case 0x65E5140C: /* constant_attenuation */
				result->constant_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0xA4ABA437: /* linear_attenuation */
				result->linear_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x9F6FF61E: /* quadratic_attenuation */
				result->quadratic_attenuation = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x806EA124: /* falloff_angle */
				result->falloff_angle = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			case 0x615C9BCB: /* falloff_exponent */
				result->falloff_exponent = YAXP_GET_FLT_TEXT(node1, "-9999.0f");
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_spot_dump(collada_ctx_t *ctx, collada_spot_t *spot, int indent)
{
	if(spot == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Spot:\n");

	indent++;

	collada_ctx_dump(ctx, collada_color_t, spot->color, indent);

	if(spot->constant_attenuation != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Constant attenuation: %f\n", spot->constant_attenuation);
	}

	if(spot->linear_attenuation != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Linear attenuation: %f\n", spot->linear_attenuation);
	}

	if(spot->quadratic_attenuation != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Quadratic attenuation: %f\n", spot->quadratic_attenuation);
	}

	if(spot->falloff_angle != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Falloff angle: %f\n", spot->falloff_angle);
	}

	if(spot->falloff_exponent != -9999.0f)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Falloff exponent: %f\n", spot->falloff_exponent);
	}
}

/*-------------------------------------------------------------------------*/

