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

collada_source_technique_common_t *collada_source_technique_common_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_source_technique_common_t *result = collada_ctx_factory(ctx, collada_source_technique_common_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_accessor_t *accessor;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0xFA9B3539: /* accessor */
				accessor = collada_ctx_parser(ctx, collada_accessor_t, node1);

				result->accessor = accessor;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_source_technique_common_dump(collada_ctx_t *ctx, collada_source_technique_common_t *technique_common, int indent)
{
	if(technique_common == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Technique common:\n");

	indent++;

	collada_ctx_dump(ctx, collada_accessor_t, technique_common->accessor, indent);
}

/*-------------------------------------------------------------------------*/

collada_source_t *collada_source_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_source_t *result = collada_ctx_factory(ctx, collada_source_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_asset_t *asset;

	/* TODO struct collada_IDREF_array_s *IDREF_array;*/
	/* TODO struct collada_Name_array_s *Name_array;*/
	/* TODO struct collada_bool_array_s *bool_array;*/
	struct collada_float_array_s *float_array;
	/* TODO struct collada_int_array_s *int_array;*/

	struct collada_source_technique_common_s *technique_common;

	/* TODO struct collada_technique_s *technique;*/

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

			case 0x7927A8D1: /* IDREF_array */
				/* TODO IDREF_array = collada_IDREF_array_parser(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->IDREF_array = IDREF_array;				*/
				goto __warning;

			case 0xD7A95F52: /* Name_array */
				/* TODO Name_array = collada_Name_array_parser(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->Name_array = Name_array;				*/
				goto __warning;

			case 0x54996949: /* bool_array */
				/* TODO bool_array = collada_bool_array_parser(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->bool_array = bool_array;				*/
				goto __warning;

			case 0xFACE8000: /* float_array */
				float_array = collada_ctx_parser(ctx, collada_float_array_t, node1);

				result->float_array = float_array;
				break;

			case 0xCF29E070: /* int_array */
				/* TODO int_array = collada_int_array_parser(ctx, node1);		*/
				/* TODO									*/
				/* TODO result->int_array = int_array;				*/
				goto __warning;

			case 0x8BA567DA: /* technique_common */
				technique_common = collada_ctx_parser(ctx, collada_source_technique_common_t, node1);

				result->technique_common = technique_common;
				break;

			case 0x2477201A: /* technique */
				/* TODO technique = collada_technique_parser(ctx, node1);		*/
				/* TODO									*/
				/* TODO ctnr_list_add(result->technique_list, technique);		*/
				goto __warning;

__warning:		default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	collada_ctx_register(ctx, result, result->id);

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_source_dump(collada_ctx_t *ctx, collada_source_t *source, int indent)
{
	if(source == NULL) {
		return;
	}

	/**/

	/* TODO int nr;*/

	/* TODO collada_technique_t *technique;*/

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Source:\n");

	indent++;

	if(source->id != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("Id: %s\n", source->id);
	}

	if(source->name != NULL)
	{
		COLLADA_DUMP_INDENT(indent);
		printf("name: %s\n", source->name);
	}

	collada_ctx_dump(ctx, collada_asset_t, source->asset, indent);

	/* TODO collada_IDREF_array_dump(source->IDREF_array, indent);*/
	/* TODO collada_Name_array_dump(source->Name_array, indent);*/
	/* TODO collada_bool_array_dump(source->bool_array, indent);*/
	collada_ctx_dump(ctx, collada_float_array_t, source->float_array, indent);
	/* TODO collada_int_array_dump(source->int_array, indent);*/

	collada_ctx_dump(ctx, collada_source_technique_common_t, source->technique_common, indent);

	/* TODO ctnr_list_foreach(source->technique_list, technique, nr) {	*/
	/* TODO 	collada_technique_dump(technique, indent);		*/
	/* TODO }								*/
}

/*-------------------------------------------------------------------------*/

