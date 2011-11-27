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

coco_effect_t *coco_effect_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_effect_t *result = coco_ctx_factory(ctx, coco_effect_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	coco_image_t *image;
	coco_newparam_t *newparam;
	coco_profile_common_t *profile_common;

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

			case 0x585AC335: /* image */
				image = coco_ctx_parse(ctx, coco_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x39385D1A: /* newparam */
				newparam = coco_ctx_parse(ctx, coco_newparam_t, node1);

				ctnr_list_add(result->newparam_list, newparam);
				break;

			case 0xC723EC8D: /* profile_COMMON */
				profile_common = coco_ctx_parse(ctx, coco_profile_common_t, node1);

				ctnr_list_add(result->profile_common_list, profile_common);
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

void coco_effect_dump(coco_ctx_t *ctx, coco_effect_t *effect, int indent)
{
	if(effect == NULL) {
		return;
	}

	/**/

	int nr;

	coco_image_t *image;
	coco_newparam_t *newparam;
	coco_profile_common_t *profile_common;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Effect:\n");

	indent++;

	if(effect->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", effect->id);
	}

	if(effect->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "Name: %s\n", effect->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, effect->asset, indent);

	ctnr_list_foreach(effect->image_list, image, nr) {
		coco_ctx_dump(ctx, coco_image_t, image, indent);
	}

	ctnr_list_foreach(effect->newparam_list, newparam, nr) {
		coco_ctx_dump(ctx, coco_newparam_t, newparam, indent);
	}

	ctnr_list_foreach(effect->profile_common_list, profile_common, nr) {
		coco_ctx_dump(ctx, coco_profile_common_t, profile_common, indent);
	}

	ctnr_list_foreach(effect->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

