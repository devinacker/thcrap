/**
  * Touhou Community Reliant Automatic Patcher
  * Team Shanghai Alice support plugin
  *
  * ----
  *
  * libpng extensions.
  */

#pragma once

// Why couldn't libpng just include the buffer pointer into the png_image
// structure. Are different pointer sizes (thus, differing structure sizes)
// really that bad?
typedef struct {
	png_image img;
	png_bytep buf;
} png_image_ex, *png_image_exp;

// Creates a new, empty PNG image with the given [format] and dimensions.
// [image] must either be zeroed out or represent a valid PNG image.
int png_image_new(
	png_image_exp image,
	const png_uint_32 w,
	const png_uint_32 h,
	const png_uint_32 format
);
