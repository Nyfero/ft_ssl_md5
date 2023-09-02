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
    // Create a buffer to read data from the file
    char buffer[1024];
    size_t bytesRead;
    char *fileContent = NULL;
    size_t fileSize = 0;

    // Read the file in chunks and append to fileContent
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Resize the fileContent buffer
        fileContent = realloc(fileContent, fileSize + bytesRead + 1);
        if (fileContent == NULL)
            malloc_failed();

        // Copy the data from the buffer to the fileContent
        ft_memcpy(fileContent + fileSize, buffer, bytesRead);
        fileSize += bytesRead;
    }

    // Null-terminate the fileContent to make it a valid string
    if (fileContent != NULL) {
        fileContent[fileSize] = '\0';
    }

    return fileContent;
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