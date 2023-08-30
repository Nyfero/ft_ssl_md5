#include "../../inc/ft_ssl.h"

void print_t_ssl(t_ssl *ssl) {
    printf("\n\e[92m*****t_ssl*****\n");
    printf("command: %s\n", ssl->command);
    if (ssl->flags[0]) {
        for (int i = 0; ssl->flags[i]; i++) {
            printf("flags %d ->", i);
            printf("%s\n", ssl->flags[i]);
        }
    }
    else {
        printf("no flags\n");
    }
    if (ssl->filename[0]) {
        for (int i = 0; ssl->filename[i]; i++) {
            printf("filename %d ->", i);
            printf("%s\n", ssl->filename[i]);
        }
    }
    else {
        printf("no filename\n");
    }
    if (ssl->fd[0]) {
        for (int i = 0; ssl->fd[i]; i++) {
            printf("fd %d ->", i);
            printf("%d\n", ssl->fd[i]);
        }
    }
    else {
        printf("no fd\n");
    }
    if (ssl->string[0]) {
        for (int i = 0; ssl->string[i]; i++) {
            printf("string %d ->", i);
            printf("%s\n", ssl->string[i]);
        }
    }
    else {
        printf("no string\n");
    }
    if (ssl->hash[0]) {
        for (int i = 0; ssl->hash[i]; i++) {
            printf("hash %d ->", i);
            printf("%s\n", ssl->hash[i]);
        }
    }
    else {
        printf("no hash\n");
    }
    printf("\n***************\n");
    printf("\n\e[39m");
}