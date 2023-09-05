#include "../../inc/ft_md5.h"

static unsigned int*    init_r() {
    unsigned int *r = malloc(sizeof(unsigned int) * 64);
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

static unsigned int*    init_k() {
    unsigned int *k = malloc(sizeof(unsigned int) * 64);
    for (int i = 0; i < 64; i++) {
        k[i] = (floor(fabs(sin(i + 1)) * pow(2, 32)));
    }
    return k;
}

static char *stringToBinary(char *s) {
    if (s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len * 8 + 1); /* over-allocate for null terminator */
    if (binary == NULL) return 0; /* malloc failed */
    binary[0] = '\0';
    for (size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for (int j = 7; j >= 0; --j) {
            if (ch & (1 << j)) {
                strcat(binary, "1");
            } else {
                strcat(binary, "0");
            }
        }
    }
    return binary;
}

static void init_string(t_ssl *ssl) {
    while (ssl->argument->string) {
        ssl->argument->string = stringToBinary(ssl->argument->string);
        ssl->argument->string = ft_strappend(ssl->argument->string, "1");
        int len = strlen(ssl->argument->string);
        while (len % 512 != 448) {
            ssl->argument->string = ft_strappend(ssl->argument->string, "0");
            len = strlen(ssl->argument->string);
        }
        ssl->argument = ssl->argument->next;
    }
}

t_md5 *init_md5(t_ssl **ssl) {
    printf("MD5 init\n");
    t_md5 *md5 = malloc(sizeof(t_md5));

    md5->r = init_r();
    md5->k = init_k();
    md5->h0 = 0x67452301;
    md5->h1 = 0xEFCDAB89;
    md5->h2 = 0x98BADCFE;
    md5->h3 = 0x10325476;

    init_string(*ssl);
    return md5;
}