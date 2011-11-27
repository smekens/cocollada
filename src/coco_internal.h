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

#ifndef __COCO_INTERNAL_H
#define __COCO_INTERNAL_H

/*-------------------------------------------------------------------------*/

#include "../include/coco.h"

/*-------------------------------------------------------------------------*/
/* CONTEXT								   */
/*-------------------------------------------------------------------------*/

typedef struct coco_ctx_element_s
{
	const char *name;

	void *parser;
	void *check;
	void *dump;

	/**/

	struct coco_ctx_element_s *prev, *next;

} coco_ctx_elem_t;

/*-------------------------------------------------------------------------*/
/* DUMP									   */
/*-------------------------------------------------------------------------*/

#define COCO_DUMP_INDENT(indent, ...)	\
  {							\
	int __i;					\
							\
	printf("\033[34m");				\
							\
	for(__i = 0; __i < (indent); __i++)		\
	{						\
		printf("__");				\
	}						\
							\
	printf("\033[0m");				\
							\
	printf(__VA_ARGS__);				\
  }

/*-------------------------------------------------------------------------*/
/* VECTORS								   */
/*-------------------------------------------------------------------------*/

typedef struct coco_vector_shr_s
{
	int nr;

	int16_t *array;

} coco_vector_shr_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_vector_int_s
{
	int nr;

	int32_t *array;

} coco_vector_int_t;

/*-------------------------------------------------------------------------*/

typedef struct coco_vector_flt_s
{
	int nr;

	float *array;

} coco_vector_flt_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void coco_vector_shr_alloc(struct coco_ctx_s *, struct coco_vector_shr_s *, int);
DLL_PUBLIC void coco_vector_int_alloc(struct coco_ctx_s *, struct coco_vector_int_s *, int);
DLL_PUBLIC void coco_vector_flt_alloc(struct coco_ctx_s *, struct coco_vector_flt_s *, int);

DLL_PUBLIC void coco_vector_shr_free(struct coco_ctx_s *, struct coco_vector_shr_s *);
DLL_PUBLIC void coco_vector_int_free(struct coco_ctx_s *, struct coco_vector_int_s *);
DLL_PUBLIC void coco_vector_flt_free(struct coco_ctx_s *, struct coco_vector_flt_s *);

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void coco_string_to_vector_shr(struct coco_ctx_s *, struct coco_vector_shr_s *, const char *);
DLL_PUBLIC void coco_string_to_vector_int(struct coco_ctx_s *, struct coco_vector_int_s *, const char *);
DLL_PUBLIC void coco_string_to_vector_flt(struct coco_ctx_s *, struct coco_vector_flt_s *, const char *);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COCO_INTERNAL_H */

/*-------------------------------------------------------------------------*/

