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
    sfSound_destroy(musics.game_start);
    sfMusic_destroy(musics.menu);
    sfSound_destroy(musics.over);
    sfSound_destroy(musics.victory_sound);
    sfSoundBuffer_destroy(musics.buffer);
    sfSoundBuffer_destroy(musics.victory);
    sfSoundBuffer_destroy(musics.buffer_start);
    sfText_destroy(scores.highscore);
    sfText_destroy(scores.score);
    for (int i = 0; i < window.check_map; i++) {
        sfSprite_destroy(window.map_object[i].sprite);
        sfTexture_destroy(window.map_object[i].texture);
    }
    sfRenderWindow_destroy(window.window);
}

void my_draw_status_next(window_t *window, game_object_t *game_object, \
score_t scores)
{
    if (window->status == 7)
        my_draw_speed(window, game_object, scores);
    if (window->status == 8)
        my_draw_game_over(window, game_object, scores);
    if (window->status == 9)
        my_draw_victory(window, game_object, scores);
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
    if (window->status == 6)
        my_draw_gravity(window, game_object, scores);
    my_draw_status_next(window, game_object, scores);
    sfRenderWindow_display(window->window);
}

int main(int ac, char *av[])
{
    game_object_t game_object[LEN];
    window_t window;
    music_t musics;
    score_t score;

    if (my_error_handling(ac, av) == 84)
        return (84);
    window.map = get_map(av[1]);
    my_loop(window, game_object, musics, score);
}