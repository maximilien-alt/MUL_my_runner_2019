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

typedef struct window_s
{
    sfRenderWindow* window;
    sfEvent event;
}window_t;

typedef enum
{
    BACK,
    MID,
    FRONT
}PARALLAX;

typedef struct game_object_s
{
    PARALLAX type;
    float speed;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
}game_object_t;

#endif /* STRUCT_H_ */