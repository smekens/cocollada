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

coco_optics_technique_common_t *coco_optics_technique_common_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_optics_technique_common_t *result = coco_ctx_factory(ctx, coco_optics_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_orthographic_t *orthographic;
	coco_perspective_t *perspective;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x5780895E: /* orthographic */
				orthographic = coco_ctx_parse(ctx, coco_orthographic_t, node1);

				result->orthographic = orthographic;
				break;

			case 0xCAFFBEBC: /* perspective */
				perspective = coco_ctx_parse(ctx, coco_perspective_t, node1);

				result->perspective = perspective;
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_optics_technique_common_check(coco_ctx_t *ctx, coco_optics_technique_common_t *optics_technique_common)
{
	if(optics_technique_common == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_optics_technique_common_dump(coco_ctx_t *ctx, coco_optics_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Technique common:\n");

	indent++;

	coco_ctx_dump(ctx, coco_orthographic_t, technique_common->orthographic, indent);

	coco_ctx_dump(ctx, coco_perspective_t, technique_common->perspective, indent);
}

/*-------------------------------------------------------------------------*/

coco_optics_t *coco_optics_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_optics_t *result = coco_ctx_factory(ctx, coco_optics_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_optics_technique_common_t *technique_common;
	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x8BA567DA: /* technique_common */
				technique_common = coco_ctx_parse(ctx, coco_optics_technique_common_t, node1);

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

	return result;
}

/*-------------------------------------------------------------------------*/

bool coco_optics_check(coco_ctx_t *ctx, coco_optics_t *optics)
{
	if(optics == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_optics_dump(coco_ctx_t *ctx, coco_optics_t *optics, int indent)
{
	if(optics == NULL) {
		return;
	}

	/**/

	int nr;

	coco_technique_core_t *technique;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Optics:\n");

	indent++;

	coco_ctx_dump(ctx, coco_optics_technique_common_t, optics->technique_common, indent);

	ctnr_list_foreach(optics->technique_list, technique, nr) {
		coco_ctx_dump(ctx, coco_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(optics->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

