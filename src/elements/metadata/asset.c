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

coco_asset_contributor_t *coco_asset_contributor_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_asset_contributor_t *result = coco_ctx_factory(ctx, coco_asset_contributor_t);

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
				result->author = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xC34433D7: /* authoring_tool */
				result->authoring_tool = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xD595913E: /* comments */
				result->comments = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x634090B6: /* copyright */
				result->copyright = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x3B2CD8DF: /* source_data */
				result->source_data = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_asset_contributor_dump(coco_ctx_t *ctx, coco_asset_contributor_t *asset_contributor, int indent)
{
	if(asset_contributor == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Contributor:\n");

	indent++;

	if(asset_contributor->author != NULL)
	{
		COCO_DUMP_INDENT(indent, "Author: %s\n", asset_contributor->author);
	}

	if(asset_contributor->authoring_tool != NULL)
	{
		COCO_DUMP_INDENT(indent, "Authoring tool: %s\n", asset_contributor->authoring_tool);
	}

	if(asset_contributor->comments != NULL)
	{
		COCO_DUMP_INDENT(indent, "Comments: %s\n", asset_contributor->comments);
	}

	if(asset_contributor->copyright != NULL)
	{
		COCO_DUMP_INDENT(indent, "Copyright: %s\n", asset_contributor->copyright);
	}

	if(asset_contributor->source_data != NULL)
	{
		COCO_DUMP_INDENT(indent, "Source data: %s\n", asset_contributor->source_data);
	}
}

/*-------------------------------------------------------------------------*/

coco_asset_t *coco_asset_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_asset_t *result = coco_ctx_factory(ctx, coco_asset_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_contributor_t *contributor;
	coco_unit_t *unit;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x3C495F8A: /* contributor */
				contributor = coco_ctx_parse(ctx, coco_asset_contributor_t, node1);

				ctnr_list_add(result->contributor_list, contributor);
				break;

			case 0x3DC2C173: /* created */
				result->created = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xA9F1C391: /* keywords */
				result->keywords = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0xD00CAE58: /* modified */
				result->modified = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x00EF2F8E: /* revision */
				result->revision = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x03D23F47: /* subject */
				result->subject = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x7BD255E9: /* title */
				result->title = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			case 0x4F6F4960: /* unit */
				unit = coco_ctx_parse(ctx, coco_unit_t, node1);

				result->unit = unit;
				break;

			case 0x62952635: /* up_axis */
				result->up_axis = coco_ctx_strdup(ctx, YAXP_GET_STR_TEXT(node1, "-- ??? --"));
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_asset_dump(coco_ctx_t *ctx, coco_asset_t *asset, int indent)
{
	if(asset == NULL) {
		return;
	}

	/**/

	int nr;

	coco_asset_contributor_t *contributor;

	/**/

	COCO_DUMP_INDENT(indent, "Asset:\n");

	indent++;

	ctnr_list_foreach(asset->contributor_list, contributor, nr) {
		coco_ctx_dump(ctx, coco_asset_contributor_t, contributor, indent);
	}

	if(asset->created != NULL)
	{
		COCO_DUMP_INDENT(indent, "Created: %s\n", asset->created);
	}

	if(asset->keywords != NULL)
	{
		COCO_DUMP_INDENT(indent, "Keywords: %s\n", asset->keywords);
	}

	if(asset->modified != NULL)
	{
		COCO_DUMP_INDENT(indent, "Modified: %s\n", asset->modified);
	}

	if(asset->revision != NULL)
	{
		COCO_DUMP_INDENT(indent, "Revision: %s\n", asset->revision);
	}

	if(asset->subject != NULL)
	{
		COCO_DUMP_INDENT(indent, "Subject: %s\n", asset->subject);
	}

	if(asset->title != NULL)
	{
		COCO_DUMP_INDENT(indent, "Title: %s\n", asset->title);
	}

	coco_ctx_dump(ctx, coco_unit_t, asset->unit, indent);

	if(asset->up_axis != NULL)
	{
		COCO_DUMP_INDENT(indent, "Up axis: %s\n", asset->up_axis);
	}
}

/*-------------------------------------------------------------------------*/

