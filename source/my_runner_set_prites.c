/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_prites.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_runner_set_structures_three(window_t *window, \
music_t *music, score_t *scores, my_clock_t *clock)
{
    music->victory = sfSoundBuffer_createFromFile\
    ("music/success.ogg");
    music->victory_sound = sfSound_create();
    music->buffer_start = sfSoundBuffer_createFromFile\
    ("music/game_start.ogg");
    music->game_start = sfSound_create();
    sfSound_setBuffer(music->game_start, music->buffer_start);
    sfSound_setVolume(music->game_start, 50);
    sfSound_setBuffer(music->victory_sound, music->victory);
    sfSound_setVolume(music->victory_sound, 50);
    window->check_menu = 0;
    window->check_pause = 0;
}

void my_game_over(window_t *window, music_t musics, score_t scores)
{
    my_check_highscore(&scores);
    sfSound_play(musics.over);
    window->status = 8;
    sfMusic_pause(musics.playing);
}

sfText *my_text(void)
{
    sfText* text;
    sfFont* font;
    char *str = "\n\n\n\n\n\n                YOU WIN!";

    font = sfFont_createFromFile("sprites/text.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfWhite);
    return (text);
}

void my_runner_set_structures_next(window_t *window, \
music_t *music, score_t *scores, my_clock_t *clock)
{
    music->buffer = sfSoundBuffer_createFromFile\
    ("music/game_over.ogg");
    music->over = sfSound_create();
    sfSound_setBuffer(music->over, music->buffer);
    window->check_play = 0;
    window->check_options = 0;
    window->check_quit = 0;
    window->check_back = 0;
    window->check_over = 0;
    sfMusic_setVolume(music->menu_button, 50);
    sfMusic_setVolume(music->playing, 50);
    sfMusic_setVolume(music->menu, 50);
    sfSound_setVolume(music->over, 50);
    sfMusic_play(music->menu);
    window->grav = 10;
    clock->clock = sfClock_create();
    window->check_map = 0;
    window->text = my_text();
    window->check_speed = 0;
}

void my_runner_set_structures(window_t *window, music_t *music, \
score_t *scores, my_clock_t *clock)
{
    char zero[2];

    zero[0] = '0';
    zero[1] = '\0';
    window->window = create_window(30);
    window->status = 0;
    window->nb_jump = 1;
    scores->highscore_str = my_highscore("sprites/highscore");
    scores->highscore = my_score(scores->highscore_str, \
    (sfVector2f){50, 900});
    scores->zero = zero;
    scores->score = my_score(scores->zero, (sfVector2f){920, 0});
    music->menu_button = sfMusic_createFromFile("music/menu_button.ogg");
    music->playing = sfMusic_createFromFile("music/music.ogg");
    music->menu = sfMusic_createFromFile("music/menu.ogg");
    sfMusic_setLoop(music->playing, sfTrue);
    sfMusic_setLoop(music->menu, sfTrue);
    my_runner_set_structures_next(window, music, scores, clock);
    my_runner_set_structures_three(window, music, scores, clock);
}