/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_speed_and_size_max.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_set_volumes(game_object_t *game_object, music_t music)
{
    sfSound_setVolume(music.game_start, \
    (game_object[VOLUME].pos.x - 750) / 2);
    sfMusic_setVolume(music.menu_button, \
    (game_object[VOLUME].pos.x - 750) / 2);
    sfMusic_setVolume(music.playing, \
    (game_object[VOLUME].pos.x - 750) / 2);
    sfMusic_setVolume(music.menu, \
    (game_object[VOLUME].pos.x - 750) / 2);
    sfSound_setVolume(music.over, \
    (game_object[VOLUME].pos.x - 750) / 2);
}

int my_speed(int type)
{
    if (type == PRESS_START || type == PLAY || type == GAME_OVER)
        return (1920);
    if (type == NINJA)
        return (168);
    return (type);
}

int my_size_max(int type)
{
    if (type == PRESS_START)
        return (9600);
    if (type == NINJA)
        return (1512);
    if (type == GAME_OVER)
        return (1921);
    return (WIDTH);
}

void my_window_checks(window_t *window)
{
    window->check_play += 1;
    window->check_options += 1;
    window->check_quit += 1;
    window->check_back += 1;
    window->check_menu += 1;
}

void my_music_button(music_t musics, window_t *window, int check)
{
    /*sfMusic_setLoop(musics.menu_button, sfFalse);
    if (window->check_quit == 0 && check == 3) {
        sfMusic_play(musics.menu_button);
        sfMusic_setLoop(musics.menu_button, sfTrue);
    }
    if (window->check_play == 0 && check == 1) {
        sfMusic_play(musics.menu_button);
        sfMusic_setLoop(musics.menu_button, sfTrue);
    }
    if (window->check_options == 0 && check == 2) {
        sfMusic_play(musics.menu_button);
        sfMusic_setLoop(musics.menu_button, sfTrue);
    }
    if (window->check_back == 0 && check == 4) {
        sfMusic_play(musics.menu_button);
        sfMusic_setLoop(musics.menu_button, sfTrue);
    }
    my_music_button_next(musics, window, check);*/
    my_window_checks(window);
}