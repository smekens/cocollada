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

collada_asset_contributor_t *collada_asset_contributor_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_asset_contributor_t *result = collada_ctx_factory(ctx, collada_asset_contributor_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xA7137143: /* author */
				result->author = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xC34433D7: /* authoring_tool */
				result->authoring_tool = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xD595913E: /* comments */
				result->comments = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x634090B6: /* copyright */
				result->copyright = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x3B2CD8DF: /* source_data */
				result->source_data = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_asset_contributor_dump(collada_ctx_t *ctx, collada_asset_contributor_t *asset_contributor, int indent)
{
	if(asset_contributor == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Contributor:\n");

	indent++;

	if(asset_contributor->author != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Author: %s\n", asset_contributor->author);
	}

	if(asset_contributor->authoring_tool != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Authoring tool: %s\n", asset_contributor->authoring_tool);
	}

	if(asset_contributor->comments != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Comments: %s\n", asset_contributor->comments);
	}

	if(asset_contributor->copyright != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Copyright: %s\n", asset_contributor->copyright);
	}

	if(asset_contributor->source_data != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Source data: %s\n", asset_contributor->source_data);
	}
}

/*-------------------------------------------------------------------------*/

collada_asset_t *collada_asset_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_asset_t *result = collada_ctx_factory(ctx, collada_asset_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_contributor_t *contributor;
	collada_unit_t *unit;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3C495F8A: /* contributor */
				contributor = collada_ctx_parser(ctx, collada_asset_contributor_t, node1);

				ctnr_list_add(result->contributor_list, contributor);
				break;

			case 0x3DC2C173: /* created */
				result->created = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xA9F1C391: /* keywords */
				result->keywords = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xD00CAE58: /* modified */
				result->modified = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x00EF2F8E: /* revision */
				result->revision = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x03D23F47: /* subject */
				result->subject = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x7BD255E9: /* title */
				result->title = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x4F6F4960: /* unit */
				unit = collada_ctx_parser(ctx, collada_unit_t, node1);

				result->unit = unit;
				break;

			case 0x62952635: /* up_axis */
				result->up_axis = collada_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_asset_dump(collada_ctx_t *ctx, collada_asset_t *asset, int indent)
{
	if(asset == NULL) {
		return;
	}

	/**/

	int nr;

	collada_asset_contributor_t *contributor;

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Asset:\n");

	indent++;

	ctnr_list_foreach(asset->contributor_list, contributor, nr) {
		collada_ctx_dump(ctx, collada_asset_contributor_t, contributor, indent);
	}

	if(asset->created != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Created: %s\n", asset->created);
	}

	if(asset->keywords != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Keywords: %s\n", asset->keywords);
	}

	if(asset->modified != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Modified: %s\n", asset->modified);
	}

	if(asset->revision != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Revision: %s\n", asset->revision);
	}

	if(asset->subject != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Subject: %s\n", asset->subject);
	}

	if(asset->title != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Title: %s\n", asset->title);
	}

	collada_ctx_dump(ctx, collada_unit_t, asset->unit, indent);

	if(asset->up_axis != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Up axis: %s\n", asset->up_axis);
	}
}

/*-------------------------------------------------------------------------*/

