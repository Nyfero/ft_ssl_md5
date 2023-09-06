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
    free(s);
    return binary;
}

static void init_string(t_ssl *ssl) {
    t_argument *tmp = ssl->argument;
    while (tmp->string) {
        tmp->string = stringToBinary(tmp->string);
        tmp->string = ft_strappend(tmp->string, "1");
        int len = 448 - (strlen(tmp->string) % 512);
        tmp->string = ft_strnappend(tmp->string, '0', len);
        tmp = tmp->next;
    }
}

void free_md5(t_md5 *md5) {
    free(md5->r);
    free(md5->k);
    free(md5);
}

t_md5 *init_md5(t_ssl *ssl) {
    printf("MD5 init\n");
    t_md5 *md5 = malloc(sizeof(t_md5));

    md5->r = init_r();
    md5->k = init_k();
    md5->h0 = 0x67452301;
    md5->h1 = 0xEFCDAB89;
    md5->h2 = 0x98BADCFE;
    md5->h3 = 0x10325476;
    md5->a = md5->h0;
    md5->b = md5->h1;
    md5->c = md5->h2;
    md5->d = md5->h3;

    init_string(ssl);
    return md5;
}