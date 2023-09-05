#include "../../inc/ft_ssl.h"

void print_command(t_ssl *ssl) {
    printf("\n*****command*****\n");
    printf("%s\n", ssl->cmd);
    printf("\n***************\n");
    printf("\n");
}

void print_flags(t_ssl *ssl) {
    printf("\n*****flags*****\n");
    if (ssl->flags[0]) {
        for (int i = 0; ssl->flags[i]; i++)
            printf(" -> %s\n", ssl->flags[i]);
    }
    else
        printf("no flags\n");
    printf("\n***************\n");
    printf("\n");
}

void print_filename(t_argument *argument) {
    printf("\n*****filename*****\n");
    t_argument *tmp = argument;
    if (tmp->file) {
        while (tmp->file) {
            printf("-> %s\n", tmp->file);
            tmp = tmp->next;
        }
    }
    else {
        printf("no filename\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_string(t_argument *argument) {
    printf("\n*****string*****\n");
    t_argument *tmp = argument;
    if (tmp->string) {
        while (tmp->string) {
            printf("-> %s\n", tmp->string);
            tmp = tmp->next;
        }
    }
    else {
        printf("no string\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_hash(t_argument *argument) {
    printf("\n*****hash*****\n");
    t_argument *tmp = argument;
    if (tmp->hash) {
        while (tmp->hash) {
            printf("-> %s\n", tmp->hash);
            tmp = tmp->next;
        }
    }
    else {
        printf("no hash\n");
    }
    printf("\n***************\n");
    printf("\n");
}


void print_t_ssl(t_ssl *ssl) {
    printf("\n*****t_ssl*****\n");
    print_command(ssl);
    print_flags(ssl);
    printf("\n*****t_argument*****\n");
    print_filename(ssl->argument);
    print_string(ssl->argument);
    print_hash(ssl->argument);
    printf("\n***************\n");
    printf("\n*****t_ssl*****\n");
    printf("\n");
}