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

#ifndef __COCO_BIND_MATERIAL_H
#define __COCO_BIND_MATERIAL_H

/*-------------------------------------------------------------------------*/

typedef struct coco_bind_material_param_s
{
	struct coco_base_s base;

	struct coco_bind_material_param_s *prev, *next;

	/**/

	const char *name;
	const char *sid;
	const char *semantic;
	const char *type;

} coco_bind_material_param_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_bind_material_technique_common_s
{
	struct coco_base_s base;

	struct coco_bind_material_technique_common_s *prev, *next;

	/**/

	struct coco_instance_material_s *instance_material_list;

} coco_bind_material_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_bind_material_s
{
	struct coco_base_s base;

	struct coco_bind_material_s *prev, *next;

	/**/

	struct coco_bind_material_param_s *param_list;

	struct coco_bind_material_technique_common_s *technique_common;
	
	struct coco_technique_core_s *technique_list;

	struct coco_extra_s *extra_list;

} coco_bind_material_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_bind_material_param_s *coco_bind_material_param_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_bind_material_param_check(struct coco_ctx_s *, struct coco_bind_material_param_s *);

DLL_PUBLIC void coco_bind_material_param_dump(struct coco_ctx_s *, struct coco_bind_material_param_s *, int);

/**/

DLL_PUBLIC struct coco_bind_material_technique_common_s *coco_bind_material_technique_common_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_bind_material_technique_common_check(struct coco_ctx_s *, struct coco_bind_material_technique_common_s *);

DLL_PUBLIC void coco_bind_material_technique_common_dump(struct coco_ctx_s *, struct coco_bind_material_technique_common_s *, int);

/**/

DLL_PUBLIC struct coco_bind_material_s *coco_bind_material_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_bind_material_check(struct coco_ctx_s *, struct coco_bind_material_s *);

DLL_PUBLIC void coco_bind_material_dump(struct coco_ctx_s *, struct coco_bind_material_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_BIND_MATERIAL_H */

/*-------------------------------------------------------------------------*/

