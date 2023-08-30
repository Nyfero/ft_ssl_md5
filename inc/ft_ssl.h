#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../Libft/inc/libft.h"

typedef struct  s_ssl
{
    char        *command;
    char        **flags;
    char        **filename;
    int         *fd;
    char        **string;
    char        **hash;
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

//  t_ssl_init.c
t_ssl   *init_ssl(int ac, char **av);

/*******************/
/*      DEBUG      */
/*******************/

//  print_t_ssl.c
void print_t_ssl(t_ssl *ssl);