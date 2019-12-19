/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** m_runner_usage_and_infinite_mod.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int my_usage(void)
{
    char *usage = "Welcome to my runner !\nUSAGE\n\
    ./my_runner map.txt\n\nOPTIONS\n\
    -i launch the game in infinity mode.\n\
    -h print the usage and quit.\n\nUSER INTERACTIONS\n    SPACE_KEY jump, \n\
    ESCAPE_KEY quit, \n\
    R_KEY restart(when you loose).\n";

    write(1, usage, my_strlen(usage));
    return (0);
}

void my_reset_map(window_t *window)
{
    for (int i = 0; i < window->check_map; i += 1) {
        if (window->map_object[i].pos.x <= 0) {
            window->map_object[i].pos.x += 180*40;
            sfSprite_setPosition(window->map_object[i].sprite, \
            window->map_object[i].pos);
        }
    }
}