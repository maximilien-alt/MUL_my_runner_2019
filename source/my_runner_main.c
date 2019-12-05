/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_main.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void move_rect(game_object_t *parallax, int offset, int max_size, int status)
{
    parallax[status].rect.left += offset;
    if (parallax[status].rect.left > max_size)
        parallax[status].rect.left = 0;
    sfSprite_setTextureRect(parallax[status].sprite, parallax[status].rect);
}

void my_clock(game_object_t *parallax, sfClock *clock, sfTime time)
{
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        for (int i = 0; i < LEN - 1; i += 1)
            move_rect(parallax, parallax[i].speed, parallax[i].size_max, i);
    }
    if (seconds > 0.15) {
        move_rect(parallax, parallax[PRESS_START].speed, \
        parallax[PRESS_START].size_max, PRESS_START);
        sfClock_restart(clock);
    }
}

void my_destoy_object(game_object_t *parallax, window_t window)
{
    for (int i = 0; i < LEN; i += 1) {
        sfTexture_destroy(parallax[i].texture);
        sfSprite_destroy(parallax[i].sprite);
    }
    sfRenderWindow_destroy(window.window);
}

void my_draw_status(window_t *window, game_object_t *parallax)
{
    sfRenderWindow_clear(window->window, sfBlack);
    if (window->status == 0) {
        for (int i = 0; i < LEN; i += 1)
            sfRenderWindow_drawSprite(window->window, parallax[i].sprite, NULL);
    }
    sfRenderWindow_display(window->window);
}

int main(int ac, char *av[])
{
    game_object_t parallax[LEN];
    window_t window;
    sfClock *clock;
    sfTime time;

    window.status = 0;
    my_create_game_object(parallax);
    window.window = create_window(30);
    clock = sfClock_create();
    sfRenderWindow_setVerticalSyncEnabled(window.window, sfTrue);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            analyse_events(&window);
        my_clock(parallax, clock, time);
        my_draw_status(&window, parallax);
    }
    my_destoy_object(parallax, window);
    return (0);
}