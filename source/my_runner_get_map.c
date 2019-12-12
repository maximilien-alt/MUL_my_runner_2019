/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_get_map.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int get_my_position(window_t *window, game_object_t *game_object)
{
    int ninja_x = game_object[NINJA].pos.x;
    int ninja_y = game_object[NINJA].pos.y;

    for (int cursor = 0; cursor < window->check_map; cursor += 1) {
        if (ninja_x >= window->map_object[cursor].pos.x && \
        ninja_x < window->map_object[cursor].pos.x + 40 && \
        ninja_y + 90 <= window->map_object[cursor].pos.y && \
        window->map_object[cursor].type != 3)
            return (window->map_object[cursor].pos.y - 90);
        if (ninja_x >= window->map_object[cursor].pos.x && \
        ninja_x < window->map_object[cursor].pos.x + 40 && \
        ninja_y >= window->map_object[cursor].pos.y - 90 && \
        ninja_y <= window->map_object[cursor].pos.y && \
        window->map_object[cursor].type == 3)
            window->status = 8;
    }
    return (1800);
}

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