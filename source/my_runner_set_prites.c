/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_prites.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_runner_set_structures_next(window_t *window, \
music_t *music, score_t *scores)
{
    window->check_play = 0;
    window->check_options = 0;
    window->check_quit = 0;
    window->check_back = 0;
    sfMusic_setVolume(music->game_start, 50);
    sfMusic_setVolume(music->menu_button, 50);
    sfMusic_setVolume(music->playing, 50);
    sfMusic_setVolume(music->menu, 50);
    window->grav = 10;
}

void my_runner_set_structures(window_t *window, music_t *music, score_t *scores)
{
    char zero[2];

    zero[0] = '0';
    zero[1] = '\0';
    window->status = 0;
    window->nb_jump = 1;
    scores->highscore_str = my_highscore("sprites/highscore");
    scores->highscore = my_score(scores->highscore_str, \
    (sfVector2f){50, 900});
    scores->zero = zero;
    scores->score = my_score(scores->zero, (sfVector2f){920, 0});
    music->game_start = sfMusic_createFromFile("music/game_start.ogg");
    music->menu_button = sfMusic_createFromFile("music/menu_button.ogg");
    music->playing = sfMusic_createFromFile("music/music.ogg");
    music->menu = sfMusic_createFromFile("music/menu.ogg");
    sfMusic_setLoop(music->playing, sfTrue);
    sfMusic_setLoop(music->menu, sfTrue);
    my_runner_set_structures_next(window, music, scores);
}