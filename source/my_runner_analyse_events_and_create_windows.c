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
    sfVideoMode mode = {800, 600, 32};

    window = sfRenderWindow_create(mode, "My_runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, nb);
    return (window);
}

game_object_t create_object(char *filepath, sfVector2f pos, \
sfIntRect rect, int status)
{
    game_object_t game_object;

    game_object.type = status;
    if (status == 0)
        game_object.speed = 10;
    if (status == 1)
        game_object.speed = 20;
    if (status == 2)
        game_object.speed = 40;
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
    parallax[0] = create_object("sprites/back.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 800, 600}, BACK);
    parallax[1] = create_object("sprites/mid.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 800, 600}, MID);
    parallax[2] = create_object("sprites/front.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 800, 600}, FRONT);
}