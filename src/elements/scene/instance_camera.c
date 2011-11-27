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

collada_instance_camera_t *collada_instance_camera_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_instance_camera_t *result = collada_ctx_factory(ctx, collada_instance_camera_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_extra_t *extra;

	/**/

	const char *str;

	str = YAXP_GET_STR_ATTR(node0, "url", NULL);
	if(str != NULL) {
		result->url = collada_ctx_strdup(ctx, str);
	}

	str = YAXP_GET_STR_ATTR(node0, "sid", NULL);
	if(str != NULL) {
		result->sid = collada_ctx_strdup(ctx, str);
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

void collada_instance_camera_dump(collada_ctx_t *ctx, collada_instance_camera_t *instance_camera, int indent)
{
	if(instance_camera == NULL) {
		return;
	}

	/**/

	int nr;

	collada_extra_t *extra;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Instance camera:\n");

	indent++;

	if(instance_camera->url != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Url: %s\n", instance_camera->url);
	}

	if(instance_camera->sid != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Sid: %s\n", instance_camera->sid);
	}

	if(instance_camera->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Name: %s\n", instance_camera->name);
	}

	ctnr_list_foreach(instance_camera->extra_list, extra, nr) {
		collada_ctx_dump(ctx, collada_extra_t, extra, indent);
	}
}

/*-------------------------------------------------------------------------*/

