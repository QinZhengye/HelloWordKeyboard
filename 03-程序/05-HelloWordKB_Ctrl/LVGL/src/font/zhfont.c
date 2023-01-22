/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ZHFONT
#define ZHFONT 1
#endif

#if ZHFONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0x60,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x49, 0x24, 0xbf, 0x49, 0x24, 0xbf, 0x52, 0x49,
    0x0,

    /* U+0024 "$" */
    0x23, 0xa3, 0x8, 0x61, 0x86, 0x18, 0x43, 0x17,
    0x10,

    /* U+0025 "%" */
    0x70, 0x8d, 0x90, 0x89, 0x8, 0xa0, 0x8a, 0xed,
    0xdb, 0x75, 0x10, 0x91, 0x9, 0x11, 0x1b, 0x10,
    0xe0,

    /* U+0026 "&" */
    0x38, 0x22, 0x11, 0x9, 0x7, 0x3, 0x7, 0x45,
    0x32, 0x8e, 0x67, 0x9e, 0x20,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x29, 0x29, 0x24, 0x92, 0x24, 0x88,

    /* U+0029 ")" */
    0x89, 0x22, 0x49, 0x24, 0xa4, 0xa0,

    /* U+002A "*" */
    0x2b, 0x67, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xdc,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x8, 0x42, 0x21, 0x8, 0x84, 0x22, 0x10, 0x88,
    0x40,

    /* U+0030 "0" */
    0x31, 0x28, 0x61, 0x86, 0x18, 0x61, 0x85, 0x27,
    0x0,

    /* U+0031 "1" */
    0x63, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x8f,
    0xc0,

    /* U+0032 "2" */
    0x7b, 0x30, 0x41, 0x4, 0x20, 0x84, 0x21, 0xf,
    0xc0,

    /* U+0033 "3" */
    0x79, 0x10, 0x41, 0x8, 0xc0, 0xc1, 0x6, 0x37,
    0x80,

    /* U+0034 "4" */
    0x4, 0x18, 0x50, 0xa2, 0x44, 0x91, 0x7f, 0x4,
    0x8, 0x10,

    /* U+0035 "5" */
    0x7d, 0x4, 0x10, 0x79, 0x30, 0x41, 0x6, 0x27,
    0x80,

    /* U+0036 "6" */
    0x39, 0x8, 0x20, 0xbb, 0x38, 0x61, 0x85, 0x33,
    0x80,

    /* U+0037 "7" */
    0xfc, 0x20, 0x84, 0x10, 0x42, 0x8, 0x20, 0x82,
    0x0,

    /* U+0038 "8" */
    0x39, 0x14, 0x51, 0x28, 0xe4, 0xe1, 0x87, 0x37,
    0x80,

    /* U+0039 "9" */
    0x73, 0x28, 0x61, 0x87, 0x37, 0x41, 0x8, 0x27,
    0x0,

    /* U+003A ":" */
    0xc3,

    /* U+003B ";" */
    0xa0, 0x3, 0x70,

    /* U+003C "<" */
    0x2, 0x1c, 0xc6, 0x6, 0x3, 0x80, 0x80,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x1, 0xc0, 0x60, 0x31, 0xcc, 0x20, 0x0,

    /* U+003F "?" */
    0x79, 0x10, 0x41, 0x8, 0x42, 0x8, 0x0, 0x82,
    0x0,

    /* U+0040 "@" */
    0xf, 0x83, 0x6, 0x20, 0x24, 0x1, 0x87, 0x18,
    0x91, 0x91, 0x19, 0x11, 0x93, 0x28, 0xdc, 0x40,
    0x2, 0x0, 0x1f, 0x0,

    /* U+0041 "A" */
    0x18, 0x18, 0x14, 0x34, 0x24, 0x26, 0x62, 0x7e,
    0x43, 0x41, 0x81,

    /* U+0042 "B" */
    0xf9, 0x1a, 0x14, 0x28, 0xdf, 0x21, 0xc1, 0x83,
    0xf, 0xf0,

    /* U+0043 "C" */
    0x3c, 0xc5, 0x4, 0x8, 0x10, 0x20, 0x40, 0x40,
    0xc4, 0xf0,

    /* U+0044 "D" */
    0xf9, 0x1a, 0x14, 0x18, 0x30, 0x60, 0xc1, 0x85,
    0x1b, 0xe0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0xf,
    0xc0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0047 "G" */
    0x1e, 0x61, 0x40, 0x80, 0x80, 0x87, 0x81, 0x81,
    0x41, 0x61, 0x1e,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x21, 0xc, 0xdc,

    /* U+004B "K" */
    0x85, 0x1a, 0x64, 0x8b, 0x1e, 0x32, 0x44, 0x85,
    0xa, 0x8,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0xf,
    0xc0,

    /* U+004D "M" */
    0xc3, 0xc3, 0xc3, 0xa5, 0xa5, 0xa5, 0xa9, 0x99,
    0x99, 0x99, 0x81,

    /* U+004E "N" */
    0x83, 0x87, 0xd, 0x1b, 0x32, 0x62, 0xc5, 0x87,
    0xe, 0x8,

    /* U+004F "O" */
    0x3e, 0x31, 0x90, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x41, 0x31, 0x87, 0x80,

    /* U+0050 "P" */
    0xf9, 0xe, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0051 "Q" */
    0x3e, 0x31, 0x90, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x41, 0x1b, 0x3, 0x1, 0x80, 0x38,

    /* U+0052 "R" */
    0xfd, 0xe, 0xc, 0x18, 0x7f, 0xa6, 0x44, 0x85,
    0xa, 0x8,

    /* U+0053 "S" */
    0x7a, 0x18, 0x20, 0x60, 0xe0, 0xc1, 0x6, 0x37,
    0x80,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0056 "V" */
    0x81, 0xc2, 0x42, 0x42, 0x66, 0x24, 0x24, 0x24,
    0x18, 0x18, 0x18,

    /* U+0057 "W" */
    0xc6, 0x14, 0x62, 0x46, 0x24, 0x52, 0x49, 0x26,
    0x92, 0x29, 0x42, 0x94, 0x28, 0xc3, 0xc, 0x30,
    0xc0,

    /* U+0058 "X" */
    0x42, 0x46, 0x24, 0x2c, 0x18, 0x18, 0x18, 0x24,
    0x24, 0x42, 0x42,

    /* U+0059 "Y" */
    0x82, 0x89, 0x11, 0x42, 0x85, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+005A "Z" */
    0xfe, 0x8, 0x10, 0x41, 0x82, 0x8, 0x10, 0x41,
    0x3, 0xf8,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005C "\\" */
    0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10,
    0x84,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005E "^" */
    0x30, 0xc5, 0x12, 0x4a, 0x10,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xcc, 0x80,

    /* U+0061 "a" */
    0x78, 0x30, 0x4f, 0xc6, 0x18, 0xdd,

    /* U+0062 "b" */
    0x82, 0x8, 0x2e, 0xce, 0x18, 0x61, 0x86, 0x2f,
    0x0,

    /* U+0063 "c" */
    0x39, 0x8, 0x20, 0x82, 0x4, 0xe,

    /* U+0064 "d" */
    0x4, 0x10, 0x4d, 0x4e, 0x18, 0x61, 0x87, 0x37,
    0x40,

    /* U+0065 "e" */
    0x39, 0x38, 0x7f, 0x82, 0x4, 0xe,

    /* U+0066 "f" */
    0x34, 0x44, 0xf4, 0x44, 0x44, 0x44,

    /* U+0067 "g" */
    0x7f, 0x9a, 0x16, 0x67, 0x90, 0x20, 0x3e, 0x83,
    0xd, 0xf0,

    /* U+0068 "h" */
    0x82, 0x8, 0x2e, 0xc6, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006A "j" */
    0x20, 0x12, 0x49, 0x24, 0x93, 0x80,

    /* U+006B "k" */
    0x82, 0x8, 0x22, 0x92, 0xca, 0x34, 0x9a, 0x28,
    0xc0,

    /* U+006C "l" */
    0xaa, 0xaa, 0xac,

    /* U+006D "m" */
    0xb9, 0xd8, 0xc6, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21,

    /* U+006E "n" */
    0xbb, 0x18, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xbb, 0x38, 0x61, 0x86, 0x18, 0xbc, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x3d, 0x18, 0x61, 0x86, 0x1c, 0xdd, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x74, 0x20, 0xc1, 0x86, 0x2e,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x44, 0x43,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0xdd,

    /* U+0076 "v" */
    0xc2, 0x89, 0x13, 0x22, 0x85, 0xa, 0x8,

    /* U+0077 "w" */
    0x44, 0x69, 0x49, 0x29, 0x25, 0x22, 0xa4, 0x63,
    0xc, 0x61, 0x8c,

    /* U+0078 "x" */
    0x44, 0xd8, 0xa1, 0x83, 0x5, 0x13, 0x62,

    /* U+0079 "y" */
    0xc2, 0x89, 0x11, 0x22, 0x85, 0x6, 0x8, 0x10,
    0x61, 0x80,

    /* U+007A "z" */
    0xfc, 0x21, 0xc, 0x21, 0x4, 0x3f,

    /* U+007B "{" */
    0x74, 0x44, 0x44, 0x48, 0x44, 0x44, 0x47,

    /* U+007C "|" */
    0xff, 0xff,

    /* U+007D "}" */
    0xe2, 0x22, 0x22, 0x21, 0x22, 0x22, 0x2e,

    /* U+007E "~" */
    0xe4, 0x70,

    /* U+4E0A "上" */
    0x2, 0x0, 0x10, 0x0, 0x80, 0x4, 0x0, 0x20,
    0x1, 0xf8, 0x8, 0x0, 0x40, 0x2, 0x0, 0x10,
    0x0, 0x81, 0xff, 0xf0,

    /* U+4E1A "业" */
    0x9, 0x0, 0x90, 0x9, 0x8, 0x91, 0x49, 0x24,
    0x92, 0x29, 0x42, 0x94, 0x9, 0x0, 0x90, 0x9,
    0xf, 0xff,

    /* U+4EE3 "代" */
    0x8, 0xa0, 0x22, 0x41, 0x8, 0x84, 0x20, 0x31,
    0xfd, 0x5a, 0x1, 0xc, 0x4, 0x10, 0x10, 0x40,
    0x41, 0x1, 0x6, 0x44, 0x9, 0x10, 0x18,

    /* U+521B "创" */
    0x8, 0x8, 0x62, 0x45, 0x92, 0x44, 0x94, 0x14,
    0x9f, 0x24, 0x89, 0x24, 0x49, 0x22, 0x49, 0x72,
    0x48, 0x42, 0x42, 0x13, 0xf7, 0x80,

    /* U+53F0 "台" */
    0x8, 0x2, 0x20, 0x82, 0x20, 0x2f, 0xfe, 0x0,
    0x1f, 0xf2, 0x2, 0x40, 0x48, 0x9, 0xff, 0x20,
    0x20,

    /* U+5B81 "宁" */
    0x4, 0x0, 0x20, 0xff, 0xf8, 0x1, 0x80, 0x10,
    0x0, 0xff, 0xf0, 0x40, 0x4, 0x0, 0x40, 0x4,
    0x0, 0x40, 0x1c, 0x0,

    /* U+5DDE "州" */
    0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x59, 0x95,
    0x55, 0x55, 0x59, 0x51, 0x11, 0x12, 0x11, 0x21,
    0x16, 0x11, 0x40, 0x10,

    /* U+5FB7 "德" */
    0x10, 0x81, 0x7f, 0xd0, 0x21, 0x2f, 0xe3, 0x55,
    0x12, 0xa9, 0x9f, 0xdc, 0x0, 0xaf, 0xf9, 0x14,
    0x8a, 0x84, 0x54, 0x52, 0x3e, 0x0,

    /* U+6210 "成" */
    0x1, 0x40, 0x9, 0x0, 0x44, 0xff, 0xf4, 0x10,
    0x3e, 0x89, 0x12, 0x88, 0x94, 0x44, 0xc2, 0x26,
    0x17, 0x73, 0x6, 0xd8, 0x63, 0x80,

    /* U+6307 "指" */
    0x22, 0x1, 0x11, 0x88, 0xf1, 0xf4, 0x12, 0x21,
    0x11, 0xf8, 0x80, 0xf, 0x7e, 0xa2, 0x11, 0x1f,
    0x88, 0x84, 0x44, 0x26, 0x3f, 0x0,

    /* U+63A7 "控" */
    0x20, 0x81, 0x4, 0xb, 0xff, 0xf0, 0x12, 0x12,
    0x13, 0x8, 0xc0, 0xc, 0xfe, 0xa0, 0x81, 0x4,
    0x8, 0x20, 0x41, 0xc, 0xff, 0x80,

    /* U+6570 "数" */
    0x10, 0x82, 0xa4, 0x14, 0x21, 0xfd, 0xf3, 0xd9,
    0x68, 0xc8, 0x42, 0x9f, 0x8c, 0x24, 0x63, 0x43,
    0x6, 0x28, 0xca, 0x28, 0x20, 0x80,

    /* U+65F6 "时" */
    0x0, 0x4f, 0x4, 0x90, 0x49, 0x7f, 0x90, 0x4f,
    0x24, 0x92, 0x49, 0x14, 0x91, 0x49, 0x4, 0xf0,
    0x40, 0x4, 0x1, 0xc0,

    /* U+677F "板" */
    0x20, 0x11, 0x1f, 0x8, 0x81, 0xf4, 0x3, 0x3f,
    0x3a, 0x89, 0xb4, 0x54, 0x94, 0xa4, 0xa5, 0x22,
    0x9, 0x38, 0x53, 0x62, 0xa1, 0x80,

    /* U+6DF1 "深" */
    0x0, 0x6, 0xff, 0x8, 0x10, 0xa5, 0x2, 0x24,
    0x42, 0x29, 0x0, 0xff, 0x21, 0x82, 0x34, 0x45,
    0x25, 0x91, 0x1, 0x0,

    /* U+80A1 "股" */
    0x79, 0xe2, 0x49, 0x12, 0x48, 0xf2, 0x44, 0xa3,
    0xa4, 0x9, 0xef, 0xc9, 0x24, 0x48, 0xe2, 0x46,
    0x22, 0x79, 0x3c, 0x30,

    /* U+817E "腾" */
    0x0, 0x1, 0xe9, 0x44, 0x88, 0x12, 0xfe, 0x7f,
    0xfd, 0x24, 0x44, 0xff, 0xde, 0x48, 0x49, 0xf9,
    0x20, 0x24, 0xbe, 0x92, 0x2, 0x98, 0x30,

    /* U+8305 "茅" */
    0x10, 0x8f, 0xff, 0x10, 0x80, 0x0, 0x7f, 0xc0,
    0x8, 0xf, 0xf, 0xff, 0xe, 0x21, 0x22, 0x62,
    0x48, 0x20, 0xe, 0x0,

    /* U+8BAF "讯" */
    0x67, 0xe1, 0x89, 0x0, 0x48, 0x2, 0x4e, 0x12,
    0x13, 0xf0, 0x84, 0x84, 0x24, 0x21, 0x21, 0xc9,
    0x48, 0x4a, 0x2, 0x30,

    /* U+8BC1 "证" */
    0x40, 0x3, 0x3f, 0xcc, 0x20, 0x1, 0x0, 0x8,
    0x71, 0x40, 0x8b, 0xc4, 0x50, 0x22, 0x81, 0x14,
    0xa, 0xa0, 0x65, 0x6, 0xff, 0x80,

    /* U+8D35 "贵" */
    0x4, 0x3, 0xfc, 0x24, 0x43, 0xfc, 0x4, 0xf,
    0xbf, 0x3f, 0xc2, 0x4, 0x24, 0x42, 0x44, 0xd,
    0x1, 0x8c, 0x60, 0x20
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 50, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 70, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 102, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 5, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 123, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 23, .adv_w = 205, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 40, .adv_w = 150, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 60, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 54, .adv_w = 74, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 60, .adv_w = 74, .box_w = 3, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 66, .adv_w = 103, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 69, .adv_w = 123, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 76, .adv_w = 60, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 77, .adv_w = 77, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 78, .adv_w = 60, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 88, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 88, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 123, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 60, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 60, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 183, .adv_w = 123, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 190, .adv_w = 123, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 193, .adv_w = 123, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 200, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 209, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 229, .adv_w = 135, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 146, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 153, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 131, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 162, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 64, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 119, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 143, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 180, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 161, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 165, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 165, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 396, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 133, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 160, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 127, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 195, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 126, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 117, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 500, .adv_w = 88, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 509, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 515, .adv_w = 123, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 520, .adv_w = 125, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 521, .adv_w = 135, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 523, .adv_w = 125, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 138, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 138, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 123, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 71, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 575, .adv_w = 135, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 60, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 60, .box_w = 3, .box_h = 14, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 592, .adv_w = 121, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 206, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 136, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 138, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 637, .adv_w = 138, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 646, .adv_w = 85, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 104, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 655, .adv_w = 83, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 135, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 177, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 109, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 701, .adv_w = 105, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 74, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 714, .adv_w = 59, .box_w = 1, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 716, .adv_w = 74, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 723, .adv_w = 123, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 725, .adv_w = 224, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 224, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 224, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 786, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 808, .adv_w = 224, .box_w = 11, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 825, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 845, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 865, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 887, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 909, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 931, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 953, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 975, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 995, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1017, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1037, .adv_w = 224, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1057, .adv_w = 224, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1080, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1100, .adv_w = 224, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1120, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1142, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x10, 0xd9, 0x411, 0x5e6, 0xd77, 0xfd4, 0x11ad,
    0x1406, 0x14fd, 0x159d, 0x1766, 0x17ec, 0x1975, 0x1fe7, 0x3297,
    0x3374, 0x34fb, 0x3da5, 0x3db7, 0x3f2b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 19978, .range_length = 16172, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 21, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 0, 0, 0, 3, 4, 3,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, 6, 0, 0, 0,
    0, 0, 7, 8, 9, 10, 11, 12,
    13, 0, 0, 14, 15, 16, 0, 0,
    10, 17, 10, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 2, 27, 0, 0,
    0, 0, 28, 29, 30, 0, 31, 32,
    33, 34, 0, 0, 35, 36, 34, 34,
    29, 29, 37, 38, 39, 40, 37, 41,
    42, 43, 44, 45, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 0, 0,
    2, 0, 3, 4, 0, 5, 6, 7,
    8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 10, 0, 0, 0,
    11, 0, 12, 0, 13, 0, 0, 0,
    13, 0, 0, 14, 0, 0, 0, 0,
    13, 0, 13, 0, 15, 16, 17, 18,
    19, 20, 21, 22, 0, 23, 3, 0,
    0, 0, 24, 0, 25, 25, 25, 26,
    27, 0, 28, 29, 0, 0, 30, 30,
    25, 30, 25, 30, 31, 32, 33, 34,
    35, 36, 37, 38, 0, 0, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, -28, 0, -28, 0,
    0, 0, 0, -13, 0, -23, -2, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    -8, 0, 0, 0, 0, 0, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 20, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -23, 0, -33,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -25, -5, -16, -8, 0,
    -22, 0, 0, 0, -3, 0, 0, 0,
    6, 0, 0, -11, 0, -8, -5, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    -4, -11, 0, -5, -2, -6, -16, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, -2, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, -2, -20, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -8, 0, -2, 7, 7, 0, 0, 3,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -13, 0, -24,
    0, 0, 0, 0, 0, 0, -6, -2,
    -2, 0, 0, -13, -4, -3, 0, 1,
    -3, -2, -10, 6, 0, -2, 0, 0,
    0, 0, 6, -3, -2, -2, -1, -1,
    -2, 0, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    -3, -6, 0, -1, -1, -1, -3, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -3, -2, -2, -3, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, -7, -2, -6, -4,
    -3, -1, -1, -1, -2, -2, 0, 0,
    0, 0, -5, 0, 0, 0, 0, -6,
    -2, -3, -2, 0, -3, 0, 0, 0,
    0, -9, 0, 0, 0, -4, 0, 0,
    0, -2, 0, -9, 0, -6, 0, -2,
    -2, -4, -5, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, -6, 0, -2, 0, -7,
    -2, 0, 0, 0, 0, 0, -17, 0,
    -17, -18, 0, 0, 0, -9, -2, -35,
    -5, 0, 0, 1, 1, -6, 1, -8,
    0, -8, -3, 0, -6, 0, 0, -5,
    -5, -2, -4, -4, -4, -6, -4, -6,
    0, 0, 0, -7, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, -5,
    0, -3, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, -6, 0, 0, 0,
    0, 0, 0, -10, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, -10,
    0, -6, 0, 0, 0, 0, -2, -2,
    -5, 0, -2, -4, -3, -3, -2, 0,
    -4, 0, 0, 0, -2, 0, 0, 0,
    -2, 0, 0, -8, -4, -4, -4, -4,
    -4, -3, 0, -20, 0, -37, 0, -14,
    0, 0, 0, 0, -7, 1, -6, 0,
    -5, -30, -7, -19, -14, 0, -19, 0,
    -20, 0, -3, -3, -1, 0, 0, 0,
    0, -5, -2, -8, -8, 0, -8, 0,
    0, 0, 0, 0, -27, -9, -27, -20,
    0, 0, 0, -13, 0, -37, -2, -6,
    0, 0, 0, -6, -2, -20, 0, -11,
    -6, 0, -8, 0, 0, 0, -2, 0,
    0, 0, 0, -3, 0, -5, 0, 0,
    0, -2, 0, -8, 0, 0, 0, 0,
    0, -1, 0, -4, -3, -3, 0, 2,
    2, -1, 0, -2, 0, -1, -2, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -2, 0, 0, 0, -4,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, -3, -3, -5, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -26, -18,
    -26, -23, -5, -5, 0, -10, -6, -32,
    -10, 0, 0, 0, 0, -5, -3, -14,
    0, -18, -16, -4, -18, 0, 0, -12,
    -15, -4, -12, -9, -9, -10, -9, -19,
    0, 0, 0, 0, -4, 0, -4, -8,
    0, 0, 0, -4, 0, -11, -2, 0,
    0, -1, 0, -2, -3, 0, 0, -1,
    0, 0, -2, 0, 0, 0, -1, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -16, -5, -16, -12, 0, 0,
    0, -3, -2, -18, -2, 0, -2, 2,
    0, 0, 0, -5, 0, -5, -4, 0,
    -5, 0, 0, -5, -3, 0, -8, -2,
    -2, -4, -2, -6, 0, 0, 0, 0,
    -8, -2, -8, -8, 0, 0, 0, 0,
    -2, -17, -2, 0, 0, 0, 0, 0,
    0, -2, 0, -4, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -2, 0, -2, 0, -6,
    0, 0, 0, 0, 0, 1, -4, 0,
    -3, -5, -2, 0, 0, 0, 0, 0,
    0, -2, -2, -4, 0, 0, 0, 0,
    0, -4, -2, -4, -3, -2, -4, -3,
    0, 0, 0, 0, -22, -16, -22, -17,
    -6, -6, -2, -3, -3, -25, -4, -3,
    -2, 0, 0, 0, 0, -7, 0, -17,
    -10, 0, -15, 0, 0, -10, -10, -6,
    -8, -3, -6, -8, -3, -11, 0, 0,
    0, 0, 0, -9, 0, 0, 0, 0,
    0, -2, -5, -9, -8, 0, -2, -2,
    -2, 0, -3, -4, 0, -4, -6, -5,
    -4, 0, 0, 0, 0, -3, -6, -4,
    -4, -6, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -22, -8, -13, -8, 0,
    -18, 0, 0, 0, 0, 0, 9, 0,
    18, 0, 0, 0, 0, -5, -2, 0,
    4, 0, 0, 0, 0, -14, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, -6, 0, -4, -1, 0, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -7, -2, 2, -2, 0,
    0, 0, -2, 0, 0, 0, 0, -14,
    0, -5, 0, -1, -11, 0, -6, -4,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, -1, -1, -4, -1, -1, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, -3,
    0, 0, -6, 0, 0, -2, -5, 0,
    -2, 0, 0, 0, 0, -2, 0, 2,
    2, 2, 2, 0, 0, 0, 0, -9,
    0, 2, 0, 0, 0, 0, -2, 0,
    0, -5, -5, -6, 0, -4, -2, 0,
    -6, 0, -4, -4, 0, 0, -2, 0,
    0, 0, 0, -2, 0, 2, 2, -2,
    2, 0, 4, 10, 13, 0, -12, -3,
    -12, -4, 0, 0, 7, 0, 0, 0,
    0, 12, 0, 17, 12, 9, 15, 0,
    17, -5, -2, 0, -4, 0, -2, 0,
    -1, 0, 0, 4, 0, -1, 0, -3,
    0, 0, 4, -9, 0, 0, 0, 13,
    0, 0, -9, 0, 0, 0, 0, -6,
    0, 0, 0, 0, -3, 0, 0, -4,
    -3, 0, 0, 0, 9, 0, 0, 0,
    0, -1, -1, 0, 4, -3, 0, 0,
    0, -9, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, -6, 0, -2,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    4, -10, 4, 0, 4, 4, -2, 0,
    0, 0, 0, -8, 0, 0, 0, 0,
    -3, 0, 0, -2, -4, 0, -2, 0,
    -2, 0, 0, -5, -3, 0, 0, -2,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, -3, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, -6, -13, -9, 7, 7,
    0, -3, 0, -13, 0, 0, 0, 0,
    0, 0, 0, -2, 4, -6, -2, 0,
    -2, 0, 0, 0, -1, 0, 0, 7,
    5, 0, 7, -1, 0, 0, 0, -13,
    0, 2, 0, 0, 0, 0, -2, 0,
    0, 0, 0, -6, 0, -2, 0, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, -6,
    2, 3, 4, 4, -6, 0, 0, 0,
    0, -3, 0, 0, 0, 0, -1, 0,
    0, -5, -3, 0, -2, 0, 0, 0,
    -2, -5, 0, 0, 0, -4, 0, 0,
    0, 0, 0, -3, -8, -2, -8, -5,
    0, 0, 0, -3, 0, -10, 0, -5,
    0, -2, 0, 0, -3, -2, 0, -5,
    -1, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, -3, -9, 0, -9, -2, 0, 0,
    0, -1, 0, -8, 0, -6, 0, -2,
    0, -3, -6, 0, 0, -2, -1, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -3, 0, 0, -6,
    2, -3, -2, 0, 0, 2, 0, 0,
    -2, 0, -1, -9, 0, -4, 0, -2,
    -8, 0, 0, -2, -4, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -8, 0,
    -8, -4, 0, 0, 0, 0, 0, -10,
    0, -5, 0, -1, 0, -1, -2, 0,
    0, -5, -1, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, -3, 0, -6,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -7,
    0, 0, 0, 0, -8, 0, 0, -6,
    -2, 0, -2, 0, 0, 0, 0, 0,
    -2, -1, 0, 0, -1, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 45,
    .right_class_cnt     = 38,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t zhfont = {
#else
lv_font_t zhfont = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if ZHFONT*/

