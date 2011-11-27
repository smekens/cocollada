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

#ifndef __COLLADA_SOURCE_H
#define __COLLADA_SOURCE_H

/*-------------------------------------------------------------------------*/

typedef struct collada_source_technique_common_s
{
	struct collada_base_s base;

	struct collada_source_technique_common_s *prev, *next;

	/**/

	struct collada_accessor_s *accessor;

} collada_source_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_source_s
{
	struct collada_base_s base;

	struct collada_source_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct collada_asset_s *asset;

	/* TODO struct collada_IDREF_array_s *IDREF_array;*/
	/* TODO struct collada_Name_array_s *Name_array;*/
	/* TODO struct collada_bool_array_s *bool_array;*/
	struct collada_float_array_s *float_array;
	/* TODO struct collada_int_array_s *int_array;*/

	struct collada_source_technique_common_s *technique_common;

	/* TODO struct collada_technique_s *technique_list;*/

} collada_source_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct collada_source_technique_common_s *collada_source_technique_common_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_source_technique_common_check(struct collada_ctx_s *, struct collada_source_technique_common_s *);

DLL_PUBLIC void collada_source_technique_common_dump(struct collada_ctx_s *, struct collada_source_technique_common_s *, int);

/**/

DLL_PUBLIC struct collada_source_s *collada_source_parse(struct collada_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool collada_source_check(struct collada_ctx_s *, struct collada_source_s *);

DLL_PUBLIC void collada_source_dump(struct collada_ctx_s *, struct collada_source_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_SOURCE_H */

/*-------------------------------------------------------------------------*/

