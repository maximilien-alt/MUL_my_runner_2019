/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_main.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void move_rect(game_object_t *game_object, int offset, int max_size, int status)
{
    game_object[status].rect.left += offset;
    if (game_object[status].rect.left > max_size)
        game_object[status].rect.left = 0;
    sfSprite_setTextureRect(game_object[status].sprite, \
    game_object[status].rect);
}

void my_clock(game_object_t *game_object, sfClock *clock, \
sfTime time, window_t *window)
{
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        for (int i = 0; i < PRESS_START; i += 1)
            move_rect(game_object, game_object[i].speed, \
            game_object[i].size_max, i);
    }
    if (window->status == 0 && seconds > 0.15) {
        move_rect(game_object, game_object[PRESS_START].speed, \
        game_object[PRESS_START].size_max, PRESS_START);
        sfClock_restart(clock);
    }
}

void my_destoy_object(game_object_t *game_object, window_t window)
{
    for (int i = 0; i < LEN; i += 1) {
        sfTexture_destroy(game_object[i].texture);
        sfSprite_destroy(game_object[i].sprite);
    }
    sfRenderWindow_destroy(window.window);
}

void my_draw_status(window_t *window, game_object_t *game_object)
{
    sfRenderWindow_clear(window->window, sfBlack);
    if (window->status == 0) {
        for (int i = 0; i < PRESS_START + 1; i += 1)
            sfRenderWindow_drawSprite(window->window, \
            game_object[i].sprite, NULL);
    }
    if (window->status == 1) {
        for (int i = 0; i < PRESS_START; i += 1)
            sfRenderWindow_drawSprite(window->window, \
            game_object[i].sprite, NULL);
        for (int i = PLAY; i < LEN; i += 1)
            sfRenderWindow_drawSprite(window->window, \
            game_object[i].sprite, NULL);
    }
    sfRenderWindow_display(window->window);
}

int main(int ac, char *av[])
{
    game_object_t game_object[CURSOR + 1];
    window_t window;
    sfClock *clock;
    sfTime time;

    window.status = 0;
    window.window = create_window(30);
    my_create_game_object(game_object, &window);
    clock = sfClock_create();
    sfRenderWindow_setVerticalSyncEnabled(window.window, sfTrue);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            analyse_events(&window, game_object);
        my_clock(game_object, clock, time, &window);
        my_draw_status(&window, game_object);
    }
    my_destoy_object(game_object, window);
    return (0);
}