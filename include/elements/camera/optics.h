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

#ifndef __COCO_OPTICS_H
#define __COCO_OPTICS_H

/*-------------------------------------------------------------------------*/

typedef struct coco_optics_technique_common_s
{
	struct coco_base_s base;

	struct coco_optics_technique_common_s *prev, *next;

	/**/

	struct coco_orthographic_s *orthographic;
	struct coco_perspective_s *perspective;

} coco_optics_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_optics_s
{
	struct coco_base_s base;

	struct coco_optics_s *prev, *next;

	/**/

	struct coco_optics_technique_common_s *technique_common;
	struct coco_technique_core_s *technique_list;

	struct coco_extra_s *extra_list;

} coco_optics_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_optics_technique_common_s *coco_optics_technique_common_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_optics_technique_common_check(struct coco_ctx_s *, struct coco_optics_technique_common_s *);

DLL_PUBLIC void coco_optics_technique_common_dump(struct coco_ctx_s *, struct coco_optics_technique_common_s *, int);

/**/

DLL_PUBLIC struct coco_optics_s *coco_optics_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_optics_check(struct coco_ctx_s *, struct coco_optics_s *);

DLL_PUBLIC void coco_optics_dump(struct coco_ctx_s *, struct coco_optics_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_OPTICS_H */

/*-------------------------------------------------------------------------*/

