#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../Libft/inc/libft.h"

typedef struct s_argument
{
    char                *filename;
    int                 fd;
    char                *string;
    char                *hash;
    struct s_argument   *next;
}            t_argument;

typedef struct  s_ssl
{
    char        *command;
    char        **flags;
    t_argument  *argument;
}               t_ssl;

/********************/
/*      MD5         */
/********************/

//  md5.c
int md5(int ac, char **av);

//  md5_init.c
int init_md5();


/********************/
/*      SHA256      */
/********************/

// sha256.c
int sha256(int ac, char **av);

// sha256_init.c
int init_sha256();

/********************/
/*      UTILS       */
/********************/

//  print_message.c
void print_usage();
void print_invalid_command(char *command);
void print_invalid_flag(char *flag);
void malloc_failed();

//  t_ssl_init.c
t_ssl   *init_ssl(int ac, char **av);

/*******************/
/*      DEBUG      */
/*******************/

//  print_t_ssl.c
void print_command(t_ssl *ssl);
void print_flags(t_ssl *ssl);
void print_filename(t_argument *argument);
void print_fd(t_argument *argument);
void print_string(t_argument *argument);
void print_hash(t_argument *argument);
void print_t_ssl(t_ssl *ssl);