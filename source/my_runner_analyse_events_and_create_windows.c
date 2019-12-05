/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_analyse_events_and_create_windows.c
*/

#include "../include/my.h"

void analyse_events(window_t *window)
{
    if (window->event.type == sfEvtClosed || \
    (sfKeyboard_isKeyPressed(sfKeyEscape)))
        sfRenderWindow_close(window->window);
}

sfRenderWindow *create_window(int nb)
{
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "My_runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, nb);
    return (window);
}

game_object_t create_object(char *filepath, sfVector2f pos, \
sfIntRect rect, PARALLAX type)
{
    game_object_t game_object;

    game_object.type = type;
    if (type == 5)
        game_object.speed = 1920;
    else
        game_object.speed = type;
    if (type == 5)
        game_object.size_max = 9600;
    else
        game_object.size_max = WIDTH;
    game_object.pos = pos;
    game_object.rect = rect;
    game_object.texture = sfTexture_createFromFile(filepath, NULL);
    game_object.sprite = sfSprite_create();
    sfSprite_setTexture(game_object.sprite, game_object.texture, sfTrue);
    sfSprite_setTextureRect(game_object.sprite, game_object.rect);
    sfSprite_setPosition(game_object.sprite, game_object.pos);
    return (game_object);
}

void my_create_game_object(game_object_t *parallax)
{
    parallax[BACK_1] = create_object("sprites/background_1.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, BACK_1);
    parallax[BACK] = create_object("sprites/background_2.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, BACK);
    parallax[MID] = create_object("sprites/background_3.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, MID);
    parallax[FRONT_1] = create_object("sprites/background_4.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, FRONT_1);
    parallax[FRONT_2] = create_object("sprites/background_5.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, FRONT_2);
    parallax[PRESS_START] = create_object("sprites/press_start.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, PRESS_START);
}