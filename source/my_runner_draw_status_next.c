/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_draw_status_next.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_draw_victory(window_t *window, game_object_t *game_object, \
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
    sfRenderWindow_drawSprite(window->window, \
    game_object[VICTORY].sprite, NULL);
    sfRenderWindow_drawText(window->window, scores.score, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[MENU].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}

void my_draw_game_over(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    for (int i = 0; i < window->check_map; i += 1) {
        sfRenderWindow_drawSprite(window->window, \
        window->map_object[i].sprite, NULL);
    }
    sfRenderWindow_drawText(window->window, scores.score, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[GAME_OVER].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[MENU].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}

void my_draw_speed(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_BACK].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_OPTIONS].sprite, NULL);
    for (int i = VOLUME_CHECK; i <= SPEED_CHECK; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[NINJA].sprite, NULL);
    for (int i = VOLUME; i <= SPEED; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}

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
    for (int i = VOLUME_CHECK; i <= SPEED_CHECK; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[NINJA].sprite, NULL);
    for (int i = VOLUME; i <= SPEED; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}

void my_draw_gravity(window_t *window, game_object_t *game_object, \
score_t scores)
{
    for (int i = 0; i < PRESS_START; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_BACK].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[MENU_OPTIONS].sprite, NULL);
    for (int i = VOLUME_CHECK; i <= SPEED_CHECK; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, \
    game_object[NINJA].sprite, NULL);
    for (int i = VOLUME; i <= SPEED; i += 2)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
    sfRenderWindow_drawSprite(window->window, game_object[CURSOR].sprite, NULL);
}