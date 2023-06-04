/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --font /home/hiruna/code/hiruna/esp32-electric-desk-controller/squareline_project/assets/fonts/FontAwesome/Font Awesome 6 Free-Regular-400.otf -o /home/hiruna/code/hiruna/esp32-electric-desk-controller/squareline_project/assets/fonts/FontAwesome/ui_font_FontAwesomeRegular12.c --format lvgl -r 0x20-0xff --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTAWESOMEREGULAR12
#define UI_FONT_FONTAWESOMEREGULAR12 1
#endif

#if UI_FONT_FONTAWESOMEREGULAR12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x20,

    /* U+0022 "\"" */
    0x0,

    /* U+0023 "#" */
    0x0, 0x1, 0x30, 0x64, 0x3f, 0xf1, 0x10, 0x22,
    0x4, 0xc0, 0x90, 0xff, 0xc4, 0x40, 0x88, 0x0,
    0x0,

    /* U+0024 "$" */
    0x10, 0x21, 0xf4, 0x8, 0xe, 0x7, 0x1, 0x3,
    0xf8, 0x40, 0x80,

    /* U+0025 "%" */
    0xc0, 0xe0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x86, 0x83, 0x0,

    /* U+0026 "&" */
    0x0,

    /* U+0027 "'" */
    0x0,

    /* U+0028 "(" */
    0x0,

    /* U+0029 ")" */
    0x0,

    /* U+002A "*" */
    0x8, 0x4, 0x22, 0x3d, 0x73, 0xe0, 0xe0, 0xf9,
    0xd7, 0x88, 0x84, 0x2, 0x0,

    /* U+002B "+" */
    0x8, 0x4, 0x2, 0x1, 0x0, 0x87, 0xfc, 0x20,
    0x10, 0x8, 0x4, 0x0,

    /* U+002C "," */
    0x0,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0x0,

    /* U+002F "/" */
    0x0,

    /* U+0030 "0" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0031 "1" */
    0x11, 0xc5, 0x4, 0x10, 0x41, 0x4, 0x10, 0x47,
    0xc0,

    /* U+0032 "2" */
    0x38, 0x44, 0x82, 0x2, 0x2, 0x4, 0xc, 0x18,
    0x30, 0x60, 0xff,

    /* U+0033 "3" */
    0xfe, 0x18, 0x60, 0x83, 0xf, 0x81, 0x81, 0x3,
    0xf, 0xf0,

    /* U+0034 "4" */
    0x0, 0x8, 0x8, 0x4, 0x44, 0x22, 0x12, 0x9,
    0xff, 0x2, 0x1, 0x0, 0x80,

    /* U+0035 "5" */
    0xfd, 0x2, 0x4, 0x8, 0x1f, 0x81, 0x81, 0x3,
    0xf, 0xf0,

    /* U+0036 "6" */
    0x8, 0x20, 0xc3, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0037 "7" */
    0xfe, 0x2, 0x4, 0xc, 0x8, 0x18, 0x10, 0x20,
    0x20, 0x40, 0x40,

    /* U+0038 "8" */
    0x7d, 0x8e, 0xc, 0x1c, 0x6f, 0xb1, 0xc1, 0x83,
    0x8d, 0xf0,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c, 0x18,
    0x20, 0x80,

    /* U+003A ":" */
    0x0,

    /* U+003B ";" */
    0x0,

    /* U+003C "<" */
    0x1, 0x83, 0x87, 0xe, 0xc, 0x3, 0x80, 0x70,
    0xe, 0x1, 0x80,

    /* U+003D "=" */
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xff, 0xc0,

    /* U+003E ">" */
    0xc0, 0x38, 0x7, 0x0, 0xe0, 0x18, 0x38, 0x70,
    0xe0, 0xc0, 0x0,

    /* U+003F "?" */
    0x79, 0x8a, 0xc, 0x10, 0x21, 0x86, 0x8, 0x0,
    0x0, 0x40,

    /* U+0040 "@" */
    0xf, 0x3, 0xc, 0x40, 0x64, 0xfa, 0x99, 0x99,
    0x9, 0x90, 0x99, 0x99, 0xcf, 0x64, 0x0, 0x30,
    0x1, 0xc0,

    /* U+0041 "A" */
    0x8, 0xe, 0x5, 0x2, 0x82, 0x21, 0x11, 0x8c,
    0xfe, 0xc1, 0xc0, 0x40,

    /* U+0042 "B" */
    0xfd, 0xe, 0xc, 0x18, 0x7f, 0xa1, 0xc1, 0x83,
    0xf, 0xf0,

    /* U+0043 "C" */
    0x0, 0x1f, 0x88, 0x28, 0x4, 0x4, 0x2, 0x0,
    0x80, 0x40, 0x10, 0x4e, 0xe0, 0x80,

    /* U+0044 "D" */
    0xfc, 0x41, 0x20, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x81, 0x41, 0x3f, 0x0,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x3, 0xf8,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x0,

    /* U+0047 "G" */
    0x1e, 0x8, 0x64, 0x2, 0x0, 0x80, 0x21, 0xf8,
    0x6, 0x1, 0x40, 0xc8, 0x61, 0xe0,

    /* U+0048 "H" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x20,

    /* U+0049 "I" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+004A "J" */
    0x2, 0x4, 0x8, 0x10, 0x20, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+004B "K" */
    0x83, 0xe, 0x34, 0xcb, 0x1e, 0x36, 0x46, 0x85,
    0x6, 0x8,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x3, 0xf8,

    /* U+004D "M" */
    0x80, 0x70, 0x3c, 0xe, 0x85, 0xb3, 0x64, 0x99,
    0xe6, 0x31, 0x80, 0x60, 0x18, 0x4,

    /* U+004E "N" */
    0x80, 0xe0, 0x78, 0x36, 0x19, 0xc, 0x46, 0x13,
    0xd, 0x83, 0xc0, 0xe0, 0x20,

    /* U+004F "O" */
    0xe, 0x6, 0x31, 0x1, 0x60, 0x38, 0x3, 0x0,
    0x60, 0xe, 0x3, 0x40, 0x46, 0x30, 0x38, 0x0,

    /* U+0050 "P" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0051 "Q" */
    0x1e, 0x8, 0x44, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x66, 0x9, 0x41, 0x88, 0x61, 0xec, 0x1,

    /* U+0052 "R" */
    0xfd, 0xa, 0xc, 0x18, 0x30, 0xbf, 0x44, 0x8d,
    0xe, 0x8,

    /* U+0053 "S" */
    0x7c, 0xc4, 0x80, 0x80, 0x60, 0x3c, 0x6, 0x2,
    0x2, 0xc6, 0x3c,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+0055 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0xc1, 0x31, 0x8f, 0x0,

    /* U+0056 "V" */
    0x80, 0xc0, 0x50, 0x48, 0x26, 0x31, 0x10, 0x98,
    0x28, 0x14, 0xe, 0x2, 0x0,

    /* U+0057 "W" */
    0x82, 0x2, 0xc, 0x24, 0x30, 0x91, 0xc6, 0x45,
    0x10, 0x92, 0x42, 0xcb, 0xa, 0x28, 0x18, 0xe0,
    0x61, 0x1, 0x84, 0x0,

    /* U+0058 "X" */
    0x80, 0xa0, 0x98, 0xc6, 0xc1, 0x40, 0x40, 0x50,
    0x6c, 0x63, 0x20, 0xa0, 0x20,

    /* U+0059 "Y" */
    0x80, 0xe0, 0xd0, 0x44, 0x43, 0x60, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+005A "Z" */
    0xff, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x40, 0x60,
    0x60, 0x60, 0x20, 0x3f, 0xe0,

    /* U+005B "[" */
    0x0,

    /* U+005C "\\" */
    0x0,

    /* U+005D "]" */
    0x0,

    /* U+005E "^" */
    0x0,

    /* U+005F "_" */
    0x0,

    /* U+0060 "`" */
    0x0,

    /* U+0061 "a" */
    0x8, 0xe, 0x5, 0x2, 0x82, 0x21, 0x11, 0x8c,
    0xfe, 0xc1, 0xc0, 0x40,

    /* U+0062 "b" */
    0xfd, 0xe, 0xc, 0x18, 0x7f, 0xa1, 0xc1, 0x83,
    0xf, 0xf0,

    /* U+0063 "c" */
    0x0, 0x1f, 0x88, 0x28, 0x4, 0x4, 0x2, 0x0,
    0x80, 0x40, 0x10, 0x4e, 0xe0, 0x80,

    /* U+0064 "d" */
    0xfc, 0x41, 0x20, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x81, 0x41, 0x3f, 0x0,

    /* U+0065 "e" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x3, 0xf8,

    /* U+0066 "f" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x0,

    /* U+0067 "g" */
    0x1e, 0x8, 0x64, 0x2, 0x0, 0x80, 0x21, 0xf8,
    0x6, 0x1, 0x40, 0xc8, 0x61, 0xe0,

    /* U+0068 "h" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x20,

    /* U+0069 "i" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x23, 0xf8,

    /* U+006A "j" */
    0x2, 0x4, 0x8, 0x10, 0x20, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+006B "k" */
    0x83, 0xe, 0x34, 0xcb, 0x1e, 0x36, 0x46, 0x85,
    0x6, 0x8,

    /* U+006C "l" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x3, 0xf8,

    /* U+006D "m" */
    0x80, 0x70, 0x3c, 0xe, 0x85, 0xb3, 0x64, 0x99,
    0xe6, 0x31, 0x80, 0x60, 0x18, 0x4,

    /* U+006E "n" */
    0x80, 0xe0, 0x78, 0x36, 0x19, 0xc, 0x46, 0x13,
    0xd, 0x83, 0xc0, 0xe0, 0x20,

    /* U+006F "o" */
    0xe, 0x6, 0x31, 0x1, 0x60, 0x38, 0x3, 0x0,
    0x60, 0xe, 0x3, 0x40, 0x46, 0x30, 0x38, 0x0,

    /* U+0070 "p" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0x1e, 0x8, 0x44, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x66, 0x9, 0x41, 0x88, 0x61, 0xec, 0x1,

    /* U+0072 "r" */
    0xfd, 0xa, 0xc, 0x18, 0x30, 0xbf, 0x44, 0x8d,
    0xe, 0x8,

    /* U+0073 "s" */
    0x7c, 0xc4, 0x80, 0x80, 0x60, 0x3c, 0x6, 0x2,
    0x2, 0xc6, 0x3c,

    /* U+0074 "t" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+0075 "u" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0xc1, 0x31, 0x8f, 0x0,

    /* U+0076 "v" */
    0x80, 0xc0, 0x50, 0x48, 0x26, 0x31, 0x10, 0x98,
    0x28, 0x14, 0xe, 0x2, 0x0,

    /* U+0077 "w" */
    0x82, 0x2, 0xc, 0x24, 0x30, 0x91, 0xc6, 0x45,
    0x10, 0x92, 0x42, 0xcb, 0xa, 0x28, 0x18, 0xe0,
    0x61, 0x1, 0x84, 0x0,

    /* U+0078 "x" */
    0x80, 0xa0, 0x98, 0xc6, 0xc1, 0x40, 0x40, 0x50,
    0x6c, 0x63, 0x20, 0xa0, 0x20,

    /* U+0079 "y" */
    0x80, 0xe0, 0xd0, 0x44, 0x43, 0x60, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+007A "z" */
    0xff, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0x40, 0x60,
    0x60, 0x60, 0x20, 0x3f, 0xe0,

    /* U+007B "{" */
    0x0,

    /* U+007C "|" */
    0x0,

    /* U+007D "}" */
    0x0,

    /* U+007E "~" */
    0x0,

    /* U+007F "" */
    0x0,

    /* U+0080 "" */
    0x0,

    /* U+0081 "" */
    0x0,

    /* U+0082 "" */
    0x0,

    /* U+0083 "" */
    0x0,

    /* U+0084 "" */
    0x0,

    /* U+0085 "" */
    0x0,

    /* U+0086 "" */
    0x0,

    /* U+0087 "" */
    0x0,

    /* U+0088 "" */
    0x0,

    /* U+0089 "" */
    0x0,

    /* U+008A "" */
    0x0,

    /* U+008B "" */
    0x0,

    /* U+008C "" */
    0x0,

    /* U+008D "" */
    0x0,

    /* U+008E "" */
    0x0,

    /* U+008F "" */
    0x0,

    /* U+0090 "" */
    0x0,

    /* U+0091 "" */
    0x0,

    /* U+0092 "" */
    0x0,

    /* U+0093 "" */
    0x0,

    /* U+0094 "" */
    0x0,

    /* U+0095 "" */
    0x0,

    /* U+0096 "" */
    0x0,

    /* U+0097 "" */
    0x0,

    /* U+0098 "" */
    0x0,

    /* U+0099 "" */
    0x0,

    /* U+009A "" */
    0x0,

    /* U+009B "" */
    0x0,

    /* U+009C "" */
    0x0,

    /* U+009D "" */
    0x0,

    /* U+009E "" */
    0x0,

    /* U+009F "" */
    0x0,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0x0,

    /* U+00A2 "¢" */
    0x0,

    /* U+00A3 "£" */
    0x0,

    /* U+00A4 "¤" */
    0x0,

    /* U+00A5 "¥" */
    0x0,

    /* U+00A6 "¦" */
    0x0,

    /* U+00A7 "§" */
    0x0,

    /* U+00A8 "¨" */
    0x0,

    /* U+00A9 "©" */
    0xf, 0x3, 0xc, 0x60, 0x64, 0x62, 0x89, 0x19,
    0x1, 0x90, 0x18, 0x91, 0x46, 0x26, 0x6, 0x30,
    0xc0, 0xf0,

    /* U+00AA "ª" */
    0x0,

    /* U+00AB "«" */
    0x0,

    /* U+00AC "¬" */
    0x0,

    /* U+00AD "­" */
    0x0,

    /* U+00AE "®" */
    0xf, 0x3, 0xc, 0x60, 0x64, 0xe2, 0x89, 0x18,
    0x91, 0x8e, 0x18, 0xb1, 0x49, 0x26, 0x6, 0x30,
    0xc0, 0xf0,

    /* U+00AF "¯" */
    0x0,

    /* U+00B0 "°" */
    0x0,

    /* U+00B1 "±" */
    0x0,

    /* U+00B2 "²" */
    0x0,

    /* U+00B3 "³" */
    0x0,

    /* U+00B4 "´" */
    0x0,

    /* U+00B5 "µ" */
    0x0,

    /* U+00B6 "¶" */
    0x0,

    /* U+00B7 "·" */
    0x0,

    /* U+00B8 "¸" */
    0x0,

    /* U+00B9 "¹" */
    0x0,

    /* U+00BA "º" */
    0x0,

    /* U+00BB "»" */
    0x0,

    /* U+00BC "¼" */
    0x0,

    /* U+00BD "½" */
    0x0,

    /* U+00BE "¾" */
    0x0,

    /* U+00BF "¿" */
    0x0,

    /* U+00C0 "À" */
    0x0,

    /* U+00C1 "Á" */
    0x0,

    /* U+00C2 "Â" */
    0x0,

    /* U+00C3 "Ã" */
    0x0,

    /* U+00C4 "Ä" */
    0x0,

    /* U+00C5 "Å" */
    0x0,

    /* U+00C6 "Æ" */
    0x0,

    /* U+00C7 "Ç" */
    0x0,

    /* U+00C8 "È" */
    0x0,

    /* U+00C9 "É" */
    0x0,

    /* U+00CA "Ê" */
    0x0,

    /* U+00CB "Ë" */
    0x0,

    /* U+00CC "Ì" */
    0x0,

    /* U+00CD "Í" */
    0x0,

    /* U+00CE "Î" */
    0x0,

    /* U+00CF "Ï" */
    0x0,

    /* U+00D0 "Ð" */
    0x0,

    /* U+00D1 "Ñ" */
    0x0,

    /* U+00D2 "Ò" */
    0x0,

    /* U+00D3 "Ó" */
    0x0,

    /* U+00D4 "Ô" */
    0x0,

    /* U+00D5 "Õ" */
    0x0,

    /* U+00D6 "Ö" */
    0x0,

    /* U+00D7 "×" */
    0x0,

    /* U+00D8 "Ø" */
    0x0,

    /* U+00D9 "Ù" */
    0x0,

    /* U+00DA "Ú" */
    0x0,

    /* U+00DB "Û" */
    0x0,

    /* U+00DC "Ü" */
    0x0,

    /* U+00DD "Ý" */
    0x0,

    /* U+00DE "Þ" */
    0x0,

    /* U+00DF "ß" */
    0x0,

    /* U+00E0 "à" */
    0x0,

    /* U+00E1 "á" */
    0x0,

    /* U+00E2 "â" */
    0x0,

    /* U+00E3 "ã" */
    0x0,

    /* U+00E4 "ä" */
    0x0,

    /* U+00E5 "å" */
    0x0,

    /* U+00E6 "æ" */
    0x0,

    /* U+00E7 "ç" */
    0x0,

    /* U+00E8 "è" */
    0x0,

    /* U+00E9 "é" */
    0x0,

    /* U+00EA "ê" */
    0x0,

    /* U+00EB "ë" */
    0x0,

    /* U+00EC "ì" */
    0x0,

    /* U+00ED "í" */
    0x0,

    /* U+00EE "î" */
    0x0,

    /* U+00EF "ï" */
    0x0,

    /* U+00F0 "ð" */
    0x0,

    /* U+00F1 "ñ" */
    0x0,

    /* U+00F2 "ò" */
    0x0,

    /* U+00F3 "ó" */
    0x0,

    /* U+00F4 "ô" */
    0x0,

    /* U+00F5 "õ" */
    0x0,

    /* U+00F6 "ö" */
    0x0,

    /* U+00F7 "÷" */
    0x0,

    /* U+00F8 "ø" */
    0x0,

    /* U+00F9 "ù" */
    0x0,

    /* U+00FA "ú" */
    0x0,

    /* U+00FB "û" */
    0x0,

    /* U+00FC "ü" */
    0x0,

    /* U+00FD "ý" */
    0x0,

    /* U+00FE "þ" */
    0x0,

    /* U+00FF "ÿ" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 72, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 24, .box_w = 1, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 168, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 21, .adv_w = 120, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 32, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 60, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 120, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 74, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 86, .adv_w = 96, .box_w = 6, .box_h = 11, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 95, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 106, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 116, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 129, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 139, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 149, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 160, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 170, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 180, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 168, .box_w = 10, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 200, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 221, .adv_w = 192, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 239, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 261, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 275, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 288, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 298, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 308, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 322, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 335, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 345, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 355, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 365, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 375, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 389, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 402, .adv_w = 168, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 418, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 428, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 443, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 453, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 464, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 477, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 490, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 503, .adv_w = 216, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 523, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 536, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 549, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 562, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 590, .adv_w = 144, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 604, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 617, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 627, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 637, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 651, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 664, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 674, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 684, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 694, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 704, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 718, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 731, .adv_w = 168, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 747, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 757, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 772, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 782, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 793, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 806, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 819, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 832, .adv_w = 216, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 852, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 865, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 878, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 891, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 893, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 896, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 898, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 902, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 904, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 909, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 910, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 912, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 914, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 918, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 919, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 922, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 924, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 930, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 931, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 932, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 933, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 936, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 937, .adv_w = 192, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 955, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 956, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 958, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 959, .adv_w = 192, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 977, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 978, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 980, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 981, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 983, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 984, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 985, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 986, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 987, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 988, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 989, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 990, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 994, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 995, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 996, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 997, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 999, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1000, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1002, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1003, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1004, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1005, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1006, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1007, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1008, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1010, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1011, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1012, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1013, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1014, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1015, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1016, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1018, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1019, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1020, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1022, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1024, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1025, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1026, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1027, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1028, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1029, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1032, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1033, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1035, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1036, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1037, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1038, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1039, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1041, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1042, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1043, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1044, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1045, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1047, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1048, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1049, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1052, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1053, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1055, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1056, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1057, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 224, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
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
const lv_font_t ui_font_FontAwesomeRegular12 = {
#else
lv_font_t ui_font_FontAwesomeRegular12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONTAWESOMEREGULAR12*/

