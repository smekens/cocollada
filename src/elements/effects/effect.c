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

collada_effect_t *collada_effect_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_effect_t *result = collada_ctx_factory(ctx, collada_effect_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	collada_image_t *image;
	collada_newparam_t *newparam;
	collada_profile_common_t *profile_common;

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

			case 0x585AC335: /* image */
				image = collada_ctx_parser(ctx, collada_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x39385D1A: /* newparam */
				newparam = collada_ctx_parser(ctx, collada_newparam_t, node1);

				ctnr_list_add(result->newparam_list, newparam);
				break;

			case 0xC723EC8D: /* profile_COMMON */
				profile_common = collada_ctx_parser(ctx, collada_profile_common_t, node1);

				ctnr_list_add(result->profile_common_list, profile_common);
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

void collada_effect_dump(collada_ctx_t *ctx, collada_effect_t *effect, int indent)
{
	if(effect == NULL) {
		return;
	}

	/**/

	int nr;

	collada_image_t *image;
	collada_newparam_t *newparam;
	collada_profile_common_t *profile_common;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Effect:\n");

	indent++;

	if(effect->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", effect->id);
	}

	if(effect->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", effect->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, effect->asset, indent);

	ctnr_list_foreach(effect->image_list, image, nr) {
		collada_ctx_dump(ctx, collada_image_t, image, indent);
	}

	ctnr_list_foreach(effect->newparam_list, newparam, nr) {
		collada_ctx_dump(ctx, collada_newparam_t, newparam, indent);
	}

	ctnr_list_foreach(effect->profile_common_list, profile_common, nr) {
		collada_ctx_dump(ctx, collada_profile_common_t, profile_common, indent);
	}

	ctnr_list_foreach(effect->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

