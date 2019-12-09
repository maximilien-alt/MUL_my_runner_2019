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
    int check = 0;

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

void analyse_events(window_t *window, \
game_object_t *game_object, music_t musics)
{
    sfIntRect rect = {1920, 0, 1920, 1080};

    if (window->event.type == sfEvtClosed || \
    (sfKeyboard_isKeyPressed(sfKeyEscape)))
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseMoved && window->status != 0)
        manage_mouse_moved(window, game_object, rect, musics);
    if (window->event.type == sfEvtKeyPressed)
        manage_key_pressed(window, game_object);
    if (window->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(window, game_object, musics);
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
}

void manage_key_pressed(window_t *window, game_object_t *game_object)
{
    if (window->status == 0 && window->event.key.code == sfKeySpace)
        window->status = 1;
    if ((window->status == 2 || window->status == 3) && \
    window->event.key.code == sfKeySpace && \
    window->nb_jump != 0) {
        game_object[NINJA].vel.y = -70;
        window->nb_jump -= 1;
        window->status = 3;
    }
}