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
    MENU_BACK,
    MENU_OPTIONS,
    VOLUME,
    VOLUME_CHECK,
    GRAVITY,
    GRAVITY_CHECK,
    SPEED,
    SPEED_CHECK,
    GAME_OVER,
    MENU,
    VICTORY,
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
    char *highscore_str;
}score_t;

typedef struct music_s
{
    sfMusic *menu_button;
    sfMusic *playing;
    sfMusic *menu;
    sfSound *over;
    sfSoundBuffer *buffer;
    sfSound *game_start;
    sfSound *victory_sound;
    sfSoundBuffer *buffer_start;
    sfSoundBuffer *victory;
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
    int check_back;
    int check_over;
    int check_menu;
    int grav;
    int inf;
    int check_pause;
    int check_speed;
    char **map;
    int check_map;
    game_object_t *map_object;
    sfText *text;
}window_t;


#endif /* STRUCT_H_ */