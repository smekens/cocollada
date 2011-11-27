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

collada_light_technique_common_t *collada_light_technique_common_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_light_technique_common_t *result = collada_ctx_factory(ctx, collada_light_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_ambient_core_t *ambient;
	collada_directional_t *directional;
	collada_spot_t *spot;
	collada_point_t *point;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xC0799E13: /* ambient */
				ambient = collada_ctx_parser(ctx, collada_ambient_core_t, node1);

				result->ambient = ambient;
				break;

			case 0xCCEF7FC9: /* directional */
				directional = collada_ctx_parser(ctx, collada_directional_t, node1);

				result->directional = directional;
				break;

			case 0x89C926D7: /* spot */
				spot = collada_ctx_parser(ctx, collada_spot_t, node1);

				result->spot = spot;
				break;

			case 0xF42D9D0C: /* point */
				point = collada_ctx_parser(ctx, collada_point_t, node1);

				result->point = point;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_light_technique_common_dump(collada_ctx_t *ctx, collada_light_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique common:\n");

	indent++;

	collada_ctx_dump(ctx, collada_ambient_core_t, technique_common->ambient, indent);

	collada_ctx_dump(ctx, collada_directional_t, technique_common->directional, indent);

	collada_ctx_dump(ctx, collada_spot_t, technique_common->spot, indent);

	collada_ctx_dump(ctx, collada_point_t, technique_common->point, indent);
}

/*-------------------------------------------------------------------------*/

collada_light_t *collada_light_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_light_t *result = collada_ctx_factory(ctx, collada_light_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_light_technique_common_t *technique_common;
	collada_technique_core_t *technique;

	collada_extra_t *extra;

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

			case 0x8BA567DA: /* technique_common */
				technique_common = collada_ctx_parser(ctx, collada_light_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				technique = collada_ctx_parser(ctx, collada_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique);
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

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_light_dump(collada_ctx_t *ctx, collada_light_t *light, int indent)
{
	if(light == NULL) {
		return;
	}

	/**/

	int nr;

	collada_technique_core_t *technique;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Light:\n");

	indent++;

	if(light->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", light->id);
	}

	if(light->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", light->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, light->asset, indent);

	collada_ctx_dump(ctx, collada_light_technique_common_t, light->technique_common, indent);

	ctnr_list_foreach(light->technique_list, technique, nr) {
		collada_ctx_dump(ctx, collada_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(light->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

