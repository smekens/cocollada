/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS
 * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com
 *
 * Version : 1.0 (2010-2011)
 *
 *
 * This file is part of CLDA.
 *
 */

/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "../../include/coco.h"

/*-------------------------------------------------------------------------*/

typedef struct input_s
{
	const char *semantic;

	int offset;
	int set;

	coco_source_t *source;

	/**/

	struct input_s *prev, *next;

} input_t;

/*-------------------------------------------------------------------------*/

typedef struct vector_shr_s
{
	int nr;

	int16_t *array;

} vector_shr_t;

/*-------------------------------------------------------------------------*/

typedef struct vector_int_s
{
	int nr;

	int32_t *array;

} vector_int_t;

/*-------------------------------------------------------------------------*/

typedef struct vector_flt_s
{
	int nr;

	float *array;

} vector_flt_t;

/*-------------------------------------------------------------------------*/

const char *__skip_char_eq(const char *s, int c)
{
	for(; *s != '\0' && *s == c; s++);

	return s;
}

/*-------------------------------------------------------------------------*/

void vector_shr_alloc(vector_shr_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_new_array(int16_t, nr);
}

/*-------------------------------------------------------------------------*/

void vector_int_alloc(vector_int_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_new_array(int32_t, nr);
}

/*-------------------------------------------------------------------------*/

void vector_flt_alloc(vector_flt_t *vector, int nr)
{
	vector->nr = nr;
	vector->array = ctnr_new_array(float, nr);
}

/*-------------------------------------------------------------------------*/

void vector_shr_free(vector_shr_t *vector)
{
	if(vector->array != NULL) {
		ctnr_memory_free(vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void vector_int_free(vector_int_t *vector)
{
	if(vector->array != NULL) {
		ctnr_memory_free(vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void vector_flt_free(vector_flt_t *vector)
{
	if(vector->array != NULL) {
		ctnr_memory_free(vector->array);
	}
}

/*-------------------------------------------------------------------------*/

void vector_deindex(vector_flt_t *dst, vector_flt_t *vertex_array, int *stride_array, int *idxinc_array, int idim, int vdim, vector_int_t *index)
{
	int i;
	int j;
	int k = 0;

	/*--------------------------------------*/

	int  xdim  = 0;
	int stride = 0;

	for(i = 0; i < vdim; i++)
	{
		 xdim  += idxinc_array[i];
		stride += stride_array[i];
	}

	/*--------------------------------------*/

	if(idim != xdim)
	{
		/* Oula ! */
		/* Oula ! */
		/* Oula ! */

		idim = xdim;
	}

	/*--------------------------------------*/

	int nr1 =  vdim  * index->nr / idim;
	int nr2 = stride * index->nr / idim;

	/*--------------------------------------*/

	vector_flt_alloc(dst, nr2);

	/*--------------------------------------*/

	int   *idx_ptr = index->array;
	float *dst_ptr =  dst ->array;

	/*--------------------------------------*/

	for(i = 0; i < nr1; i++)
	{
		j = i % vdim;

		if(idxinc_array[j] != 0 && i > 0)
		{
			k++;
		}

		stride = stride_array[j];

		memcpy(dst_ptr, &vertex_array[j].array[stride * idx_ptr[k]], stride * sizeof(float));

		dst_ptr += stride;
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

void vector_quad2tri(vector_flt_t *dst, vector_flt_t *src, int stride)
{
	/*--------------------------------------*/

	vector_flt_alloc(dst, 3 * src->nr / 2);

	/*--------------------------------------*/

	float *src_ptr = src->array;
	float *dst_ptr = dst->array;

	size_t size = stride * sizeof(float);

	/*--------------------------------------*/

	int i;

	for(i = 0; i < src->nr; i += 4 * stride, src_ptr += 4 * stride)
	{
		memcpy(dst_ptr, src_ptr + 0 * stride, size);
		dst_ptr += stride;
		memcpy(dst_ptr, src_ptr + 1 * stride, size);
		dst_ptr += stride;
		memcpy(dst_ptr, src_ptr + 2 * stride, size);
		dst_ptr += stride;

		memcpy(dst_ptr, src_ptr + 0 * stride, size);
		dst_ptr += stride;
		memcpy(dst_ptr, src_ptr + 2 * stride, size);
		dst_ptr += stride;
		memcpy(dst_ptr, src_ptr + 3 * stride, size);
		dst_ptr += stride;
	}

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

typedef struct __item_s
{
	int index;

	unsigned hash;

	struct __item_s *next;

} __item_t;

/*-------------------------------------------------------------------------*/

void vector_reindex(vector_shr_t *dst1, vector_flt_t *dst2, vector_flt_t *src, int stride)
{
	int i;

	int index = 0;
	int xedni = 0;

	__item_t *item/*  */;
	__item_t *dict[8192];

	memset(&dict, 0x00, sizeof(dict));

	/*--------------------------------------*/

	int dst1__nr1 = 0;
	short *dst1__array1 = ctnr_new_array(short, src->nr);
	int dst1__nr2 = 0;
	float *dst1__array2 = ctnr_new_array(float, src->nr);

	/*--------------------------------------*/

	size_t size = stride * sizeof(float);

	/*--------------------------------------*/

	ctnr_pool_t pool;

	ctnr_pool_init(&pool);

	/*--------------------------------------*/

	for(i = 0; i < src->nr; i += stride)
	{
		/*--------------------------------------*/
		/* HASH					*/
		/*--------------------------------------*/

		unsigned hash = ctnr_murmur32(&src->array[i], stride * sizeof(float), 0xAABBCCDD);

		/*--------------------------------------*/
		/* LOOKUP				*/
		/*--------------------------------------*/

		index = -1;

		for(item = dict[hash % 8192]; item != NULL; item = item->next)
		{
			if(item->hash == hash)
			{
				index = item->index;

				break;
			}
		}

		/*--------------------------------------*/
		/* INSERT				*/
		/*--------------------------------------*/

		if(index == -1)
		{
			item = ctnr_pool_new(&pool, __item_t);

			item->hash = hash;
			item->index = xedni;

			if(dict[hash % 8192] == NULL)
			{
				item->next = dict[hash % 8192];
				dict[hash % 8192] = /* */ item;
			}

			index = xedni++;

			/*--------------------------------------*/
			/* VERTICES				*/
			/*--------------------------------------*/

			memcpy(&dst1__array2[dst1__nr2], &src->array[i], size);

			dst1__nr2 += stride;
		}

		/*--------------------------------------*/
		/* INDICES				*/
		/*--------------------------------------*/

		dst1__array1[dst1__nr1++] = index;
	}

	/*--------------------------------------*/

	dst1->nr = dst1__nr1;
	dst1->array = dst1__array1;

	dst2->nr = dst1__nr2;
	dst2->array = dst1__array2;

	/*--------------------------------------*/

	ctnr_pool_flush(&pool);

	/*--------------------------------------*/
}

/*-------------------------------------------------------------------------*/

input_t *build_input_list(coco_ctx_t *ctx, coco_input_t *input_list)
{
	input_t *result = NULL;

	/**/

	int nr1;
	int nr2;

	input_t *input;
	coco_input_t *coco_input;
	coco_vertices_input_t *vertices_input;

	/**/

	ctnr_list_foreach(input_list, coco_input, nr1)
	{
		coco_source_t *source = coco_ctx_lookup_by_name(ctx, coco_source_t, __skip_char_eq(coco_input->source, '#'));

		if(source != NULL)
		{
			input = ctnr_new(input_t);

			input->semantic = coco_input->semantic;

			input->offset = coco_input->offset;
			input->set = coco_input->set;

			input->source = source;

			ctnr_list_add(result, input);
		}
		else
		{
			coco_vertices_t *vertices = coco_ctx_lookup_by_name(ctx, coco_vertices_t, __skip_char_eq(coco_input->source, '#'));

			ctnr_list_foreach(vertices->input_list, vertices_input, nr2)
			{
				source = coco_ctx_lookup_by_name(ctx, coco_source_t, __skip_char_eq(vertices_input->source, '#'));

				input = ctnr_new(input_t);

				input->semantic = vertices_input->semantic;

				input->offset = coco_input->offset;
				input->set = coco_input->set;

				input->source = source;

				ctnr_list_add(result, input);
			}
		}
	}

	return result;
}

/*-------------------------------------------------------------------------*/

int main(int argc, char **argv)
{
	int i;
	int j;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <fname>\n", argv[0]);

		return 1;
	}

	FILE *fp = fopen(argv[1], "rt");

	if(fp != NULL)
	{
		bool result = true;
		/*-----------------------------------------------------------------*/
		/* INITIALIZE COLLADA						   */
		/*-----------------------------------------------------------------*/

		coco_ctx_t ctx;

		coco_ctx_initialize(&ctx);

		/*-----------------------------------------------------------------*/
		/* LOAD								   */
		/*-----------------------------------------------------------------*/

		fseek(fp, 0, SEEK_END);
		size_t size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		/**/

		buff_t buff = ctnr_pool_malloc_zero(&ctx.pool, size + 1);

		fread(buff, 1, size, fp);

		fclose(fp);

		/*-----------------------------------------------------------------*/
		/* COLLADA PARSE						   */
		/*-----------------------------------------------------------------*/

		result = coco_ctx_loader(&ctx, buff, size);

		/*-----------------------------------------------------------------*/
		/* COLLADA DUMP							   */
		/*-----------------------------------------------------------------*/

		if(ctx.collada->library_geometries_list == NULL || ctx.collada->library_geometries_list->geometry_list == NULL)
		{
			fprintf(stderr, "Error: no geometry !\n");

			return 1;
		}

		coco_geometry_t *geometry = ctx.collada->library_geometries_list->geometry_list;

		int nr1;
		int nr2;

		coco_polylist_t *polylist;
		coco_triangles_t *triangles;

		ctnr_list_foreach(geometry->mesh->polylist_list, polylist, nr1)
		{
			printf("Only triangle list allowed !\n");

			return 1;
		}

		ctnr_list_foreach(geometry->mesh->triangles_list, triangles, nr1)
		{
			i = 0;
			int idim = 0;
			int vdim = 0;
			int stride = 0;

			int prev_offset = -1;

			input_t *input;
			input_t *input_list = build_input_list(&ctx, triangles->input_list);

			vector_flt_t vertex_array[64];
			/*    */ int stride_array[64];
			/*    */ int idxinc_array[64];

			ctnr_list_foreach(input_list, input, nr2)
			{
				switch(ctnr_hash(input->semantic))
				{
					case 0xA61400B6: /* POSITION */
					case 0x6DE772C0: /* NORMAL */
					case 0x21C2680F: /* COLOR */
						i += 0;
						goto __ok2;

					case 0x7536A15A: /* TEXCOORD */
						i += 1;
						goto __ok2;

					default:
						printf("Oula (content_mask) !\n");

						return 1;
					__ok2:
					{
						/*------------------*/
						/* VERTICES	    */
						/*------------------*/

						vector_flt_t source__vector;

						source__vector.nr = input->source->float_array->count;
						source__vector.array = input->source->float_array->array;

						/*------------------*/

						if(source__vector.nr != input->source->technique_common->accessor->count * input->source->technique_common->accessor->stride)
						{
							printf("goto from line %d\n", __LINE__);

							return 1;
						}

						/*------------------*/

						vertex_array[vdim] = source__vector;
						stride_array[vdim] = input->source->technique_common->accessor->stride;

						if(input->offset > prev_offset)
						{
							idxinc_array[vdim] = 1;
							idim += 1;
						}
						else
						{
							idxinc_array[vdim] = 0;
							idim += 0;
						}

						prev_offset = input->offset;

						vdim   += 0x000000000001;
						stride += input->source->technique_common->accessor->stride;
					}
				}
			}

			while(input_list != NULL && (input = ctnr_list_pop(input_list)) != NULL) {
				ctnr_memory_free(input);
			}

			/*----------------------*/
			/* INDICES		*/
			/*----------------------*/

			vector_int_t v1;

			v1.nr = triangles->p->count;
			v1.array = triangles->p->array;

			int count = 3 * triangles->count * idim;

			if(v1.nr != count)
			{
				printf("ERROR 4\n");

				return 1;
			}

			/*----------------------*/
			/* DEINDEX		*/
			/*----------------------*/

			vector_flt_t v2;

			vector_deindex(&v2, vertex_array, stride_array, idxinc_array, idim, vdim, &v1);

			/*----------------------*/
			/* REINDEX 		*/
			/*----------------------*/

			vector_shr_t v3;
			vector_flt_t v4;

			vector_reindex(&v3, &v4, &v2, stride);

			/*----------------------*/
			/* DUMP TO SCREEN	*/
			/*----------------------*/
/*
			short *buff1 = blend_block_header_alloc(&blend_ctx, "I000", "short", v3.nr / 0x0003, sizeof(short) * 0x0003);
			float *buff2 = blend_block_header_alloc(&blend_ctx, "V000", "float", v4.nr / stride, sizeof(float) * stride);
*/
			printf("/*-------------------------------------------------------------------------*/"	"\n");
			printf("/* Author  : Jerome ODIER, Christophe SMEKENS, Francois SMEKENS"		"\n");
			printf(" * Email   : ---@gmail.com, ---@gmail.com, ---@gmail.com"			"\n");
			printf(" *"										"\n");
			printf(" * Version : 1.0 (2010-2011)"							"\n");
			printf(" *"										"\n");
			printf(" *"										"\n");
			printf(" * This file is part of CLDA."							"\n");
			printf(" *"										"\n");
			printf(" */"										"\n");
			printf(""										"\n");
			printf("/*-------------------------------------------------------------------------*/"	"\n");
			printf(""										"\n");
			printf("const int vertex_buffer_%s_nr = %d;"						"\n", geometry->name, v4.nr / stride);
			printf("const int vertex_buffer_%s_stride = %d;"					"\n", geometry->name, stride - 2);
			printf(""										"\n");
			printf("const float vertex_buffer_%s_array[%d * %d] = {"				"\n", geometry->name, v4.nr / stride, stride);

			for(j = 0; j < v4.nr / stride; j++)
			{
				printf("\t");

				for(i = 0; i < stride - 2; i++)
				{
					printf("%6.3f, ", v4.array[j * stride + i]);
				}

				printf("\n");
			}

			printf("};"										"\n");
			printf(""										"\n");
			printf("/*-------------------------------------------------------------------------*/"	"\n");
			printf(""										"\n");
			printf("const int index_buffer_%s_nr = %d;"						"\n", geometry->name, v3.nr / 3);
			printf("const int index_buffer_%s_stride = %d;"						"\n", geometry->name, 3);
			printf(""										"\n");
			printf("const float index_buffer_%s_array[%d * %d] = {"					"\n", geometry->name, v3.nr / 3, 3);

			for(j = 0; j < v3.nr / 3; j++)
			{
				printf("\t");

				for(i = 0; i < 3; i++)
				{
					printf("%4d, ", v3.array[j * 3 + i]);
				}

				printf("\n");
			}

			printf("};"										"\n");
			printf(""										"\n");
			printf("/*-------------------------------------------------------------------------*/"	"\n");
			printf(""										"\n");

			/*----------------------*/
			/* CLEANING		*/
			/*----------------------*/

			vector_flt_free(&v4);
			vector_shr_free(&v3);
			vector_flt_free(&v2);
		}

		/*-----------------------------------------------------------------*/
		/* FINALIZE COLLADA						   */
		/*-----------------------------------------------------------------*/

		coco_ctx_finalize(&ctx);

		/*-----------------------------------------------------------------*/
		/* FINALIZE							   */
		/*-----------------------------------------------------------------*/

		return result != false ? 0 : 1;
	}

	return 1;
}

/*-------------------------------------------------------------------------*/

