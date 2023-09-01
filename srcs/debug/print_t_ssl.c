#include "../../inc/ft_ssl.h"

void print_command(t_ssl *ssl) {
    printf("\n*****command*****\n");
    printf("%s\n", ssl->command);
    printf("\n***************\n");
    printf("\n");
}

void print_flags(t_ssl *ssl) {
    printf("\n*****flags*****\n");
    if (ssl->flags[0]) {
        for (int i = 0; ssl->flags[i]; i++) {
            printf("-> %s\n", ssl->flags[i]);
        }
    }
    else {
        printf("no flags\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_filename(t_argument *argument) {
    printf("\n*****filename*****\n");
    if (argument->filename) {
        while (argument->filename) {
            printf("-> %s\n", argument->filename);
            argument = argument->next;
        }
    }
    else {
        printf("no filename\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_fd(t_argument *argument) {
    printf("\n*****fd*****\n");
    if (argument->fd) {
        while (argument->fd) {
            printf("-> %d\n", argument->fd);
            argument = argument->next;
        }
    }
    else {
        printf("no fd\n");
    }
    printf("\n***************\n");
    printf("\n");
}

void print_string(t_argument *argument) {
    printf("\n*****string*****\n");
    if (argument->string) {
        while (argument->string) {
            printf("-> %s\n", argument->string);
            argument = argument->next;
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
    if (argument->hash) {
        while (argument->hash) {
            printf("-> %s\n", argument->hash);
            argument = argument->next;
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
    print_filename(ssl->argument);
    print_fd(ssl->argument);
    print_string(ssl->argument);
    print_hash(ssl->argument);
    printf("\n*****t_ssl*****\n");
    printf("\n");
}