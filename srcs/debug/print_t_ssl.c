#include "../../inc/ft_ssl.h"

void print_t_ssl(t_ssl *ssl) {
    printf("\n\e[92m*****t_ssl*****\n");
    printf("command: %s\n", ssl->command);
    printf("flags: ");
    if (ssl->flags[0]) {
        for (int i = 0; ssl->flags[i]; i++) {
            printf("%s ", ssl->flags[i]);
        }
    }
    else {
        printf("no flags");
    }
    printf("\n");
    printf("filename: ");
    if (ssl->filename[0]) {
        for (int i = 0; ssl->filename[i]; i++) {
            printf("%s ", ssl->filename[i]);
        }
    }
    else {
        printf("no filename");
    }
    printf("\n");
    printf("fd: ");
    if (ssl->fd[0]) {
        for (int i = 0; ssl->fd[i]; i++) {
            printf("%d ", ssl->fd[i]);
        }
    }
    else {
        printf("no fd");
    }
    printf("\n");
    printf("string: ");
    if (ssl->string[0]) {
        for (int i = 0; ssl->string[i]; i++) {
            printf("%s ", ssl->string[i]);
        }
    }
    else {
        printf("no string");
    }
    printf("\n");
    printf("hash: ");
    if (ssl->hash[0]) {
        for (int i = 0; ssl->hash[i]; i++) {
            printf("%s ", ssl->hash[i]);
        }
    }
    else {
        printf("no hash");
    }
    printf("\n***************\n");
    printf("\n\e[39m");
}