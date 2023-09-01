#include "../../inc/ft_ssl.h"

static int get_flag(int ac, char **av, t_ssl *ssl) {
    int i = 2;
    int count = 0;
    while (i < ac) {
        if (av[i][0] == '-') {
            if (av[i][1] == 'p' || av[i][1] == 'q' || av[i][1] == 'r' || av[i][1] == 's')
                count++;
            else
                print_invalid_flag(av[i]);
        }
        else
            break;
        i++;
    }
    ssl->flags = malloc(sizeof(char *) * (count + 1));
    if (!ssl->flags)
        malloc_failed();
    for (int j = 0; j < count; j++)
        ssl->flags[j] = &av[j + 2][1];
    return i;
}

static char *get_string(int fd) {
    char *line;
    char *string;
    int i = 0;
    (void)fd;
    // string = ft_strdup("");
    while (get_next_line(fd, &line) > 0) {
        printf("line: %s\n", line);
        string = ft_strjoin(string, line);
        string = ft_strjoin(string, "\n");
        free(line);
        printf("string: %s\n", string);
        i++;
    }
    return string;
}

static void get_argument(int ac, char **av, t_ssl *ssl, int i) {
    ssl->argument = malloc(sizeof(t_argument));
    if (!ssl->argument)
        malloc_failed();
    t_argument *ptr = ssl->argument;

    while (i < ac) {
        ptr->filename = av[i];
        ptr->fd = open(av[i], O_RDWR);
        ptr->string = get_string(ptr->fd);
        ptr->hash = NULL;
        ptr->next = malloc(sizeof(t_argument));
        if (!ptr->next)
            malloc_failed();
        ptr = ptr->next;
        i++;
    }
}

t_ssl   *init_ssl(int ac, char **av) {
    t_ssl *ssl = malloc(sizeof(t_ssl));
    if (!ssl)
        malloc_failed();
    ssl->command = av[1];
    int i = get_flag(ac, av, ssl);
    get_argument(ac, av, ssl, i);
    return ssl;
}