#include "../../inc/ft_ssl.h"

// get the number of flags
static int count_flag(int ac, char **av) {
    int count = 0;
    for (int i = 2; i < ac; i++) {
        if (av[i][0] == '-') {
            if (av[i][1] == 'p' || av[i][1] == 'q' || av[i][1] == 'r' || av[i][1] == 's')
                count++;
            else
                print_invalid_flag(av[i]);
        }
        else
            break;
    }
    return count;
}

// get the flags
static char **get_flag(int ac, char **av) {
    int nb_flags = count_flag(ac, av);
    if (nb_flags == 0)
        return NULL;
    char **flags = malloc(sizeof(char **) * (nb_flags + 1));
    if (!flags)
        malloc_failed();
    for (int i = 0; i < nb_flags; i++)
        flags[i] =  ft_strdup(&av[i + 2][1]);
    flags[nb_flags] = NULL;
    return flags;
}

// get the content of a file
static char *get_string(char *filename) {
    char *string = ft_strdup("");
    int fd = 0;

    if ((fd = open(filename, O_RDONLY)) < 0)
        print_file_error(filename);
    else {
        char *line;
        while (get_next_line(fd, &line) > 0) {
            string = ft_strappend(string, line);
            string = ft_strappend(string, "\n");
            free(line);
        }
        string = ft_strappend(string, line);
        free(line);
        close(fd);
    }

    return string;
}

// get the arguments
static t_argument *get_argument(int ac, char **av) {
    t_argument *argument = malloc(sizeof(t_argument) * 1);
    if (!argument)
        malloc_failed();
    
    t_argument *tmp = argument;
    int i = 2 + count_flag(ac, av);

    while (i < ac) {
        tmp->file = ft_strdup(av[i]);
        tmp->string = get_string(tmp->file);
        tmp->hash = NULL;
        tmp->next = malloc(sizeof(t_argument));
        if (!tmp->next)
            malloc_failed();
        tmp = tmp->next;
        i++;
    }
    tmp->file = NULL;
    tmp->string = NULL;
    tmp->hash = NULL;
    tmp->next = NULL;
    return argument;
}

// free the t_ssl structure
void   free_ssl(t_ssl *ssl) {
    if (ssl->cmd)
        free(ssl->cmd);
    if (ssl->flags) {
        for (int i = 0; ssl->flags[i]; i++)
            free(ssl->flags[i]);
        free(ssl->flags);
    }
    t_argument *tmp = ssl->argument;
    while (tmp) {
        if (tmp->file)
            free(tmp->file);
        if (tmp->string)
            free(tmp->string);
        if (tmp->hash)
            free(tmp->hash);
        t_argument *next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(ssl);
}

// initialize the t_ssl structure
t_ssl   *init_ssl(int ac, char **av) {
    t_ssl *ssl = malloc(sizeof(t_ssl) * 1);
    if (!ssl)
        malloc_failed();
    ssl->cmd = ft_strdup(av[1]);
    ssl->flags = get_flag(ac, av);
    ssl->argument = get_argument(ac, av);
    if (!ssl->argument)
        malloc_failed();
    return ssl;
}