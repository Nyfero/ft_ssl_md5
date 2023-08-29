#include "../../inc/ft_ssl.h"
#include <math.h>

int*    init_r() {
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

int*    init_k() {
    int *k = malloc(sizeof(int) * 64);
    for (int i = 0; i < 64; i++) {
        k[i] = (int)(floor(sin(i + 1)) * pow(2, 32));
        // k[i] = i;
    }
    return k;
}