/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct my_clock_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
}my_clock_t;

typedef struct score_s
{
    sfText *highscore;
    sfText* score;
    char *zero;
}score_t;

typedef struct music_s
{
    sfMusic *game_start;
    sfMusic *menu_button;
    sfMusic *playing;
    sfMusic *menu;
}music_t;

typedef struct window_s
{
    sfRenderWindow* window;
    sfEvent event;
    int status;
    int nb_jump;
    int check_play;
    int check_options;
    int check_quit;
}window_t;

typedef enum
{
    BACK_1,
    BACK,
    MID,
    FRONT_1,
    FRONT_2,
    PRESS_START,
    PLAY,
    OPTIONS,
    QUIT,
    CURSOR,
    NINJA,
    LEN
}PARALLAX;

typedef struct game_object_s
{
    PARALLAX type;
    float speed;
    int size_max;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfVector2f vel;
    sfIntRect rect;
}game_object_t;

#endif /* STRUCT_H_ */