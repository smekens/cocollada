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

coco_lambert_t *coco_lambert_parse(coco_ctx_t *ctx, yaxp_node_t *node0)
{
	coco_lambert_t *result = coco_ctx_factory(ctx, coco_lambert_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	coco_emission_t *emission;
	coco_ambient_fx_t *ambient;
	coco_diffuse_t *diffuse;
	coco_reflective_t *reflective;
	coco_reflectivity_t *reflectivity;
	coco_transparent_t *transparent;
	coco_transparency_t *transparency;
	coco_index_of_refraction_t *index_of_refraction;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x67E8B767: /* emission */
				emission = coco_ctx_parse(ctx, coco_emission_t, node1);

				result->emission = emission;
				break;

			case 0xC0799E13: /* ambient */
				ambient = coco_ctx_parse(ctx, coco_ambient_fx_t, node1);

				result->ambient = ambient;
				break;

			case 0x31C098DC: /* diffuse */
				diffuse = coco_ctx_parse(ctx, coco_diffuse_t, node1);

				result->diffuse = diffuse;
				break;

			case 0x6C0FF7D6: /* reflective */
				reflective = coco_ctx_parse(ctx, coco_reflective_t, node1);

				result->reflective = reflective;
				break;

			case 0x10187EF2: /* reflectivity */
				reflectivity = coco_ctx_parse(ctx, coco_reflectivity_t, node1);

				result->reflectivity = reflectivity;
				break;

			case 0xADCDAC65: /* transparent */
				transparent = coco_ctx_parse(ctx, coco_transparent_t, node1);

				result->transparent = transparent;
				break;

			case 0x93A230A0: /* transparency */
				transparency = coco_ctx_parse(ctx, coco_transparency_t, node1);

				result->transparency = transparency;
				break;

			case 0xCC908315: /* index_of_refraction */
				index_of_refraction = coco_ctx_parse(ctx, coco_index_of_refraction_t, node1);

				result->index_of_refraction = index_of_refraction;
				break;

			default:
				coco_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void coco_lambert_dump(coco_ctx_t *ctx, coco_lambert_t *lambert, int indent)
{
	if(lambert == NULL) {
		return;
	}

	/**/

	COCO_DUMP_INDENT(indent, "Lambert:\n");

	indent++;

	coco_ctx_dump(ctx, coco_emission_t, lambert->emission, indent);

	coco_ctx_dump(ctx, coco_ambient_fx_t, lambert->ambient, indent);

	coco_ctx_dump(ctx, coco_diffuse_t, lambert->diffuse, indent);

	coco_ctx_dump(ctx, coco_reflective_t, lambert->reflective, indent);

	coco_ctx_dump(ctx, coco_reflectivity_t, lambert->reflectivity, indent);

	coco_ctx_dump(ctx, coco_transparent_t, lambert->transparent, indent);

	coco_ctx_dump(ctx, coco_transparency_t, lambert->transparency, indent);

	coco_ctx_dump(ctx, coco_index_of_refraction_t, lambert->index_of_refraction, indent);
}

/*-------------------------------------------------------------------------*/

