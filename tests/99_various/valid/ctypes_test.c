// Exit code: 0
#include <ctype.h>

/* Bitmask flags for C99 ctype classifications */
#define _ALNUM  (1 << 0)
#define _ALPHA  (1 << 1)
#define _CNTRL  (1 << 2)
#define _DIGIT  (1 << 3)
#define _GRAPH  (1 << 4)
#define _LOWER  (1 << 5)
#define _PRINT  (1 << 6)
#define _PUNCT  (1 << 7)
#define _SPACE  (1 << 8)
#define _UPPER  (1 << 9)
#define _XDIGIT (1 << 10)
#define _BLANK  (1 << 11)

/* Macro as requested: returns 0 if >= 128, else returns TAB entry */
#define TYPES(x) do { \
    if ((x) < 0 || (x) >= 128) return 0; \
    else return TAB[(x)]; \
} while (0)

/* * TAB Population: Strict C99 Standard 
 * Each index corresponds to the ASCII value.
 */
static const int TAB[128] = {
    _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, /* 0-7: NUL, SOH, STX, ETX, EOT, ENQ, ACK, BEL */
    _CNTRL, _CNTRL|_SPACE|_BLANK, _CNTRL|_SPACE, _CNTRL|_SPACE, _CNTRL|_SPACE, _CNTRL|_SPACE, _CNTRL, _CNTRL, /* 8-15: BS, HT(\t), LF(\n), VT, FF, CR, SO, SI */
    _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, /* 16-23: DLE, DC1, DC2, DC3, DC4, NAK, SYN, ETB */
    _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, _CNTRL, /* 24-31: CAN, EM, SUB, ESC, FS, GS, RS, US */
    _SPACE|_PRINT|_BLANK,                                           /* 32: Space */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 33-35: !, ", # */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 36-38: $, %, & */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 39-41: ', (, ) */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 42-44: *, +, , */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 45-47: -, ., / */
    _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, /* 48-49: 0, 1 */
    _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, /* 50-51: 2, 3 */
    _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, /* 52-53: 4, 5 */
    _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, /* 54-55: 6, 7 */
    _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, _DIGIT|_ALNUM|_GRAPH|_PRINT|_XDIGIT, /* 56-57: 8, 9 */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 58-60: :, ;, < */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 61-63: =, >, ? */
    _PUNCT|_GRAPH|_PRINT,                                           /* 64: @ */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 65: A */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 66: B */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 67: C */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 68: D */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 69: E */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 70: F */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT,                             /* 71: G */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 72-73: H, I */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 74-75: J, K */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 76-77: L, M */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 78-79: N, O */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 80-81: P, Q */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 82-83: R, S */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 84-85: T, U */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 86-87: V, W */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 88-89: X, Y */
    _UPPER|_ALPHA|_ALNUM|_GRAPH|_PRINT,                             /* 90: Z */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 91-93: [, \, ] */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 94-96: ^, _, ` */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 97: a */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 98: b */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 99: c */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 100: d */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 101: e */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT|_XDIGIT,                     /* 102: f */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT,                             /* 103: g */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 104-105: h, i */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 106-107: j, k */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 108-109: l, m */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 110-111: n, o */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 112-113: p, q */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 114-115: r, s */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 116-117: t, u */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 118-119: v, w */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT, /* 120-121: x, y */
    _LOWER|_ALPHA|_ALNUM|_GRAPH|_PRINT,                             /* 122: z */
    _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, _PUNCT|_GRAPH|_PRINT, /* 123-125: {, |, } */
    _PUNCT|_GRAPH|_PRINT,                                           /* 126: ~ */
    _CNTRL                                                          /* 127: DEL */
};

int get_bits(int c) {
    TYPES(c);
}

int main(void) {
    for (int i = 0; i < 128; i++) {
        int expected = get_bits(i);

        if (!!isalnum(i)  != !!(expected & _ALNUM))  return (i * 12) + 1;
        if (!!isalpha(i)  != !!(expected & _ALPHA))  return (i * 12) + 2;
        if (!!iscntrl(i)  != !!(expected & _CNTRL))  return (i * 12) + 3;
        if (!!isdigit(i)  != !!(expected & _DIGIT))  return (i * 12) + 4;
        if (!!isgraph(i)  != !!(expected & _GRAPH))  return (i * 12) + 5;
        if (!!islower(i)  != !!(expected & _LOWER))  return (i * 12) + 6;
        if (!!isprint(i)  != !!(expected & _PRINT))  return (i * 12) + 7;
        if (!!ispunct(i)  != !!(expected & _PUNCT))  return (i * 12) + 8;
        if (!!isspace(i)  != !!(expected & _SPACE))  return (i * 12) + 9;
        if (!!isupper(i)  != !!(expected & _UPPER))  return (i * 12) + 10;
        if (!!isxdigit(i) != !!(expected & _XDIGIT)) return (i * 12) + 11;
        if (!!isblank(i)  != !!(expected & _BLANK))  return (i * 12) + 12;
    }
    return 0;
}