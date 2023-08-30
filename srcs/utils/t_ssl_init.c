#include "../../inc/ft_ssl.h"

static int get_flag(int ac, char **av, t_ssl *ssl) {
    int i = 2;
    int count = 0;
    while (i < ac) {
        if (av[i][0] == '-') {
            count++;
        }
        else {
            break;
        }
        i++;
    }

    ssl->flags = malloc(sizeof(char *) * (count + 1));
    for (int j = 0; j < count; j++) {
        ssl->flags[j] = &av[j + 2][1];
    }

    return i;
}

static int get_filename(int ac, char **av, t_ssl *ssl, int i) {
    int j = 0;
    ssl->filename = malloc(sizeof(char *) * (ac - i));
    while (i < ac) {
        ssl->filename[j] = av[i];
        j++;
        i++;
    }
    
    ssl->fd = malloc(sizeof(int) * j);
    for (int k = 0; k < j; k++) {
        ssl->fd[k] = open(ssl->filename[k], O_RDWR);
    }
    return j;
}

static void get_string(t_ssl *ssl) {
    char *line;
    int i = 0;
    get_next_line(0, &line);
    ssl->string[i] = line;
    i++;
    while (ssl->fd[i - 1]) {
        read(ssl->fd[i - 1], line, 100000);
        printf("line: %s\n", line);
        ssl->string[i] = line;
        i++;
    }
}

t_ssl   *init_ssl(int ac, char **av) {
    t_ssl *ssl = malloc(sizeof(t_ssl));
    ssl->command = av[1];
    int i = get_flag(ac, av, ssl);
    i = get_filename(ac, av, ssl, i);
    ssl->string = malloc(sizeof(char *) * (i + 1));
    get_string(ssl);
    ssl->hash = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++) {
        ssl->hash[j] = NULL;
    }
    return ssl;
}