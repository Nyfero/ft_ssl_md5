#include "../inc/ft_ssl.h"

int main(int ac, char **av) {

    if (ac == 1) {
        print_usage();
    }
    else if (strcmp(av[1], "md5") && strcmp(av[1], "sha256")) {
        print_invalid_command(av[1]);
        return (1);
    }

    return (0);
}