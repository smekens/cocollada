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

collada_optics_technique_common_t *collada_optics_technique_common_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_optics_technique_common_t *result = collada_ctx_factory(ctx, collada_optics_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_orthographic_t *orthographic;
	collada_perspective_t *perspective;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x5780895E: /* orthographic */
				orthographic = collada_ctx_parser(ctx, collada_orthographic_t, node1);

				result->orthographic = orthographic;
				break;

			case 0xCAFFBEBC: /* perspective */
				perspective = collada_ctx_parser(ctx, collada_perspective_t, node1);

				result->perspective = perspective;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_optics_technique_common_dump(collada_ctx_t *ctx, collada_optics_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique common:\n");

	indent++;

	collada_ctx_dump(ctx, collada_orthographic_t, technique_common->orthographic, indent);

	collada_ctx_dump(ctx, collada_perspective_t, technique_common->perspective, indent);
}

/*-------------------------------------------------------------------------*/

collada_optics_t *collada_optics_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_optics_t *result = collada_ctx_factory(ctx, collada_optics_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_optics_technique_common_t *technique_common;
	collada_technique_core_t *technique;

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x8BA567DA: /* technique_common */
				technique_common = collada_ctx_parser(ctx, collada_optics_technique_common_t, node1);

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

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_optics_dump(collada_ctx_t *ctx, collada_optics_t *optics, int indent)
{
	if(optics == NULL) {
		return;
	}

	/**/

	int nr;

	collada_technique_core_t *technique;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Optics:\n");

	indent++;

	collada_ctx_dump(ctx, collada_optics_technique_common_t, optics->technique_common, indent);

	ctnr_list_foreach(optics->technique_list, technique, nr) {
		collada_ctx_dump(ctx, collada_technique_core_t, technique, indent);
	}

	ctnr_list_foreach(optics->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

