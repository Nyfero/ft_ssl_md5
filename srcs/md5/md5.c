#include "../../inc/ft_md5.h"

int md5(int ac, char **av) {
    printf("MD5\n");
    t_ssl *ssl = init_ssl(ac, av);
    print_t_ssl(ssl);
    // t_md5 *md5 = init_md5(&ssl);
    // (void)md5;
    // print_t_md5(md5);

    // printf("MD5\n");
    // print_t_ssl(ssl);
    // print_t_md5(md5);
    free_ssl(ssl);

    return 0;
}