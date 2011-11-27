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

coco_light_technique_common_t *coco_light_technique_common_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_light_technique_common_t *result = coco_ctx_factory(ctx, coco_light_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_ambient_core_t *ambient;
	coco_directional_t *directional;
	coco_spot_t *spot;
	coco_point_t *point;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xC0799E13: /* ambient */
				ambient = coco_ctx_parse(ctx, coco_ambient_core_t, node1);

				result->ambient = ambient;
				break;

			case 0xCCEF7FC9: /* directional */
				directional = coco_ctx_parse(ctx, coco_directional_t, node1);

				result->directional = directional;
				break;

			case 0x89C926D7: /* spot */
				spot = coco_ctx_parse(ctx, coco_spot_t, node1);

				result->spot = spot;
				break;

			case 0xF42D9D0C: /* point */
				point = coco_ctx_parse(ctx, coco_point_t, node1);

				result->point = point;
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_light_technique_common_check(coco_ctx_t *ctx, coco_light_technique_common_t *light_technique_common)
{
	if(light_technique_common == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_light_technique_common_dump(coco_ctx_t *ctx, coco_light_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Technique common:\n");

	indent++;

	coco_ctx_dump(ctx, coco_ambient_core_t, technique_common->ambient, indent);

	coco_ctx_dump(ctx, coco_directional_t, technique_common->directional, indent);

	coco_ctx_dump(ctx, coco_spot_t, technique_common->spot, indent);

	coco_ctx_dump(ctx, coco_point_t, technique_common->point, indent);
}

/*-------------------------------------------------------------------------*/

coco_light_t *coco_light_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_light_t *result = coco_ctx_factory(ctx, coco_light_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_light_technique_common_t *technique_common;
	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "name", NULL);
	if(str != NULL) {
		result->name = coco_ctx_strdup(ctx, str);
	}

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3BCDA5FD: /* asset */
				asset = coco_ctx_parse(ctx, coco_asset_t, node1);

				result->asset = asset;
				break;

			case 0x8BA567DA: /* technique_common */
				technique_common = coco_ctx_parse(ctx, coco_light_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				technique = coco_ctx_parse(ctx, coco_technique_core_t, node1);

				ctnr_list_add(result->technique_list, technique);
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

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_light_check(coco_ctx_t *ctx, coco_light_t *light)
{
	if(light == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_light_dump(coco_ctx_t *ctx, coco_light_t *light, int indent)
{
	if(light == NULL) {
		return;
	}

	/**/

	int nr;

	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Light:\n");

	indent++;

	if(light->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", light->id);
	}

	if(light->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", light->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, light->asset, indent);

	coco_ctx_dump(ctx, coco_light_technique_common_t, light->technique_common, indent);

	ctnr_list_foreach(light->technique_list, technique, nr) {
		coco_ctx_dump(ctx, coco_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(light->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

