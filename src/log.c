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

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "coco_internal.h"

/*-------------------------------------------------------------------------*/

void __coco_log(coco_ctx_t *ctx, coco_log_type_t type, const char *fname, int fline, int xml_line, int xml_column, const char *format, ...)
{
	va_list ap;

	switch(type)
	{
		case TYPE_DEBUG:
			fprintf(stderr, "DEBUG: %s:%d, ligne: %d, column: %d - ", fname, fline, xml_line, xml_column);
			break;

		case TYPE_NOTICE:
			fprintf(stderr, "NOTICE: %s:%d, ligne: %d, column: %d - ", fname, fline, xml_line, xml_column);
			break;

		case TYPE_WARNING:
			fprintf(stderr, "WARNING: %s:%d, ligne: %d, column: %d - ", fname, fline, xml_line, xml_column);
			ctx->wrn_nr++;
			break;

		case TYPE_ERROR:
			fprintf(stderr, "ERROR: %s:%d, ligne: %d, column: %d - ", fname, fline, xml_line, xml_column);
			ctx->err_nr++;
			break;

		case TYPE_FATAL:
			fprintf(stderr, "FATAL: %s:%d, ligne: %d, column: %d - ", fname, fline, xml_line, xml_column);
			break;

		default:
			return;
	}

	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);

	if(type == TYPE_FATAL) {
		exit(1);
	}
}


/*-------------------------------------------------------------------------*/

