/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_analyse_events.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void manage_mouse_moved_four(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    if (window->status == 6 && mouse.x > 1350 && mouse.x < 1550) {
        game_object[GRAVITY].pos.x = mouse.x - 100;
        sfSprite_setPosition(game_object[GRAVITY].sprite, \
        (sfVector2f){game_object[GRAVITY].pos.x, game_object[GRAVITY].pos.y});
        window->grav = (game_object[GRAVITY].pos.x - 1250) / 10;
    }
    if (window->status == 7 && mouse.x > 350 && mouse.x < 550) {
        game_object[SPEED].pos.x = mouse.x - 100;
        sfSprite_setPosition(game_object[SPEED].sprite, \
        (sfVector2f){game_object[SPEED].pos.x, game_object[SPEED].pos.y});
        for (int i = BACK; i <= FRONT_2; i += 1) {
            game_object[i].speed = i + \
            (game_object[SPEED].pos.x - 250) / 5;
        }
    }
}

void manage_mouse_click_next(window_t *window, game_object_t *game_object, \
music_t musics)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    int pos_x = game_object[VOLUME].pos.x + 75;
    int gravity_pos_x = game_object[GRAVITY].pos.x + 75;
    int speed_pos_x = game_object[SPEED].pos.x + 75;

    if (window->status == 4 && mouse.x > 71 && mouse.x < 300 \
    && mouse.y > 861 && mouse.y < 925)
        window->status = 1;
    if ((window->status == 4) && (mouse.x > pos_x && mouse.x < pos_x + 50)
    && mouse.y > 500 && mouse.y < 700) {
        window->status = 5;
    }
    if ((window->status == 4) && \
    (mouse.x > gravity_pos_x && mouse.x < gravity_pos_x + 50)
    && mouse.y > 500 && mouse.y < 700)
        window->status = 6;
    if ((window->status == 4) && \
    (mouse.x > speed_pos_x && mouse.x < speed_pos_x + 50)
    && mouse.y > 500 && mouse.y < 700)
        window->status = 7;
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
        manage_key_pressed(window, game_object, musics, &scores);
    if (window->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(window, game_object, musics);
    if (window->status == 5 && window->event.type == sfEvtMouseButtonReleased)
        window->status = 4;
    if (window->status == 6 && window->event.type == sfEvtMouseButtonReleased)
        window->status = 4;
    if (window->status == 7 && window->event.type == sfEvtMouseButtonReleased)
        window->status = 4;
}