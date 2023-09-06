# pragma once
#include "ft_ssl.h"
#include <stdint.h>

typedef struct s_md5
{
    unsigned int    *r;
    unsigned int    *k;
    unsigned int    h0;
    unsigned int    h1;
    unsigned int    h2;
    unsigned int    h3;
    unsigned int    a;
    unsigned int    b;
    unsigned int    c;
    unsigned int    d;
}               t_md5;


/********************/
/*      MD5         */
/********************/

//  md5.c
int md5(int ac, char **av);

//  md5_init.c
t_md5   *init_md5(t_ssl *ssl);
void    free_md5(t_md5 *md5);


/*******************/
/*      DEBUG      */
/*******************/

//  print_md5.c
void print_r(t_md5 *md5);
void print_k(t_md5 *md5);
void print_h0123(t_md5 *md5);
void print_abcd(t_md5 *md5);
void print_t_md5(t_md5 *md5);