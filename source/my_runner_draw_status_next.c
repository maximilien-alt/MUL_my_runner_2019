/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_draw_status_next.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_draw_volume(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_BACK].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_OPTIONS].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[VOLUME_CHECK].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[NINJA].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[VOLUME].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}