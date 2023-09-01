#include "../../inc/ft_ssl.h"

void print_usage() {
    ft_putendl_fd("usage: ft_ssl command [flags] [file/string]", 1);
}

void static print_valid_command(){
    ft_putendl_fd("\nCommands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s", 2);
}

void print_invalid_command(char *command) {
    ft_putstr_fd("ft_ssl: Error: ", 2);
    ft_putstr_fd(command, 2);
    ft_putendl_fd(" is an invalid command.", 2);
    print_valid_command();
    exit(1);
}

void print_invalid_flag(char *flag) {
    ft_putstr_fd("ft_ssl: Error: ", 2);
    ft_putstr_fd(flag, 2);
    ft_putendl_fd(" is an invalid flag.", 2);
    print_valid_command();
    exit(1);
}

void malloc_failed() {
    ft_putendl_fd("Error: malloc failed", 2);
    exit(1);
}