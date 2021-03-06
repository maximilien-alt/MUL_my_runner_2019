/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_loop.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int complete_my_map(int cursor, int digit, window_t *window, game_object_t *map)
{
    sfVector2f vector = {digit * 40, (cursor - 1) * 40};

    if (window->map[cursor][digit] == '1') {
        map[window->check_map] = create_object("sprites/ground.png", vector, \
        (sfIntRect){0, 0, 40, 40}, 1);
        window->check_map += 1;
    }
    if (window->map[cursor][digit] == '2') {
        map[window->check_map] = create_object("sprites/bloc.png", vector, \
        (sfIntRect){0, 0, 40, 40}, 2);
        window->check_map += 1;
    }
    if (window->map[cursor][digit] == '3') {
        map[window->check_map] = create_object("sprites/pics.png", vector, \
        (sfIntRect){0, 0, 40, 40}, 3);
        window->check_map += 1;
    } else if (window->map[cursor][digit] == '4') {
        map[window->check_map] = create_object("sprites/power_up.png", vector, \
        (sfIntRect){0, 0, 40, 40}, 4);
        window->check_map += 1;
    }
}

void my_create_map(game_object_t *map, window_t *window)
{
    window->check_map = 0;

    for (int cursor = 0; window->map[cursor]; cursor += 1) {
        for (int digit = 0; window->map[cursor][digit]; digit += 1)
            complete_my_map(cursor, digit, window, map);
    }
}

int is_that_an_elem(int cursor, int digit, char **map)
{
    if (map[cursor][digit] == '1' \
    || map[cursor][digit] == '2' \
    || map[cursor][digit] == '3' \
    || map[cursor][digit] == '4') {
        return (1);
    }
    return (0);
}

int nb_elems(char **map)
{
    int nb_elems = 0;

    for (int cursor = 0; map[cursor]; cursor += 1) {
        for (int digit = 0; map[cursor][digit]; digit += 1)
            nb_elems += is_that_an_elem(cursor, digit, map);
    }
    return (nb_elems);
}

void my_loop(window_t window, game_object_t *game_object, \
music_t musics, score_t score)
{
    int nb = nb_elems(window.map);
    my_clock_t clock;
    game_object_t map[nb];

    my_runner_set_structures(&window, &musics, &score, &clock);
    my_create_game_object(game_object, &window);
    my_create_map(map, &window);
    window.map_object = map;
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            analyse_events(&window, game_object, musics, score);
        if (window.status != 9)
            my_jump(game_object, &window, musics, score);
        my_clock(game_object, &clock, &window, &score);
        my_draw_status(&window, game_object, score);
        if (window.inf == 0)
            my_check_victory(&window, game_object, map, musics);
        else
            my_reset_map(&window, game_object);
    }
    my_destoy_object(game_object, window, musics, score);
}