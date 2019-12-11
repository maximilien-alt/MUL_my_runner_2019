/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_manage_events.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void manage_mouse_moved_next(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfIntRect rect_2 = {0, 0, 1920, 1080};

    if (window->status == 1 && mouse.x > 844 && mouse.x < 1045 \
    && mouse.y > 768 && mouse.y < 803) {
        sfSprite_setTextureRect(game_object[QUIT].sprite, rect);
        my_music_button(musics, window, 3);
    } else {
        sfSprite_setTextureRect(game_object[QUIT].sprite, rect_2);
        window->check_quit = 0;
    }
    if (window->status == 1 && mouse.x > 769 && mouse.x < 1125 \
    && mouse.y > 532 && mouse.y < 588) {
        sfSprite_setTextureRect(game_object[OPTIONS].sprite, rect);
        my_music_button(musics, window, 2);
    } else {
        sfSprite_setTextureRect(game_object[OPTIONS].sprite, rect_2);
        window->check_options = 0;
    }
}

void manage_mouse_moved_three(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfIntRect rect_2 = {0, 0, 1920, 1080};

    if (window->status == 4 && mouse.x > 71 && mouse.x < 300 \
    && mouse.y > 861 && mouse.y < 925) {
        sfSprite_setTextureRect(game_object[MENU_BACK].sprite, rect);
        my_music_button(musics, window, 4);
    } else {
        sfSprite_setTextureRect(game_object[MENU_BACK].sprite, rect_2);
        window->check_back = 0;
    }
    if (window->status == 5 && mouse.x > 850 && mouse.x < 1050) {
        game_object[VOLUME].pos.x = mouse.x - 100;
        sfSprite_setPosition(game_object[VOLUME].sprite, \
        (sfVector2f){game_object[VOLUME].pos.x, game_object[VOLUME].pos.y});
        my_set_volumes(game_object, musics);
    }
    manage_mouse_moved_four(window, game_object, rect, musics);
}

void manage_mouse_click(window_t *window, game_object_t *game_object, \
music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    if (window->status == 1 && mouse.x > 844 && mouse.x < 1045 \
    && mouse.y > 768 && mouse.y < 803)
        sfRenderWindow_close(window->window);
    if (window->status == 1 && mouse.x > 850 && mouse.x < 1050 \
    && mouse.y > 320 && mouse.y < 384) {
        window->status = 2;
        for (int i = 1; i < PRESS_START; i += 1)
                game_object[i].speed += 10;
        sfMusic_play(musics.game_start);
        sfMusic_play(musics.playing);
        sfMusic_pause(musics.menu);
    }
    if (window->status == 1 && mouse.x > 769 && mouse.x < 1125 \
    && mouse.y > 532 && mouse.y < 588)
        window->status = 4;
    manage_mouse_click_next(window, game_object, musics);
}

void manage_mouse_moved(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfIntRect rect_2 = {0, 0, 1920, 1080};

    sfSprite_setPosition(game_object[CURSOR].sprite, \
    (sfVector2f){mouse.x, mouse.y});
    if (window->status == 1 && mouse.x > 850 && mouse.x < 1050 \
    && mouse.y > 320 && mouse.y < 384) {
        sfSprite_setTextureRect(game_object[PLAY].sprite, rect);
        my_music_button(musics, window, 1);
    } else {
        sfSprite_setTextureRect(game_object[PLAY].sprite, rect_2);
        window->check_play = 0;
    }
    manage_mouse_moved_next(window, game_object, rect, musics);
    manage_mouse_moved_three(window, game_object, rect, musics);
}

void manage_key_pressed(window_t *window, game_object_t *game_object)
{
    if (window->status == 0 && window->event.key.code == sfKeySpace)
        window->status = 1;
    if ((window->status == 2 || window->status == 4) && \
    window->event.key.code == sfKeySpace && \
    window->nb_jump != 0) {
        game_object[NINJA].vel.y = -70;
        window->nb_jump -= 1;
    }
}