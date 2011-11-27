/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of COMMON.
 *
 */

/*-------------------------------------------------------------------------*/

#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "coco_internal.h"

/*-------------------------------------------------------------------------*/
/*
static const char *__coco_skip_char_eq(const char *s, int c)
{
	for(; *s != '\0' && *s == c; s++);

	return s;
}
*/
/*-------------------------------------------------------------------------*/
/*
static const char *__coco_skip_char_ne(const char *s, int c)
{
	for(; *s != '\0' && *s != c; s++);

	return s;
}
*/
/*-------------------------------------------------------------------------*/

static int __coco_isreal(int c)
{
	static const int __ascii_table[256] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	return __ascii_table[c & 0xFF];
}

/*-------------------------------------------------------------------------*/

static const char *__coco_skip_int_eq(const char *s)
{
	for(; *s != '\0' && isalnum(*s) != 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

static const char *__coco_skip_int_ne(const char *s)
{
	for(; *s != '\0' && isalnum(*s) == 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

static const char *__coco_skip_flt_eq(const char *s)
{
	for(; *s != '\0' && __coco_isreal(*s) != 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

static const char *__coco_skip_flt_ne(const char *s)
{
	for(; *s != '\0' && __coco_isreal(*s) == 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

static float coco_simplify(float f)
{
	float r = floor(f + 0.5f);

	return fabs(r - f) < 1.0e-5f ? r : f;
}

/*-------------------------------------------------------------------------*/

void coco_vector_shr_alloc(coco_ctx_t *ctx, coco_vector_shr_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, int16_t, nr);
}

/*-------------------------------------------------------------------------*/

void coco_vector_int_alloc(coco_ctx_t *ctx, coco_vector_int_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, int32_t, nr);
}

/*-------------------------------------------------------------------------*/

void coco_vector_flt_alloc(coco_ctx_t *ctx, coco_vector_flt_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, float, nr);
}

/*-------------------------------------------------------------------------*/

void coco_vector_shr_free(coco_ctx_t *ctx, coco_vector_shr_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void coco_vector_int_free(coco_ctx_t *ctx, coco_vector_int_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void coco_vector_flt_free(coco_ctx_t *ctx, coco_vector_flt_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void coco_string_to_vector_shr(coco_ctx_t *ctx, coco_vector_shr_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __coco_skip_int_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __coco_skip_int_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __coco_skip_int_ne(q);
	}

	/*--------------------------------------*/

	coco_vector_shr_alloc(ctx, vector, nr);

	int16_t *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __coco_skip_int_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __coco_skip_int_eq(p);
		array[i] = atoi(p);
		p = __coco_skip_int_ne(q);
	}
	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

void coco_string_to_vector_int(coco_ctx_t *ctx, coco_vector_int_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __coco_skip_int_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __coco_skip_int_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __coco_skip_int_ne(q);
	}

	/*--------------------------------------*/

	coco_vector_int_alloc(ctx, vector, nr);

	int32_t *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __coco_skip_int_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __coco_skip_int_eq(p);
		array[i] = atoi(p);
		p = __coco_skip_int_ne(q);
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

void coco_string_to_vector_flt(coco_ctx_t *ctx, coco_vector_flt_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __coco_skip_flt_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __coco_skip_flt_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __coco_skip_flt_ne(q);
	}

	/*--------------------------------------*/

	coco_vector_flt_alloc(ctx, vector, nr);

	float *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __coco_skip_flt_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __coco_skip_flt_eq(p);
		array[i] = coco_simplify(atof(p));
		p = __coco_skip_flt_ne(q);
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/
