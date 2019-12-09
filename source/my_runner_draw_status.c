/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_draw_status.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_jump(game_object_t *game_object, window_t *window)
{
    if (window->status == 3) {
        game_object[NINJA].pos.x += game_object[NINJA].vel.x;
        game_object[NINJA].pos.y += game_object[NINJA].vel.y;
        if (game_object[NINJA].pos.y <= 925)
            game_object[NINJA].vel.y += GRAV;
        else {
            window->nb_jump = 1;
            game_object[NINJA].vel.y = 0;
            game_object[NINJA].pos.y = 925;
            window->status = 2;
        }
        sfSprite_setPosition(game_object[NINJA].sprite, game_object[NINJA].pos);
    }
}

void my_draw_jumping(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    for (int i = NINJA; i >= CURSOR; i += -1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfText_setPosition(scores.score, \
    (sfVector2f){940 - (30 * my_strlen(scores.zero)), 0});
    sfRenderWindow_drawText(window->window, scores.score, NULL);
}

void my_draw_playing(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    for (int i = NINJA; i >= CURSOR; i += -1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfText_setPosition(scores.score, \
    (sfVector2f){940 - (30 * my_strlen(scores.zero)), 0});
    sfRenderWindow_drawText(window->window, scores.score, NULL);
}

void my_draw_menu(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    for (int i = PLAY; i < NINJA; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawText(window->window, scores.highscore, NULL);
}