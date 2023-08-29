#include "../../inc/ft_ssl.h"

static int*    init_r() {
    int *r = malloc(sizeof(int) * 64);
    int i = 0;
    for (int j = 0; j < 4; j++) {
        r[i++] = 7;
        r[i++] = 12;
        r[i++] = 17;
        r[i++] = 22;
    }
    for (int j = 0; j < 4; j++) {
        r[i++] = 5;
        r[i++] = 9;
        r[i++] = 14;
        r[i++] = 20;
    }
    for (int j = 0; j < 4; j++) {
        r[i++] = 4;
        r[i++] = 11;
        r[i++] = 16;
        r[i++] = 23;
    }
    for (int j = 0; j < 4; j++) {
        r[i++] = 6;
        r[i++] = 10;
        r[i++] = 15;
        r[i++] = 21;
    }
    return r;
}

static float*    init_k() {
    float *k = malloc(sizeof(int) * 64);
    for (int i = 0; i < 64; i++) {
        k[i] = (floor(fabs(sin(i + 1)) * pow(2, 32)));
    }
    return k;
}

int init_md5() {
    printf("MD5\n");

    int *r = init_r();
    float *k = init_k();
    int h0 = 0x67452301;
    int h1 = 0xEFCDAB89;
    int h2 = 0x98BADCFE;
    int h3 = 0x10325476;

    (void)r;
    (void)k;
    (void)h0;
    (void)h1;
    (void)h2;
    (void)h3;

    return 0;

}