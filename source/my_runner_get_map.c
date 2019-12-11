/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_get_map.c
*/

#include "../include/my.h"
#include "../include/struct.h"

char **get_map(char *filepath)
{
    char **map;
    char *buffer;
    int fd = open(filepath, O_RDONLY);
    struct stat st;

    stat(filepath, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size + 1);
    buffer[st.st_size] = '\0';
    map = my_str_to_word_array(buffer);
    free (buffer);
    close (fd);
    return (map);
}

int my_error_handling(int ac, char *av[])
{
    if (ac != 2)
        return (84);
    return (0);
}