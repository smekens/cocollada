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

coco_instance_geometry_t *coco_instance_geometry_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_instance_geometry_t *result = coco_ctx_factory(ctx, coco_instance_geometry_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_bind_material_t *bind_material;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "url", NULL);
	if(str != NULL) {
		result->url = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
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
			case 0x5C4D3625: /* bind_material */
				bind_material = coco_ctx_parse(ctx, coco_bind_material_t, node1);

				ctnr_list_append(result->bind_material_list, bind_material);
				break;

			case 0x2FAFA2F4: /* extra */
				extra = coco_ctx_parse(ctx, coco_extra_t, node1);

				ctnr_list_append(result->extra_list, extra);
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_instance_geometry_check(coco_ctx_t *ctx, coco_instance_geometry_t *instance_geometry)
{
	if(instance_geometry == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_instance_geometry_dump(coco_ctx_t *ctx, coco_instance_geometry_t *instance_geometry, int indent)
{
	if(instance_geometry == NULL) {
		return;
	}

	/**/

	int nr;

	coco_bind_material_t *bind_material;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Instance geometry:\n");

	indent++;

	if(instance_geometry->url != NULL)
	{
		COCO_DUMP_INDENT(indent, "Url: %s\n", instance_geometry->url);
	}

	if(instance_geometry->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", instance_geometry->sid);
	}

	if(instance_geometry->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", instance_geometry->name);
	}

	ctnr_list_foreach(instance_geometry->bind_material_list, bind_material, nr) {
		coco_ctx_dump(ctx, coco_bind_material_t, bind_material, indent);
	}

	ctnr_list_foreach(instance_geometry->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

