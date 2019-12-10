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

void my_destoy_object(game_object_t *game_object, \
window_t window, music_t musics, score_t scores)
{
    for (int i = 0; i < LEN; i += 1) {
        sfTexture_destroy(game_object[i].texture);
        sfSprite_destroy(game_object[i].sprite);
    }
    sfMusic_destroy(musics.playing);
    sfMusic_destroy(musics.menu_button);
    sfMusic_destroy(musics.game_start);
    sfMusic_destroy(musics.menu);
    sfText_destroy(scores.highscore);
    sfText_destroy(scores.score);
    sfRenderWindow_destroy(window.window);
}

void my_draw_status(window_t *window, game_object_t *game_object, \
score_t scores)
{
    sfRenderWindow_clear(window->window, sfBlack);
    if (window->status == 0) {
        for (int i = 0; i < PRESS_START + 1; i += 1)
            sfRenderWindow_drawSprite(window->window, \
            game_object[i].sprite, NULL);
    }
    if (window->status == 1)
        my_draw_menu(window, game_object, scores);
    if (window->status == 2)
        my_draw_playing(window, game_object, scores);
    if (window->status == 3)
        my_draw_jumping(window, game_object, scores);
    if (window->status == 4)
        my_draw_options(window, game_object, scores);
    if (window->status == 5)
        my_draw_volume(window, game_object, scores);
    sfRenderWindow_display(window->window);
}

void main(int ac, char *av[])
{
    game_object_t game_object[LEN];
    window_t window;
    my_clock_t clock;
    music_t musics;
    score_t score;

    window.window = create_window(30);
    my_runner_set_structures(&window, &musics, &score);
    my_create_game_object(game_object, &window);
    clock.clock = sfClock_create();
    sfMusic_play(musics.menu);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            analyse_events(&window, game_object, musics, score);
        my_jump(game_object, &window);
        my_clock(game_object, &clock, &window, &score);
        my_draw_status(&window, game_object, score);
    }
    my_destoy_object(game_object, window, musics, score);
}