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

#ifndef __COLLADA_H
#define __COLLADA_H

/*-------------------------------------------------------------------------*/

#include "../../libctnr/include/ctnr.h"
#include "../../libyaxp/include/yaxp.h"

/*-------------------------------------------------------------------------*/

struct collada_ctx_s;

/*-------------------------------------------------------------------------*/

typedef struct collada_base_s
{
	const char *id;

	unsigned type;

	int line;
	int column;

	/**/

	struct collada_base_s *prev, *next;

} collada_base_t;

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

typedef struct collada_ctx_s
{
	struct collada_s *collada;

	/**/

	struct ctnr_hash_list_s hash_list;
	struct ctnr_hash_list_s element_list;

	struct ctnr_pool_s pool;

	/**/

	int wrn_nr;
	int err_nr;

} collada_ctx_t;

/*-------------------------------------------------------------------------*/
/* LOG									   */
/*-------------------------------------------------------------------------*/

typedef enum collada_log_type_e
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

} collada_log_type_t;

#define collada_log(ctx, type, line, column, ...) __collada_log(ctx, type, __FILE__, __LINE__, line, column, __VA_ARGS__)

DLL_PUBLIC void __collada_log(struct collada_ctx_s *, collada_log_type_t type, const char *, int, int, int, const char *, ...) __attribute__ ((format(printf, 7, 8)));

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void collada_ctx_initialize(struct collada_ctx_s *);
DLL_PUBLIC void collada_ctx_finalize(struct collada_ctx_s *);

/*-------------------------------------------------------------------------*/

#define collada_ctx_factory(__ctx, __type)										\
	({														\
		struct collada_base_s *base = ctnr_cast(struct collada_base_s *, ctnr_pool_new(&__ctx->pool, __type));	\
															\
		base->type = ctnr_hash(#__type);									\
															\
		ctnr_cast(__type *, base);										\
	})

/*-------------------------------------------------------------------------*/

#define collada_ctx_register_element(__ctx, __type, __elm_parser, __elm_check, __elm_dump) \
		__collada_ctx_register_element(__ctx, #__type, __elm_parser, __elm_check, __elm_dump)

DLL_PUBLIC void __collada_ctx_register_element(struct collada_ctx_s *, const char *, void *, void *, void *);

/*-------------------------------------------------------------------------*/

#define collada_ctx_parser(__ctx, __type, __node) \
		ctnr_cast(__type *(*)(collada_ctx_t *, yaxp_node_t *), __collada_ctx_get_parser(ctx, ctnr_hash(#__type)))(__ctx, __node)

DLL_PUBLIC void *__collada_ctx_get_parser(struct collada_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

#define collada_ctx_check(__ctx, __type, __object) \
		ctnr_cast(bool (*)(collada_ctx_t *, __type *), __collada_ctx_get_check(__ctx, ctnr_hash(#__type)))(__ctx, __object)

DLL_PUBLIC void *__collada_ctx_get_check(struct collada_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

#define collada_ctx_dump(__ctx, __type, __object, __indent) \
		ctnr_cast(void (*)(collada_ctx_t *, __type *, int), __collada_ctx_get_dump(__ctx, ctnr_hash(#__type)))(__ctx, __object, __indent)

DLL_PUBLIC void *__collada_ctx_get_dump(struct collada_ctx_s *, unsigned);

/*-------------------------------------------------------------------------*/

DLL_PUBLIC bool collada_ctx_loader(struct collada_ctx_s *, BUFF_t, size_t);

DLL_PUBLIC bool collada_ctx_check_all(struct collada_ctx_s *);

DLL_PUBLIC void collada_ctx_dump_all(struct collada_ctx_s *);

/*-------------------------------------------------------------------------*/

#define collada_ctx_register(__ctx, __elm, __id)		\
	({							\
		__elm->base.id = __id;				\
		ctnr_hash_add(&__ctx->hash_list, __elm);	\
	})

#define collada_ctx_unregister(__ctx, __elm)			\
		ctnr_hash_del(&__ctx->hash_list, __elm);


#define collada_ctx_lookup_by_hash(ctx, type, hash) \
		ctnr_cast(type *, __collada_ctx_lookup_by_hash(ctx, ctnr_hash(#type), hash))

#define collada_ctx_lookup_by_name(ctx, type, name) \
		ctnr_cast(type *, __collada_ctx_lookup_by_name(ctx, ctnr_hash(#type), name))

DLL_PUBLIC struct collada_base_s *__collada_ctx_lookup_by_hash(struct collada_ctx_s *, unsigned, unsigned);
DLL_PUBLIC struct collada_base_s *__collada_ctx_lookup_by_name(struct collada_ctx_s *, unsigned, const char *);

/*-------------------------------------------------------------------------*/

const char *collada_ctx_strdup(struct collada_ctx_s *, const char *);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_H */

/*-------------------------------------------------------------------------*/

