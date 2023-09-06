#include "../../inc/ft_md5.h"

int md5(int ac, char **av) {
    printf("MD5\n");
    t_ssl *ssl = init_ssl(ac, av);
    print_t_ssl(ssl);
    t_md5 *md5 = init_md5(ssl);
    print_t_md5(md5);

    print_t_ssl(ssl);

    free_ssl(ssl);
    free_md5(md5);

    return 0;
}