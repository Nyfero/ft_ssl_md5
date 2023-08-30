#include "../inc/ft_ssl.h"

int main(int ac, char **av) {

    if (ac == 1) {
        print_usage();
    }
    else if (!strcmp(av[1], "md5")) {
        md5(ac, av);
    }
    else if (!strcmp(av[1], "sha256")) {
        sha256(ac, av);
    }
    else {
        print_invalid_command(av[1]);
        return (1);
    }

    return (0);
}