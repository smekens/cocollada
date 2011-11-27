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

collada_material_t *collada_material_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_material_t *result = collada_ctx_factory(ctx, collada_material_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_instance_effect_t *instance_effect;

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

			case 0x9FE65945: /* instance_effect */
				instance_effect = collada_ctx_parser(ctx, collada_instance_effect_t, node1);

				result->instance_effect = instance_effect;
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

void collada_material_dump(collada_ctx_t *ctx, collada_material_t *material, int indent)
{
	if(material == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Material:\n");

	indent++;

	if(material->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", material->id);
	}

	if(material->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", material->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, material->asset, indent);

	collada_ctx_dump(ctx, collada_instance_effect_t, material->instance_effect, indent);

	ctnr_list_foreach(material->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/
