/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_analyse_events.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void manage_mouse_click_next(window_t *window, game_object_t *game_object, \
music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    int pos_x = game_object[VOLUME].pos.x + 75;
    int pos_y = game_object[VOLUME].pos.y;

    if (window->status == 4 && mouse.x > 71 && mouse.x < 300 \
    && mouse.y > 861 && mouse.y < 925)
        window->status = 1;
    if ((window->status == 4) && (mouse.x > pos_x && mouse.x < pos_x + 50)
    && mouse.y > 500 && mouse.y < 700) {
        window->status = 5;
    }
}

void analyse_events(window_t *window, \
game_object_t *game_object, music_t musics, score_t scores)
{
    sfIntRect rect = {1920, 0, 1920, 1080};

    if (window->event.type == sfEvtClosed || \
    (sfKeyboard_isKeyPressed(sfKeyEscape))) {
        my_check_highscore(scores);
        sfRenderWindow_close(window->window);
    }
    if (window->event.type == sfEvtMouseMoved && window->status != 0)
        manage_mouse_moved(window, game_object, rect, musics);
    if (window->event.type == sfEvtKeyPressed)
        manage_key_pressed(window, game_object);
    if (window->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(window, game_object, musics);
    if (window->status == 5 && window->event.type == sfEvtMouseButtonReleased)
        window->status = 4;
}