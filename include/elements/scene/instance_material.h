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

#ifndef __COCO_INSTANCE_MATERIAL_H
#define __COCO_INSTANCE_MATERIAL_H

/*-------------------------------------------------------------------------*/

typedef struct coco_instance_material_s
{
	struct coco_base_s base;

	struct coco_instance_material_s *prev, *next;

	/**/

	const char *symbol;
	const char *target;
	const char *sid;
	const char *name;

	/* TODO bind */
	struct coco_bind_vertex_input_s *bind_vertex_input_list;

	struct coco_extra_s *extra_list;

} coco_instance_material_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_instance_material_s *coco_instance_material_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_instance_material_check(struct coco_ctx_s *, struct coco_instance_material_s *);

DLL_PUBLIC void coco_instance_material_dump(struct coco_ctx_s *, struct coco_instance_material_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INSTANCE_MATERIAL_H */

/*-------------------------------------------------------------------------*/

