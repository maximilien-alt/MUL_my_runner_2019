/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_draw_status.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_jump(game_object_t *game_object, window_t *window, \
music_t musics, score_t scores)
{
    int check_y = 0;

    if (window->status != 10) {
        if (window->status == 2)
            check_y = get_my_position(window, game_object, musics);
        if (game_object[NINJA].pos.y >= 1080)
            my_game_over(window, musics, scores);
        else
            window->check_over = 0;
        if ((window->status >= 4 && window->status <= 7))
            check_y = 500;
        game_object[NINJA].pos.y += game_object[NINJA].vel.y;
        if (game_object[NINJA].pos.y <= check_y)
            game_object[NINJA].vel.y += window->grav;
        else {
            window->nb_jump = 1;
            game_object[NINJA].vel.y = 0;
            game_object[NINJA].pos.y = check_y;
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
    for (int i = 0; i < window->check_map; i += 1) {
        if (window->map_object[i].pos.x <= 1920 && \
        window->map_object[i].pos.x >= -20)
            sfRenderWindow_drawSprite(window->window, \
            window->map_object[i].sprite, NULL);
    }
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
    sfRenderWindow_drawText(window->window, scores.highscore, NULL);
    for (int i = PLAY; i < NINJA; i += 1)
        sfRenderWindow_drawSprite(window->window, \
        game_object[i].sprite, NULL);
}

void my_draw_options(window_t *window, game_object_t *game_object, \
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