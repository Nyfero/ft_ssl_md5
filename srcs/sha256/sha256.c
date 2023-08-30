#include "../../inc/ft_ssl.h"

int sha256(int ac, char **av) {
    t_ssl *ssl = init_ssl(ac, av);
    print_t_ssl(ssl);
    printf("SHA256\n");
    init_sha256();
    return 0;
}