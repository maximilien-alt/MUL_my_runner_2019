/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** m_runner_usage_and_infinite_mod.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void get_my_second_jump(window_t *window, game_object_t *game_object)
{
    int ninja_x = game_object[NINJA].pos.x;
    int ninja_y = game_object[NINJA].pos.y;

    for (int i = 0; i < window->check_map; i += 1) {
        if (window->map_object[i].type == 4 && \
        ninja_x >= window->map_object[i].pos.x - 40 && \
        ninja_x < window->map_object[i].pos.x + 40 && \
        ninja_y >= window->map_object[i].pos.y - 10 && \
        ninja_x <= window->map_object[i].pos.y + 10) {
            window->nb_jump += 1;
            window->map_object[i].type = 5;
        }
    }
}

void my_draw_pause(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    for (int i = 0; i < window->check_map; i += 1) {
        sfRenderWindow_drawSprite(window->window, \
        window->map_object[i].sprite, NULL);
    }
    sfRenderWindow_drawSprite(window->window, game_object[NINJA].sprite, NULL);
    sfRenderWindow_drawText(window->window, scores.score, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[MENU].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}

void manage_key_pressed_next(window_t *window, \
game_object_t *game_object, music_t musics, score_t *scores)
{
    if (window->event.key.code == sfKeyP && window->status == 10 \
    && window->check_pause == 0) {
        window->status = 2;
        window->check_pause += 1;
    }
    if (window->event.key.code == sfKeyP && window->status == 2 \
    && window->check_pause == 0)
        window->status = 10;
    window->check_pause = 0;
}

int my_usage(void)
{
    char *usage = "Welcome to my runner !\nUSAGE\n\
    ./my_runner map.txt\n\nOPTIONS\n\
    -i launch the game in infinity mode.\n\
    -h print the usage and quit.\n\nUSER INTERACTIONS\n    SPACE_KEY jump, \n\
    ESCAPE_KEY quit, \n\
    R_KEY restart(when you loose).\n\
    P_KEY pause(in game).\nYour highscore is save and visible in the menu";

    write(1, usage, my_strlen(usage));
    return (0);
}

void my_reset_map(window_t *window, game_object_t *game_object)
{

    for (int i = 0; i < window->check_map; i += 1) {
        if (window->map_object[i].pos.x <= 0) {
            window->map_object[i].pos.x += 180*40;
            sfSprite_setPosition(window->map_object[i].sprite, \
            window->map_object[i].pos);
        }
    }
}