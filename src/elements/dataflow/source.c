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

coco_source_technique_common_t *coco_source_technique_common_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_source_technique_common_t *result = coco_ctx_factory(ctx, coco_source_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_accessor_t *accessor;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xFA9B3539: /* accessor */
				accessor = coco_ctx_parse(ctx, coco_accessor_t, node1);

				result->accessor = accessor;
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_source_technique_common_dump(coco_ctx_t *ctx, coco_source_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Technique common:\n");

	indent++;

	coco_ctx_dump(ctx, coco_accessor_t, technique_common->accessor, indent);
}

/*-------------------------------------------------------------------------*/

coco_source_t *coco_source_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_source_t *result = coco_ctx_factory(ctx, coco_source_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_asset_t *asset;

	/* TODO struct coco_IDREF_array_s *IDREF_array;*/
	/* TODO struct coco_Name_array_s *Name_array;*/
	/* TODO struct coco_bool_array_s *bool_array;*/
	struct coco_float_array_s *float_array;
	/* TODO struct coco_int_array_s *int_array;*/

	struct coco_source_technique_common_s *technique_common;

	/* TODO struct coco_technique_s *technique;*/

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

			case 0x7927A8D1: /* IDREF_array */
				/* TODO IDREF_array = coco_IDREF_array_parse(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->IDREF_array = IDREF_array;				*/
				goto __warning;

			case 0xD7A95F52: /* Name_array */
				/* TODO Name_array = coco_Name_array_parse(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->Name_array = Name_array;				*/
				goto __warning;

			case 0x54996949: /* bool_array */
				/* TODO bool_array = coco_bool_array_parse(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->bool_array = bool_array;				*/
				goto __warning;

			case 0xFACE8000: /* float_array */
				float_array = coco_ctx_parse(ctx, coco_float_array_t, node1);

				result->float_array = float_array;
				break;

			case 0xCF29E070: /* int_array */
				/* TODO int_array = coco_int_array_parse(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->int_array = int_array;				*/
				goto __warning;

			case 0x8BA567DA: /* technique_common */
				technique_common = coco_ctx_parse(ctx, coco_source_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				/* TODO technique = coco_technique_parse(ctx, node1);		*/
				/* TODO									*/
				/* TODO ctnr_list_add(result->technique_list, technique);		*/
				goto __warning;

__warning:		default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	coco_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_source_dump(coco_ctx_t *ctx, coco_source_t *source, int indent)
{
	if(source == NULL) {
		return;
	}

	/**/

	/* TODO int nr;*/

	/* TODO coco_technique_t *technique;*/

	/**/

	COCO_DUMP_INDENT(indent, "Source:\n");

	indent++;

	if(source->id != NULL)
	{
		COCO_DUMP_INDENT(indent, "Id: %s\n", source->id);
	}

	if(source->name != NULL)
	{
		COCO_DUMP_INDENT(indent, "name: %s\n", source->name);
	}

	coco_ctx_dump(ctx, coco_asset_t, source->asset, indent);

	/* TODO coco_IDREF_array_dump(source->IDREF_array, indent);*/
	/* TODO coco_Name_array_dump(source->Name_array, indent);*/
	/* TODO coco_bool_array_dump(source->bool_array, indent);*/
	coco_ctx_dump(ctx, coco_float_array_t, source->float_array, indent);
	/* TODO coco_int_array_dump(source->int_array, indent);*/

	coco_ctx_dump(ctx, coco_source_technique_common_t, source->technique_common, indent);

	/* TODO ctnr_list_foreach(source->technique_list, technique, nr) {	*/
	/* TODO 	coco_technique_dump(technique, indent);		*/
	/* TODO }								*/
}

/*-------------------------------------------------------------------------*/

