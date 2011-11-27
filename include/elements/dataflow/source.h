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

#ifndef __COCO_SOURCE_H
#define __COCO_SOURCE_H

/*-------------------------------------------------------------------------*/

typedef struct coco_source_technique_common_s
{
	struct coco_base_s base;

	struct coco_source_technique_common_s *prev, *next;

	/**/

	struct coco_accessor_s *accessor;

} coco_source_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_source_s
{
	struct coco_base_s base;

	struct coco_source_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_asset_s *asset;

	/* TODO struct coco_IDREF_array_s *IDREF_array;*/
	/* TODO struct coco_Name_array_s *Name_array;*/
	/* TODO struct coco_bool_array_s *bool_array;*/
	struct coco_float_array_s *float_array;
	/* TODO struct coco_int_array_s *int_array;*/

	struct coco_source_technique_common_s *technique_common;

	/* TODO struct coco_technique_s *technique_list;*/

} coco_source_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_source_technique_common_s *coco_source_technique_common_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_source_technique_common_check(struct coco_ctx_s *, struct coco_source_technique_common_s *);

DLL_PUBLIC void coco_source_technique_common_dump(struct coco_ctx_s *, struct coco_source_technique_common_s *, int);

/**/

DLL_PUBLIC struct coco_source_s *coco_source_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_source_check(struct coco_ctx_s *, struct coco_source_s *);

DLL_PUBLIC void coco_source_dump(struct coco_ctx_s *, struct coco_source_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_SOURCE_H */

/*-------------------------------------------------------------------------*/

