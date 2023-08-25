#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../Libft/inc/libft.h"

typedef struct  s_ssl
{
    char        *command;
    char        *flags;
    char        *file;
    char        *string;
}               t_ssl;