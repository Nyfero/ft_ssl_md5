#include "../../inc/ft_md5.h"

void print_r(t_md5 *md5) {
    printf("\n*****r*****\n");
    for (int i = 0; i < 64; i++) {
        printf("%u ", md5->r[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_k(t_md5 *md5) {
    printf("\n*****k*****\n");
    for (int i = 0; i < 64; i++) {
        printf("%u ", md5->k[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_h0123(t_md5 *md5) {
    printf("\n*****h*****\n");
    printf("h0: %u\n", md5->h0);
    printf("h1: %u\n", md5->h1);
    printf("h2: %u\n", md5->h2);
    printf("h3: %u\n", md5->h3);
    printf("\n***************\n");
    printf("\n");
}

void print_abcd(t_md5 *md5) {
    printf("\n*****fd*****\n");
    printf("a: %u\n", md5->a);
    printf("b: %u\n", md5->b);
    printf("c: %u\n", md5->c);
    printf("d: %u\n", md5->d);
    printf("\n***************\n");
    printf("\n");
}

void print_t_md5(t_md5 *md5) {
    printf("\n*****t_md5*****\n");
    print_r(md5);
    print_k(md5);
    print_h0123(md5);
    print_abcd(md5);
    printf("\n*****t_md5*****\n");
    printf("\n");
}