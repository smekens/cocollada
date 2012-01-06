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

#ifndef __COCO_H
#define __COCO_H

/*-------------------------------------------------------------------------*/

#include <ctnr.h>
#include <yaxp.h>

/*-------------------------------------------------------------------------*/

struct coco_ctx_s;

/*-------------------------------------------------------------------------*/

typedef struct coco_base_s
{
	const char *id;

	unsigned type;

	int line;
	int column;

	/**/

	struct coco_base_s *prev, *next;

} coco_base_t;

/*-------------------------------------------------------------------------*/

#include "elements/camera/camera.h"
#include "elements/camera/optics.h"
#include "elements/camera/orthographic.h"
#include "elements/camera/perspective.h"

#include "elements/dataflow/accessor.h"
#include "elements/dataflow/float_array.h"
#include "elements/dataflow/input.h"
#include "elements/dataflow/source.h"

#include "elements/effects/effect.h"
#include "elements/effects/profile_common.h"

#include "elements/extensibility/extra.h"
#include "elements/extensibility/technique_core.h"

#include "elements/geometry/geometry.h"
#include "elements/geometry/mesh.h"
#include "elements/geometry/p.h"
#include "elements/geometry/polylist.h"
#include "elements/geometry/triangles.h"
#include "elements/geometry/vcount.h"
#include "elements/geometry/vertices.h"

#include "elements/lightning/color.h"
#include "elements/lightning/light.h"
#include "elements/lightning/ambient_core.h"
#include "elements/lightning/directional.h"
#include "elements/lightning/spot.h"
#include "elements/lightning/point.h"

#include "elements/materials/instance_effect.h"
#include "elements/materials/material.h"

#include "elements/metadata/asset.h"
#include "elements/metadata/collada.h"
#include "elements/metadata/library_cameras.h"
#include "elements/metadata/library_effects.h"
#include "elements/metadata/library_geometries.h"
#include "elements/metadata/library_images.h"
#include "elements/metadata/library_lights.h"
#include "elements/metadata/library_materials.h"
#include "elements/metadata/library_nodes.h"
#include "elements/metadata/library_visual_scenes.h"
#include "elements/metadata/unit.h"

#include "elements/rendering/ambient_fx.h"
#include "elements/rendering/diffuse.h"
#include "elements/rendering/emission.h"
#include "elements/rendering/fx_common_float.h"
#include "elements/rendering/fx_common_param.h"
#include "elements/rendering/fx_common_texture.h"
#include "elements/rendering/index_of_refraction.h"
#include "elements/rendering/lambert.h"
#include "elements/rendering/phong.h"
#include "elements/rendering/reflective.h"
#include "elements/rendering/reflectivity.h"
#include "elements/rendering/shininess.h"
#include "elements/rendering/specular.h"
#include "elements/rendering/transparency.h"
#include "elements/rendering/transparent.h"

#include "elements/scene/bind_material.h"
#include "elements/scene/bind_vertex_input.h"
#include "elements/scene/instance_camera.h"
#include "elements/scene/instance_geometry.h"
#include "elements/scene/instance_light.h"
#include "elements/scene/instance_material.h"
#include "elements/scene/instance_node.h"
#include "elements/scene/instance_visual_scene.h"
#include "elements/scene/node.h"
#include "elements/scene/scene.h"
#include "elements/scene/visual_scene.h"

#include "elements/shader/newparam.h"

#include "elements/texturing/image.h"
#include "elements/texturing/sampler2D.h"
#include "elements/texturing/surface.h"

#include "elements/transform/lookat.h"
#include "elements/transform/matrix.h"
#include "elements/transform/rotate.h"
#include "elements/transform/scale.h"
#include "elements/transform/translate.h"

/*-------------------------------------------------------------------------*/

typedef struct coco_ctx_s
{
	struct coco_collada_s *collada;

	/**/

	struct ctnr_hash_s hash_list;
	struct ctnr_hash_s elem_list;

	struct ctnr_pool_s pool;

	/**/

	int wrn_nr;
	int err_nr;

} coco_ctx_t;

/*-------------------------------------------------------------------------*/
/* LOG									   */
/*-------------------------------------------------------------------------*/

typedef enum coco_log_type_e
{
	TYPE_NOTICE = 0
	,
	TYPE_DEBUG = 1
	,
	TYPE_WARNING = 2
	,
	TYPE_ERROR = 3
	,
	TYPE_FATAL = 4

} coco_log_type_t;

#define coco_log(ctx, type, line, column, ...) __coco_log(ctx, type, __FILE__, __LINE__, line, column, __VA_ARGS__)

DLL_PUBLIC void __coco_log(struct coco_ctx_s *, coco_log_type_t type, const char *, int, int, int, const char *, ...) __attribute__ ((format(printf, 7, 8)));

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void coco_ctx_initialize(struct coco_ctx_s *);
DLL_PUBLIC void coco_ctx_finalize(struct coco_ctx_s *);

/*-------------------------------------------------------------------------*/

#define coco_ctx_factory(__ctx, __type)											\
	({														\
		struct coco_base_s *base = ctnr_cast(struct coco_base_s *, ctnr_pool_new_zero(&__ctx->pool, __type));	\
															\
		base->type = ctnr_hash(#__type);									\
															\
		ctnr_cast(__type *, base);										\
	})

/*-------------------------------------------------------------------------*/

#define coco_ctx_register_element(__ctx, __type, __elm_parse, __elm_check, __elm_dump) \
		__coco_ctx_register_element(__ctx, #__type, __elm_parse, __elm_check, __elm_dump)

DLL_PUBLIC void __coco_ctx_register_element(struct coco_ctx_s *, const char *, void *, void *, void *);

/*-------------------------------------------------------------------------*/

#define coco_ctx_parse(__ctx, __type, __node) \
		ctnr_cast(__type *(*)(coco_ctx_t *, yaxp_node_t *), __coco_ctx_get_parse(ctx, ctnr_hash(#__type)))(__ctx, __node)

DLL_PUBLIC void *__coco_ctx_get_parse(struct coco_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

#define coco_ctx_check(__ctx, __type, __object) \
		ctnr_cast(bool (*)(coco_ctx_t *, __type *), __coco_ctx_get_check(__ctx, ctnr_hash(#__type)))(__ctx, __object)

DLL_PUBLIC void *__coco_ctx_get_check(struct coco_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

#define coco_ctx_dump(__ctx, __type, __object, __indent) \
		ctnr_cast(void (*)(coco_ctx_t *, __type *, int), __coco_ctx_get_dump(__ctx, ctnr_hash(#__type)))(__ctx, __object, __indent)

DLL_PUBLIC void *__coco_ctx_get_dump(struct coco_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

DLL_PUBLIC bool coco_ctx_loader(struct coco_ctx_s *, BUFF_t, size_t);

DLL_PUBLIC bool coco_ctx_check_all(struct coco_ctx_s *);

DLL_PUBLIC void coco_ctx_dump_all(struct coco_ctx_s *);

/*-------------------------------------------------------------------------*/

#define coco_ctx_register(__ctx, __elm, __id)		\
	({							\
		__elm->base.id = __id;				\
		ctnr_hash_add(&__ctx->hash_list, __elm);	\
	})

#define coco_ctx_unregister(__ctx, __elm)			\
		ctnr_hash_del(&__ctx->hash_list, __elm);


#define coco_ctx_lookup_by_hash(ctx, type, hash) \
		ctnr_cast(type *, __coco_ctx_lookup_by_hash(ctx, ctnr_hash(#type), hash))

#define coco_ctx_lookup_by_name(ctx, type, name) \
		ctnr_cast(type *, __coco_ctx_lookup_by_name(ctx, ctnr_hash(#type), name))

DLL_PUBLIC struct coco_base_s *__coco_ctx_lookup_by_hash(struct coco_ctx_s *, unsigned, unsigned);
DLL_PUBLIC struct coco_base_s *__coco_ctx_lookup_by_name(struct coco_ctx_s *, unsigned, const char *);

/*-------------------------------------------------------------------------*/

const char *coco_ctx_strdup(struct coco_ctx_s *, const char *);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_H */

/*-------------------------------------------------------------------------*/

