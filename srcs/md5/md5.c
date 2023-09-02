#include "../../inc/ft_ssl.h"
#include "../../inc/ft_md5.h"

int md5(int ac, char **av) {
    t_ssl *ssl = init_ssl(ac, av);
    // print_t_ssl(ssl);
    printf("MD5\n");
    init_md5(ssl);
    return 0;
}