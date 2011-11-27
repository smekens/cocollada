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

#ifndef __COCO_LIGHT_H
#define __COCO_LIGHT_H

/*-------------------------------------------------------------------------*/

typedef struct coco_light_technique_common_s
{
	struct coco_base_s base;

	struct coco_light_technique_common_s *prev, *next;

	/**/

	struct coco_ambient_core_s *ambient;
	struct coco_directional_s *directional;
	struct coco_point_s *point;
	struct coco_spot_s *spot;

} coco_light_technique_common_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_light_s
{
	struct coco_base_s base;

	struct coco_light_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_asset_s *asset;

	struct coco_light_technique_common_s *technique_common;
	struct coco_technique_core_s *technique_list;

	struct coco_extra_s *extra_list;

} coco_light_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_light_technique_common_s *coco_light_technique_common_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_light_technique_common_check(struct coco_ctx_s *, struct coco_light_technique_common_s *);

DLL_PUBLIC void coco_light_technique_common_dump(struct coco_ctx_s *, struct coco_light_technique_common_s *, int);

/**/

DLL_PUBLIC struct coco_light_s *coco_light_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_light_check(struct coco_ctx_s *, struct coco_light_s *);

DLL_PUBLIC void coco_light_dump(struct coco_ctx_s *, struct coco_light_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_LIGHT_H */

/*-------------------------------------------------------------------------*/

