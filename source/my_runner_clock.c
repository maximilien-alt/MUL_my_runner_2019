/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_clock.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_rect_map(window_t *window, game_object_t *game_object)
{
    for (int i = 0; i < window->check_map; i += 1) {
        window->map_object[i].pos.x -= game_object[FRONT_2].speed;
        sfSprite_setPosition(window->map_object[i].sprite, \
        window->map_object[i].pos);
    }
}

void my_clock_ninja(game_object_t *game_object, \
my_clock_t *clock, window_t *window, score_t *scores)
{
    if (window->status != 0 && clock->seconds > 0.1) {
        move_rect(game_object, game_object[NINJA].speed, \
        game_object[NINJA].size_max, NINJA);
        if (window->status == 2) {
            scores->zero = my_infin_add(scores->zero, "1");
            sfText_setString(scores->score, scores->zero);
        }
        sfSprite_rotate(game_object[CURSOR].sprite, 40);
        sfClock_restart(clock->clock);
    }
}

void my_clock(game_object_t *game_object, my_clock_t *clock, \
window_t *window, score_t *scores)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > 0.01) {
        for (int i = 0; i < PRESS_START; i += 1)
            move_rect(game_object, game_object[i].speed, \
            game_object[i].size_max, i);
            if (window->status == 2)
                my_rect_map(window, game_object);
    }
    if (window->status == 0 && clock->seconds > 0.15) {
        move_rect(game_object, game_object[PRESS_START].speed, \
        game_object[PRESS_START].size_max, PRESS_START);
        sfClock_restart(clock->clock);
    }
    my_clock_ninja(game_object, clock, window, scores);
}