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
    char        *flags;
    char        *file;
    char        *string;
}               t_ssl;


/********************/
/*      MD5         */
/********************/

int*    init_r();
int*    init_k();


/********************/
/*      UTILS       */
/********************/

void print_usage();
void print_invalid_command(char *command);