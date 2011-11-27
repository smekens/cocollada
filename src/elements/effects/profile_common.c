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

collada_profile_common_technique_t *collada_profile_common_technique_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_profile_common_technique_t *result = collada_ctx_factory(ctx, collada_profile_common_technique_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_image_t *image;
	collada_lambert_t *lambert;
	collada_phong_t *phong;

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "id", NULL);
	if(str != NULL) {
		result->id = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
	}
	
	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x585AC335: /* image */
				image = collada_ctx_parser(ctx, collada_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x72C2F08D: /* lambert */
				lambert = collada_ctx_parser(ctx, collada_lambert_t, node1);

				result->lambert = lambert;
				break;

			case 0x926D7556: /* phong */
				phong = collada_ctx_parser(ctx, collada_phong_t, node1);

				result->phong = phong;
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

void collada_profile_common_technique_dump(collada_ctx_t *ctx, collada_profile_common_technique_t *profile_common_technique, int indent)
{
	if(profile_common_technique == NULL) {
		return;
	}

	/**/

	int nr;

	collada_image_t *image;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique:\n");

	indent++;

	if(profile_common_technique->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", profile_common_technique->id);
	}

	if(profile_common_technique->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", profile_common_technique->sid);
	}

	ctnr_list_foreach(profile_common_technique->image_list, image, nr) {
		collada_ctx_dump(ctx, collada_image_t, image, indent);
	}

	collada_ctx_dump(ctx, collada_lambert_t, profile_common_technique->lambert, indent);

	collada_ctx_dump(ctx, collada_phong_t, profile_common_technique->phong, indent);

	ctnr_list_foreach(profile_common_technique->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

collada_profile_common_t *collada_profile_common_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_profile_common_t *result = collada_ctx_factory(ctx, collada_profile_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_image_t *image;
	collada_newparam_t *newparam;
	collada_profile_common_technique_t *technique;

	collada_extra_t *extra;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x585AC335: /* image */
				image = collada_ctx_parser(ctx, collada_image_t, node1);

				ctnr_list_add(result->image_list, image);
				break;

			case 0x39385D1A: /* newparam */
				newparam = collada_ctx_parser(ctx, collada_newparam_t, node1);

				ctnr_list_add(result->newparam_list, newparam);
				break;

			case 0x2477201A: /* technique */
				technique = collada_ctx_parser(ctx, collada_profile_common_technique_t, node1);

				result->technique = technique;
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

void collada_profile_common_dump(collada_ctx_t *ctx, collada_profile_common_t *profile_common, int indent)
{
	if(profile_common == NULL) {
		return;
	}

	/**/

	int nr;

	collada_image_t *image;
	collada_newparam_t *newparam;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Profile COMMON:\n");

	indent++;

	ctnr_list_foreach(profile_common->newparam_list, newparam, nr) {
		collada_ctx_dump(ctx, collada_newparam_t, newparam, indent);
	}

	ctnr_list_foreach(profile_common->image_list, image, nr) {
		collada_ctx_dump(ctx, collada_image_t, image, indent);
	}

	collada_ctx_dump(ctx, collada_profile_common_technique_t, profile_common->technique, indent);

	ctnr_list_foreach(profile_common->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

