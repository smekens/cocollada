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

collada_phong_t *collada_phong_parser(collada_ctx_t *ctx, yaxp_node_t *node0)
{
	collada_phong_t *result = collada_ctx_factory(ctx, collada_phong_t);

	result->base.line = node0->line;
	result->base.column = node0->column;

	/**/

	collada_emission_t *emission;
	collada_ambient_fx_t *ambient;
	collada_diffuse_t *diffuse;
	collada_specular_t *specular;
	collada_shininess_t *shininess;
	collada_reflective_t *reflective;
	collada_reflectivity_t *reflectivity;
	collada_transparent_t *transparent;
	collada_transparency_t *transparency;
	collada_index_of_refraction_t *index_of_refraction;

	/**/

	int nr1;
	yaxp_node_t * node1;

	yaxp_foreach_node(node0, node1, nr1)
	{
		switch(ctnr_hash(node1->name))
		{
			case 0x67E8B767: /* emission */
				emission = collada_ctx_parser(ctx, collada_emission_t, node1);

				result->emission = emission;
				break;

			case 0xC0799E13: /* ambient */
				ambient = collada_ctx_parser(ctx, collada_ambient_fx_t, node1);

				result->ambient = ambient;
				break;

			case 0x31C098DC: /* diffuse */
				diffuse = collada_ctx_parser(ctx, collada_diffuse_t, node1);

				result->diffuse = diffuse;
				break;

			case 0x12C2C291: /* specular */
				specular = collada_ctx_parser(ctx, collada_specular_t, node1);

				result->specular = specular;
				break;

			case 0x098722AD: /* shininess */
				shininess = collada_ctx_parser(ctx, collada_shininess_t, node1);

				result->shininess = shininess;
				break;

			case 0x6C0FF7D6: /* reflective */
				reflective = collada_ctx_parser(ctx, collada_reflective_t, node1);

				result->reflective = reflective;
				break;

			case 0x10187EF2: /* reflectivity */
				reflectivity = collada_ctx_parser(ctx, collada_reflectivity_t, node1);

				result->reflectivity = reflectivity;
				break;

			case 0xADCDAC65: /* transparent */
				transparent = collada_ctx_parser(ctx, collada_transparent_t, node1);

				result->transparent = transparent;
				break;

			case 0x93A230A0: /* transparency */
				transparency = collada_ctx_parser(ctx, collada_transparency_t, node1);

				result->transparency = transparency;
				break;

			case 0xCC908315: /* index_of_refraction */
				index_of_refraction = collada_ctx_parser(ctx, collada_index_of_refraction_t, node1);

				result->index_of_refraction = index_of_refraction;
				break;

			default:
				collada_log(ctx, TYPE_WARNING, result->base.line, result->base.column, "node not supported <%s>\n", node1->name);
		}
	}

	/**/

	return result;
}

/*-------------------------------------------------------------------------*/

void collada_phong_dump(collada_ctx_t *ctx, collada_phong_t *phong, int indent)
{
	if(phong == NULL) {
		return;
	}

	/**/

	COLLADA_DUMP_INDENT(indent);
	printf("Phong:\n");

	indent++;

	collada_ctx_dump(ctx, collada_emission_t, phong->emission, indent);

	collada_ctx_dump(ctx, collada_ambient_fx_t, phong->ambient, indent);

	collada_ctx_dump(ctx, collada_diffuse_t, phong->diffuse, indent);

	collada_ctx_dump(ctx, collada_specular_t, phong->specular, indent);

	collada_ctx_dump(ctx, collada_shininess_t, phong->shininess, indent);

	collada_ctx_dump(ctx, collada_reflective_t, phong->reflective, indent);

	collada_ctx_dump(ctx, collada_reflectivity_t, phong->reflectivity, indent);

	collada_ctx_dump(ctx, collada_transparent_t, phong->transparent, indent);

	collada_ctx_dump(ctx, collada_transparency_t, phong->transparency, indent);

	collada_ctx_dump(ctx, collada_index_of_refraction_t, phong->index_of_refraction, indent);
}

/*-------------------------------------------------------------------------*/

