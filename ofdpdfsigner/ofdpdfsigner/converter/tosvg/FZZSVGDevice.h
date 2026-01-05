//
//  Created by zizheng fan on 2024/09/18.
//

#ifndef FZZSVGDEVICE_H
#define FZZSVGDEVICE_H

#include <stdio.h>
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include "mupdf/memento.h"
#include "mupdf/ucdn.h"

typedef struct
{
    fz_device super;
    fz_device * svgdev;

    bool isstamp;

} fzsvg_device;

fz_device * new_fzsvg_device(fz_context *ctx, fz_output *out, float page_width, float page_height, int text_format, int reuse_images);

#endif //FZZSVGDEVICE_H
