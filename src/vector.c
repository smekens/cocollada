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

#include "collada_internal.h"

/*-------------------------------------------------------------------------*/

const char *__collada_skip_char_eq(const char *s, int c)
{
	for(; *s != '\0' && *s == c; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

const char *__collada_skip_char_ne(const char *s, int c)
{
	for(; *s != '\0' && *s != c; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

static int __collada_isreal(int c)
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

const char *__collada_skip_int_eq(const char *s)
{
	for(; *s != '\0' && isalnum(*s) != 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

const char *__collada_skip_int_ne(const char *s)
{
	for(; *s != '\0' && isalnum(*s) == 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

const char *__collada_skip_flt_eq(const char *s)
{
	for(; *s != '\0' && __collada_isreal(*s) != 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

const char *__collada_skip_flt_ne(const char *s)
{
	for(; *s != '\0' && __collada_isreal(*s) == 0; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

float collada_simplify(float f)
{
	float r = floor(f + 0.5f);

	return fabs(r - f) < 1.0e-5f ? r : f;
}

/*-------------------------------------------------------------------------*/

void collada_vector_shr_alloc(collada_ctx_t *ctx, collada_vector_shr_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, int16_t, nr);
}

/*-------------------------------------------------------------------------*/

void collada_vector_int_alloc(collada_ctx_t *ctx, collada_vector_int_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, int32_t, nr);
}

/*-------------------------------------------------------------------------*/

void collada_vector_flt_alloc(collada_ctx_t *ctx, collada_vector_flt_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_pool_new_array(&ctx->pool, float, nr);
}

/*-------------------------------------------------------------------------*/

void collada_vector_shr_free(collada_ctx_t *ctx, collada_vector_shr_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void collada_vector_int_free(collada_ctx_t *ctx, collada_vector_int_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void collada_vector_flt_free(collada_ctx_t *ctx, collada_vector_flt_t *vector)
{
	if(vector->array != NULL) {
		ctnr_pool_free(&ctx->pool, vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void collada_string_to_vector_shr(collada_ctx_t *ctx, collada_vector_shr_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __collada_skip_int_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __collada_skip_int_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __collada_skip_int_ne(q);
	}

	/*--------------------------------------*/

	collada_vector_shr_alloc(ctx, vector, nr);

	int16_t *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __collada_skip_int_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __collada_skip_int_eq(p);
		array[i] = atoi(p);
		p = __collada_skip_int_ne(q);
	}
	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

void collada_string_to_vector_int(collada_ctx_t *ctx, collada_vector_int_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __collada_skip_int_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __collada_skip_int_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __collada_skip_int_ne(q);
	}

	/*--------------------------------------*/

	collada_vector_int_alloc(ctx, vector, nr);

	int32_t *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __collada_skip_int_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __collada_skip_int_eq(p);
		array[i] = atoi(p);
		p = __collada_skip_int_ne(q);
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

void collada_string_to_vector_flt(collada_ctx_t *ctx, collada_vector_flt_t *vector, const char *str)
{
	/*--------------------------------------*/

	int nr = 0;

	const char *p = str;
	const char *q = 0x0;

	p = __collada_skip_flt_ne(p);

	for(;;)
	{
		if(p[0] == '\0') break;
		q = __collada_skip_flt_eq(p);

		nr++;

		if(q[0] == '\0') break;
		p = __collada_skip_flt_ne(q);
	}

	/*--------------------------------------*/

	collada_vector_flt_alloc(ctx, vector, nr);

	float *array = vector->array;

	/*--------------------------------------*/

	int i;

	p = str;
	q = 0x0;

	p = __collada_skip_flt_ne(p);

	for(i = 0; i < nr; i++)
	{
		q = __collada_skip_flt_eq(p);
		array[i] = collada_simplify(atof(p));
		p = __collada_skip_flt_ne(q);
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/
