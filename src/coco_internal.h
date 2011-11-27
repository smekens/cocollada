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

#ifndef __COLLADA_INTERNAL_H
#define __COLLADA_INTERNAL_H

/*-------------------------------------------------------------------------*/

#include "../include/collada.h"

/*-------------------------------------------------------------------------*/
/* CONTEXT								   */
/*-------------------------------------------------------------------------*/

typedef struct collada_ctx_element_s
{
	const char *name;

	void *parser;
	void *check;
	void *dump;

	/**/

	struct collada_ctx_element_s *prev, *next;

} collada_ctx_element_t;

/*-------------------------------------------------------------------------*/
/* DUMP									   */
/*-------------------------------------------------------------------------*/

#define COLLADA_DUMP_INDENT(indent, format, ...)	\
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
	
  }

/*-------------------------------------------------------------------------*/
/* VECTORS								   */
/*-------------------------------------------------------------------------*/

typedef struct collada_vector_shr_s
{
	int nr;

	int16_t *array;

} collada_vector_shr_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_vector_int_s
{
	int nr;

	int32_t *array;

} collada_vector_int_t;

/*-------------------------------------------------------------------------*/

typedef struct collada_vector_flt_s
{
	int nr;

	float *array;

} collada_vector_flt_t;

/*-------------------------------------------------------------------------*/

CTNR_BEGIN_EXTERN_C

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void collada_vector_shr_alloc(struct collada_ctx_s *, struct collada_vector_shr_s *, int);
DLL_PUBLIC void collada_vector_int_alloc(struct collada_ctx_s *, struct collada_vector_int_s *, int);
DLL_PUBLIC void collada_vector_flt_alloc(struct collada_ctx_s *, struct collada_vector_flt_s *, int);

DLL_PUBLIC void collada_vector_shr_free(struct collada_ctx_s *, struct collada_vector_shr_s *);
DLL_PUBLIC void collada_vector_int_free(struct collada_ctx_s *, struct collada_vector_int_s *);
DLL_PUBLIC void collada_vector_flt_free(struct collada_ctx_s *, struct collada_vector_flt_s *);

/*-------------------------------------------------------------------------*/

DLL_PUBLIC void collada_string_to_vector_shr(struct collada_ctx_s *, struct collada_vector_shr_s *, const char *);
DLL_PUBLIC void collada_string_to_vector_int(struct collada_ctx_s *, struct collada_vector_int_s *, const char *);
DLL_PUBLIC void collada_string_to_vector_flt(struct collada_ctx_s *, struct collada_vector_flt_s *, const char *);

/*-------------------------------------------------------------------------*/

CTNR_END_EXTERN_C

/*-------------------------------------------------------------------------*/

#endif /* __COLLADA_INTERNAL_H */

/*-------------------------------------------------------------------------*/

