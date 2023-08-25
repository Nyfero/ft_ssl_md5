#include "../inc/ft_ssl.h"

int main(int ac, char **av) {

    if (ac == 1) {
        ft_putendl_fd("usage: ft_ssl command [flags] [file/string]", 1);
        return (0);
    }
    else if (strcmp(av[1], "md5") && strcmp(av[1], "sha256")) {
        ft_putstr_fd("ft_ssl: Error: ", 2);
        ft_putstr_fd(av[1], 2);
        ft_putendl_fd(" is an invalid command.", 2);
        ft_putendl_fd("\nCommands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s", 2);
        return (1);
    }

    return (0);
}