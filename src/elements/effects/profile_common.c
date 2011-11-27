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

coco_profile_common_technique_t *coco_profile_common_technique_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_profile_common_technique_t *result = coco_ctx_factory(ctx, coco_profile_common_technique_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_image_t *image;
	coco_lambert_t *lambert;
	coco_phong_t *phong;

	coco_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = coco_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = coco_ctx_strdup(ctx, str);
	}
	
	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x585AC335: /* image */
				image = coco_ctx_parse(ctx, coco_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x72C2F08D: /* lambert */
				lambert = coco_ctx_parse(ctx, coco_lambert_t, node1);

				result->lambert = lambert;
				break;

			case 0x926D7556: /* phong */
				phong = coco_ctx_parse(ctx, coco_phong_t, node1);

				result->phong = phong;
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

bool coco_profile_common_technique_check(coco_ctx_t *ctx, coco_profile_common_technique_t *profile_common_technique)
{
	if(profile_common_technique == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_profile_common_technique_dump(coco_ctx_t *ctx, coco_profile_common_technique_t *profile_common_technique, int indent)
{
	if(profile_common_technique == NULL) {
		return;
	}

	/**/

	int nr;

	coco_image_t *image;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Technique:\n");

	indent++;

	if(profile_common_technique->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", profile_common_technique->id);
	}

	if(profile_common_technique->sid != NULL)
	{
		COCO_DUMP_INDENT(indent, "Sid: %s\n", profile_common_technique->sid);
	}

	ctnr_list_foreach(profile_common_technique->image_list, image, nr) {
		coco_ctx_dump(ctx, coco_image_t, image, indent);
	}

	coco_ctx_dump(ctx, coco_lambert_t, profile_common_technique->lambert, indent);

	coco_ctx_dump(ctx, coco_phong_t, profile_common_technique->phong, indent);

	ctnr_list_foreach(profile_common_technique->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

coco_profile_common_t *coco_profile_common_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_profile_common_t *result = coco_ctx_factory(ctx, coco_profile_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_image_t *image;
	coco_newparam_t *newparam;
	coco_profile_common_technique_t *technique;

	coco_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x585AC335: /* image */
				image = coco_ctx_parse(ctx, coco_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x39385D1A: /* newparam */
				newparam = coco_ctx_parse(ctx, coco_newparam_t, node1);

				ctnr_list_add(result->newparam_list, newparam);
				break;

			case 0x2477201A: /* technique */
				technique = coco_ctx_parse(ctx, coco_profile_common_technique_t, node1);

				result->technique = technique;
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

bool coco_profile_common_check(coco_ctx_t *ctx, coco_profile_common_t *profile_common)
{
	if(profile_common == NULL)
	{
		return false;
	}

	/**/

	bool result = true;

	/*-----------------------------------------------------------------*/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_profile_common_dump(coco_ctx_t *ctx, coco_profile_common_t *profile_common, int indent)
{
	if(profile_common == NULL) {
		return;
	}

	/**/

	int nr;

	coco_image_t *image;
	coco_newparam_t *newparam;

	coco_extra_t *extra;

	/**/

	COCO_DUMP_INDENT(indent, "Profile COMMON:\n");

	indent++;

	ctnr_list_foreach(profile_common->newparam_list, newparam, nr) {
		coco_ctx_dump(ctx, coco_newparam_t, newparam, indent);
	}

	ctnr_list_foreach(profile_common->image_list, image, nr) {
		coco_ctx_dump(ctx, coco_image_t, image, indent);
	}

	coco_ctx_dump(ctx, coco_profile_common_technique_t, profile_common->technique, indent);

	ctnr_list_foreach(profile_common->extra_list, extra, nr) {
		coco_ctx_dump(ctx, coco_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

