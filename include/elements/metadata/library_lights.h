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

#ifndef __COCO_LIBRARY_LIGHTS_H
#define __COCO_LIBRARY_LIGHTS_H

/*-------------------------------------------------------------------------*/

typedef struct coco_library_lights_s
{
	struct coco_base_s base;

	struct coco_library_lights_s *prev, *next;

	/**/

	const char *id;
	const char *name;

	struct coco_asset_s *asset;

	struct coco_light_s *light_list;

	struct coco_extra_s *extra_list;

} coco_library_lights_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC struct coco_library_lights_s *coco_library_lights_parse(struct coco_ctx_s *, struct yaxp_node_s *);

DLL_PUBLIC bool coco_library_lights_check(struct coco_ctx_s *, struct coco_library_lights_s *);

DLL_PUBLIC void coco_library_lights_dump(struct coco_ctx_s *, struct coco_library_lights_s *, int);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_LIBRARY_LIGHT_H */

/*-------------------------------------------------------------------------*/

