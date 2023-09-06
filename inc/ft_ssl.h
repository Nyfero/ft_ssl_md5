# pragma once
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../Libft/inc/libft.h"

typedef struct s_argument
{
    char                *file;
    char                *string;
    char                *hash;
    struct s_argument   *next;
}            t_argument;

typedef struct  s_ssl
{
    char        *cmd;
    char        **flags;
    t_argument  *argument;
}               t_ssl;


/********************/
/*      UTILS       */
/********************/

//  print_message.c
void print_usage();
void print_invalid_command(char *command);
void print_invalid_flag(char *flag);
void malloc_failed();
void print_file_error(char *filename);

//  t_ssl_function.c
t_ssl   *init_ssl(int ac, char **av);
void    free_ssl(t_ssl *ssl);

/*******************/
/*      DEBUG      */
/*******************/

//  print_ssl.c
void print_command(t_ssl *ssl);
void print_flags(t_ssl *ssl);
void print_filename(t_argument *argument);
void print_string(t_argument *argument);
void print_hash(t_argument *argument);
void print_t_ssl(t_ssl *ssl);