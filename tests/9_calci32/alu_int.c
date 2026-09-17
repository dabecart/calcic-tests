#include <limits.h>

// #define DO_LONG_TESTS
// #define DO_LONGLONG_TESTS

int main(void) {
    // ========================================================================
    // 1. char 
    // ========================================================================
    {
        char a = 10, b = 3;
        if ((char)(a + b) != 13) return 1;
        if ((char)(a - b) != 7) return 2;
        if ((char)(a * b) != 30) return 3;
        if ((char)(a / b) != 3) return 4;
        if ((char)(a % b) != 1) return 5;
        if ((char)(a & b) != 2) return 6;
        if ((char)(a | b) != 11) return 7;
        if ((char)(a ^ b) != 9) return 8;
        if ((char)(a << 1) != 20) return 9;
        if ((char)(a >> 1) != 5) return 10;
        if ((char)(~a) != (char)-11) return 11;
        if ((char)(-a) != (char)-10) return 12;
        if ((char)(+a) != 10) return 13;

        if (a++ != 10) return 14;
        if (++a != 12) return 15;
        if (a-- != 12) return 16;
        if (--a != 10) return 17;

        if ((a += b) != 13) return 18;
        if ((a -= b) != 10) return 19;
        if ((a *= b) != 30) return 20;
        if ((a /= b) != 10) return 21;
        if ((a %= b) != 1) return 22;

        a = 10; if ((a &= b) != 2) return 23;
        a = 10; if ((a |= b) != 11) return 24;
        a = 10; if ((a ^= b) != 9) return 25;
        a = 10; if ((a <<= 1) != 20) return 26;
        a = 10; if ((a >>= 1) != 5) return 27;
    }

    // ========================================================================
    // 2. signed char
    // ========================================================================
    {
        signed char a = 10, b = 3;
        if ((signed char)(a + b) != 13) return 28;
        if ((signed char)(a - b) != 7) return 29;
        if ((signed char)(a * b) != 30) return 30;
        if ((signed char)(a / b) != 3) return 31;
        if ((signed char)(a % b) != 1) return 32;
        if ((signed char)(a & b) != 2) return 33;
        if ((signed char)(a | b) != 11) return 34;
        if ((signed char)(a ^ b) != 9) return 35;
        if ((signed char)(a << 1) != 20) return 36;
        if ((signed char)(a >> 1) != 5) return 37;
        if ((signed char)(~a) != (signed char)-11) return 38;
        if ((signed char)(-a) != (signed char)-10) return 39;
        if ((signed char)(+a) != 10) return 40;

        if (a++ != 10) return 41;
        if (++a != 12) return 42;
        if (a-- != 12) return 43;
        if (--a != 10) return 44;

        if ((a += b) != 13) return 45;
        if ((a -= b) != 10) return 46;
        if ((a *= b) != 30) return 47;
        if ((a /= b) != 10) return 48;
        if ((a %= b) != 1) return 49;

        a = 10; if ((a &= b) != 2) return 50;
        a = 10; if ((a |= b) != 11) return 51;
        a = 10; if ((a ^= b) != 9) return 52;
        a = 10; if ((a <<= 1) != 20) return 53;
        a = 10; if ((a >>= 1) != 5) return 54;
    }

    // ========================================================================
    // 3. unsigned char
    // ========================================================================
    {
        unsigned char a = 10, b = 3;
        if ((unsigned char)(a + b) != 13) return 55;
        if ((unsigned char)(a - b) != 7) return 56;
        if ((unsigned char)(a * b) != 30) return 57;
        if ((unsigned char)(a / b) != 3) return 58;
        if ((unsigned char)(a % b) != 1) return 59;
        if ((unsigned char)(a & b) != 2) return 60;
        if ((unsigned char)(a | b) != 11) return 61;
        if ((unsigned char)(a ^ b) != 9) return 62;
        if ((unsigned char)(a << 1) != 20) return 63;
        if ((unsigned char)(a >> 1) != 5) return 64;
        if ((unsigned char)(~a) != (unsigned char)-11) return 65;
        if ((unsigned char)(-a) != (unsigned char)-10) return 66;
        if ((unsigned char)(+a) != 10) return 67;

        if (a++ != 10) return 68;
        if (++a != 12) return 69;
        if (a-- != 12) return 70;
        if (--a != 10) return 71;

        if ((a += b) != 13) return 72;
        if ((a -= b) != 10) return 73;
        if ((a *= b) != 30) return 74;
        if ((a /= b) != 10) return 75;
        if ((a %= b) != 1) return 76;

        a = 10; if ((a &= b) != 2) return 77;
        a = 10; if ((a |= b) != 11) return 78;
        a = 10; if ((a ^= b) != 9) return 79;
        a = 10; if ((a <<= 1) != 20) return 80;
        a = 10; if ((a >>= 1) != 5) return 81;
    }

    // ========================================================================
    // 4. short
    // ========================================================================
    {
        short a = 10, b = 3;
        if ((short)(a + b) != 13) return 82;
        if ((short)(a - b) != 7) return 83;
        if ((short)(a * b) != 30) return 84;
        if ((short)(a / b) != 3) return 85;
        if ((short)(a % b) != 1) return 86;
        if ((short)(a & b) != 2) return 87;
        if ((short)(a | b) != 11) return 88;
        if ((short)(a ^ b) != 9) return 89;
        if ((short)(a << 1) != 20) return 90;
        if ((short)(a >> 1) != 5) return 91;
        if ((short)(~a) != (short)-11) return 92;
        if ((short)(-a) != (short)-10) return 93;
        if ((short)(+a) != 10) return 94;

        if (a++ != 10) return 95;
        if (++a != 12) return 96;
        if (a-- != 12) return 97;
        if (--a != 10) return 98;

        if ((a += b) != 13) return 99;
        if ((a -= b) != 10) return 100;
        if ((a *= b) != 30) return 101;
        if ((a /= b) != 10) return 102;
        if ((a %= b) != 1) return 103;

        a = 10; if ((a &= b) != 2) return 104;
        a = 10; if ((a |= b) != 11) return 105;
        a = 10; if ((a ^= b) != 9) return 106;
        a = 10; if ((a <<= 1) != 20) return 107;
        a = 10; if ((a >>= 1) != 5) return 108;
    }

    // ========================================================================
    // 5. unsigned short
    // ========================================================================
    {
        unsigned short a = 10, b = 3;
        if ((unsigned short)(a + b) != 13) return 109;
        if ((unsigned short)(a - b) != 7) return 110;
        if ((unsigned short)(a * b) != 30) return 111;
        if ((unsigned short)(a / b) != 3) return 112;
        if ((unsigned short)(a % b) != 1) return 113;
        if ((unsigned short)(a & b) != 2) return 114;
        if ((unsigned short)(a | b) != 11) return 115;
        if ((unsigned short)(a ^ b) != 9) return 116;
        if ((unsigned short)(a << 1) != 20) return 117;
        if ((unsigned short)(a >> 1) != 5) return 118;
        if ((unsigned short)(~a) != (unsigned short)-11) return 119;
        if ((unsigned short)(-a) != (unsigned short)-10) return 120;
        if ((unsigned short)(+a) != 10) return 121;

        if (a++ != 10) return 122;
        if (++a != 12) return 123;
        if (a-- != 12) return 124;
        if (--a != 10) return 125;

        if ((a += b) != 13) return 126;
        if ((a -= b) != 10) return 127;
        if ((a *= b) != 30) return 128;
        if ((a /= b) != 10) return 129;
        if ((a %= b) != 1) return 130;

        a = 10; if ((a &= b) != 2) return 131;
        a = 10; if ((a |= b) != 11) return 132;
        a = 10; if ((a ^= b) != 9) return 133;
        a = 10; if ((a <<= 1) != 20) return 134;
        a = 10; if ((a >>= 1) != 5) return 135;
    }

    // ========================================================================
    // 6. int
    // ========================================================================
    {
        int a = 10, b = 3;
        if ((int)(a + b) != 13) return 136;
        if ((int)(a - b) != 7) return 137;
        if ((int)(a * b) != 30) return 138;
        if ((int)(a / b) != 3) return 139;
        if ((int)(a % b) != 1) return 140;
        if ((int)(a & b) != 2) return 141;
        if ((int)(a | b) != 11) return 142;
        if ((int)(a ^ b) != 9) return 143;
        if ((int)(a << 1) != 20) return 144;
        if ((int)(a >> 1) != 5) return 145;
        if ((int)(~a) != (int)-11) return 146;
        if ((int)(-a) != (int)-10) return 147;
        if ((int)(+a) != 10) return 148;

        if (a++ != 10) return 149;
        if (++a != 12) return 150;
        if (a-- != 12) return 151;
        if (--a != 10) return 152;

        if ((a += b) != 13) return 153;
        if ((a -= b) != 10) return 154;
        if ((a *= b) != 30) return 155;
        if ((a /= b) != 10) return 156;
        if ((a %= b) != 1) return 157;

        a = 10; if ((a &= b) != 2) return 158;
        a = 10; if ((a |= b) != 11) return 159;
        a = 10; if ((a ^= b) != 9) return 160;
        a = 10; if ((a <<= 1) != 20) return 161;
        a = 10; if ((a >>= 1) != 5) return 162;
    }

    // ========================================================================
    // 7. unsigned int
    // ========================================================================
    {
        unsigned int a = 10, b = 3;
        if ((unsigned int)(a + b) != 13) return 163;
        if ((unsigned int)(a - b) != 7) return 164;
        if ((unsigned int)(a * b) != 30) return 165;
        if ((unsigned int)(a / b) != 3) return 166;
        if ((unsigned int)(a % b) != 1) return 167;
        if ((unsigned int)(a & b) != 2) return 168;
        if ((unsigned int)(a | b) != 11) return 169;
        if ((unsigned int)(a ^ b) != 9) return 170;
        if ((unsigned int)(a << 1) != 20) return 171;
        if ((unsigned int)(a >> 1) != 5) return 172;
        if ((unsigned int)(~a) != (unsigned int)-11) return 173;
        if ((unsigned int)(-a) != (unsigned int)-10) return 174;
        if ((unsigned int)(+a) != 10) return 175;

        if (a++ != 10) return 176;
        if (++a != 12) return 177;
        if (a-- != 12) return 178;
        if (--a != 10) return 179;

        if ((a += b) != 13) return 180;
        if ((a -= b) != 10) return 181;
        if ((a *= b) != 30) return 182;
        if ((a /= b) != 10) return 183;
        if ((a %= b) != 1) return 184;

        a = 10; if ((a &= b) != 2) return 185;
        a = 10; if ((a |= b) != 11) return 186;
        a = 10; if ((a ^= b) != 9) return 187;
        a = 10; if ((a <<= 1) != 20) return 188;
        a = 10; if ((a >>= 1) != 5) return 189;
    }

#ifdef DO_LONG_TESTS
    // ========================================================================
    // 8. long
    // ========================================================================
    {
        long a = 10, b = 3;
        if ((long)(a + b) != 13) return 190;
        if ((long)(a - b) != 7) return 191;
        if ((long)(a * b) != 30) return 192;
        if ((long)(a / b) != 3) return 193;
        if ((long)(a % b) != 1) return 194;
        if ((long)(a & b) != 2) return 195;
        if ((long)(a | b) != 11) return 196;
        if ((long)(a ^ b) != 9) return 197;
        if ((long)(a << 1) != 20) return 198;
        if ((long)(a >> 1) != 5) return 199;
        if ((long)(~a) != (long)-11) return 200;
        if ((long)(-a) != (long)-10) return 201;
        if ((long)(+a) != 10) return 202;

        if (a++ != 10) return 203;
        if (++a != 12) return 204;
        if (a-- != 12) return 205;
        if (--a != 10) return 206;

        if ((a += b) != 13) return 207;
        if ((a -= b) != 10) return 208;
        if ((a *= b) != 30) return 209;
        if ((a /= b) != 10) return 210;
        if ((a %= b) != 1) return 211;

        a = 10; if ((a &= b) != 2) return 212;
        a = 10; if ((a |= b) != 11) return 213;
        a = 10; if ((a ^= b) != 9) return 214;
        a = 10; if ((a <<= 1) != 20) return 215;
        a = 10; if ((a >>= 1) != 5) return 216;
    }

    // ========================================================================
    // 9. unsigned long
    // ========================================================================
    {
        unsigned long a = 10, b = 3;
        if ((unsigned long)(a + b) != 13) return 217;
        if ((unsigned long)(a - b) != 7) return 218;
        if ((unsigned long)(a * b) != 30) return 219;
        if ((unsigned long)(a / b) != 3) return 220;
        if ((unsigned long)(a % b) != 1) return 221;
        if ((unsigned long)(a & b) != 2) return 222;
        if ((unsigned long)(a | b) != 11) return 223;
        if ((unsigned long)(a ^ b) != 9) return 224;
        if ((unsigned long)(a << 1) != 20) return 225;
        if ((unsigned long)(a >> 1) != 5) return 226;
        if ((unsigned long)(~a) != (unsigned long)-11) return 227;
        if ((unsigned long)(-a) != (unsigned long)-10) return 228;
        if ((unsigned long)(+a) != 10) return 229;

        if (a++ != 10) return 230;
        if (++a != 12) return 231;
        if (a-- != 12) return 232;
        if (--a != 10) return 233;

        if ((a += b) != 13) return 234;
        if ((a -= b) != 10) return 235;
        if ((a *= b) != 30) return 236;
        if ((a /= b) != 10) return 237;
        if ((a %= b) != 1) return 238;

        a = 10; if ((a &= b) != 2) return 239;
        a = 10; if ((a |= b) != 11) return 240;
        a = 10; if ((a ^= b) != 9) return 241;
        a = 10; if ((a <<= 1) != 20) return 242;
        a = 10; if ((a >>= 1) != 5) return 243;
    }
#endif

#ifdef DO_LONGLONG_TESTS
    // ========================================================================
    // 10. long long
    // ========================================================================
    {
        long long a = 10, b = 3;
        if ((long long)(a + b) != 13) return 244;
        if ((long long)(a - b) != 7) return 245;
        if ((long long)(a * b) != 30) return 246;
        if ((long long)(a / b) != 3) return 247;
        if ((long long)(a % b) != 1) return 248;
        if ((long long)(a & b) != 2) return 249;
        if ((long long)(a | b) != 11) return 250;
        if ((long long)(a ^ b) != 9) return 251;
        if ((long long)(a << 1) != 20) return 252;
        if ((long long)(a >> 1) != 5) return 253;
        if ((long long)(~a) != (long long)-11) return 254;
        if ((long long)(-a) != (long long)-10) return 255;
        if ((long long)(+a) != 10) return 256;

        if (a++ != 10) return 257;
        if (++a != 12) return 258;
        if (a-- != 12) return 259;
        if (--a != 10) return 260;

        if ((a += b) != 13) return 261;
        if ((a -= b) != 10) return 262;
        if ((a *= b) != 30) return 263;
        if ((a /= b) != 10) return 264;
        if ((a %= b) != 1) return 265;

        a = 10; if ((a &= b) != 2) return 266;
        a = 10; if ((a |= b) != 11) return 267;
        a = 10; if ((a ^= b) != 9) return 268;
        a = 10; if ((a <<= 1) != 20) return 269;
        a = 10; if ((a >>= 1) != 5) return 270;
    }

    // ========================================================================
    // 11. unsigned long long
    // ========================================================================
    {
        unsigned long long a = 10, b = 3;
        if ((unsigned long long)(a + b) != 13) return 271;
        if ((unsigned long long)(a - b) != 7) return 272;
        if ((unsigned long long)(a * b) != 30) return 273;
        if ((unsigned long long)(a / b) != 3) return 274;
        if ((unsigned long long)(a % b) != 1) return 275;
        if ((unsigned long long)(a & b) != 2) return 276;
        if ((unsigned long long)(a | b) != 11) return 277;
        if ((unsigned long long)(a ^ b) != 9) return 278;
        if ((unsigned long long)(a << 1) != 20) return 279;
        if ((unsigned long long)(a >> 1) != 5) return 280;
        if ((unsigned long long)(~a) != (unsigned long long)-11) return 281;
        if ((unsigned long long)(-a) != (unsigned long long)-10) return 282;
        if ((unsigned long long)(+a) != 10) return 283;

        if (a++ != 10) return 284;
        if (++a != 12) return 285;
        if (a-- != 12) return 286;
        if (--a != 10) return 287;

        if ((a += b) != 13) return 288;
        if ((a -= b) != 10) return 289;
        if ((a *= b) != 30) return 290;
        if ((a /= b) != 10) return 291;
        if ((a %= b) != 1) return 292;

        a = 10; if ((a &= b) != 2) return 293;
        a = 10; if ((a |= b) != 11) return 294;
        a = 10; if ((a ^= b) != 9) return 295;
        a = 10; if ((a <<= 1) != 20) return 296;
        a = 10; if ((a >>= 1) != 5) return 297;
    }
#endif 

    // ========================================================================
    // 12. Boundary, Overflow, and Wrapping Tests
    // (Utilizing int-promotion to safely examine overflow wrap)
    // ========================================================================
    {
        signed char sc1 = 120, sc2 = 10;
        if ((signed char)(sc1 + sc2) != -126) return 298; // Signed char overflow
        if ((signed char)(sc1 - 130) != -10) return 299;

        unsigned char uc1 = 250, uc2 = 10;
        if ((unsigned char)(uc1 + uc2) != 4) return 300;  // Unsigned char wrap
        if ((unsigned char)(uc1 - 255) != 251) return 301;

        short s1 = 32000, s2 = 1000;
        if ((short)(s1 + s2) != -32536) return 302;       // Short overflow

        unsigned short us1 = 65530, us2 = 10;
        if ((unsigned short)(us1 + us2) != 4) return 303; // Unsigned short wrap

        unsigned int ui1 = UINT_MAX;
        if (ui1 + 1U != 0U) return 304;                   // Unsigned int wrap
        unsigned int ui2 = 0U;
        if (ui2 - 1U != UINT_MAX) return 305;

#ifdef DO_LONG_TESTS
        unsigned long ul1 = ULONG_MAX;
        if (ul1 + 1UL != 0UL) return 306;                 // Unsigned long wrap
#endif 

#ifdef DO_LONGLONG_TESTS
        unsigned long long ull1 = ULLONG_MAX;
        if (ull1 + 1ULL != 0ULL) return 307;              // Unsigned long long wrap
        unsigned long long ull2 = 0ULL;
        if (ull2 - 1ULL != ULLONG_MAX) return 308;
#endif
    }

    // ========================================================================
    // 13. Explicit Integer Conversions Tests
    // ========================================================================
    {
        // Signed to Unsigned (same size boundaries)
        int i_val = -5;
        if ((unsigned int)i_val != UINT_MAX - 4) return 309;

        // Unsigned to Signed (same size boundaries)
        unsigned int ui_val = UINT_MAX;
        if ((int)ui_val != -1) return 310;

        // Widening (Signed -> Signed)
        char c_val = -10;
        if ((int)c_val != -10) return 311;

        // Widening (Unsigned -> Unsigned)
        unsigned char uc_val = 250;
        if ((unsigned int)uc_val != 250) return 312;

        // Widening with Sign Extension (Unsigned -> larger Signed)
        unsigned int ui_val2 = UINT_MAX;
        if ((int)ui_val2 != (int)UINT_MAX) return 313;

        // Narrowing (Signed -> Signed)
        int ll_val = -32536;
        if ((short)ll_val != -32536) return 314;

        // Narrowing (Unsigned -> Unsigned)
        unsigned int ui_val3 = 65540U;
        if ((unsigned short)ui_val3 != 4) return 315;

        // Narrowing (Signed -> Unsigned)
        int i_val2 = -1;
        if ((unsigned char)i_val2 != 255) return 316;

        // Narrowing (Unsigned -> Signed)
        unsigned int ui_val4 = 255U;
        if ((signed char)ui_val4 != -1) return 317;
        
#ifdef DO_LONGLONG_TESTS
        unsigned long long ull_val = 0xFFFFFFFFFFFFFFFFULL;
        if ((unsigned int)ull_val != UINT_MAX) return 318;
#endif

        unsigned int a = 0x0F0F0F0F;
        unsigned int b = 0x33333333;

        if ((a & b) != 0x03030303) return 319;
        if ((a | b) != 0x3F3F3F3F) return 320;
        if ((a ^ b) != 0x3C3C3C3C) return 321;
        if (~a != 0xF0F0F0F0) return 322;

        unsigned int shift_val = 0x000000FF;
        if ((shift_val << 8) != 0x0000FF00) return 323;
        if ((shift_val >> 4) != 0x0000000F) return 324;

        int signed_val = -128; // 0xFFFFFF80
        if ((signed_val >> 1) != -64) return 325; // Arithmetic shift right
    }

    return 0; // Success, everything behaved correctly according to C99!
}