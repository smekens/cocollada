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

#include "../../collada_internal.h"

/*-------------------------------------------------------------------------*/

collada_technique_core_t *collada_technique_core_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_technique_core_t *result = collada_ctx_factory(ctx, collada_technique_core_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "profile", NULL);
	if(str != NULL) {
		result->profile = collada_ctx_strdup(ctx, str);
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_technique_core_dump(collada_ctx_t *ctx, collada_technique_core_t *technique_core, int indent)
{
	if(technique_core == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique (core):\n");

	indent++;

	if(technique_core->profile != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Profile: %s\n", technique_core->profile);
	}
}

/*-------------------------------------------------------------------------*/

