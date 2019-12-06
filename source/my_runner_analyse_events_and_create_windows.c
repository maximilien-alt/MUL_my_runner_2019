/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_analyse_events_and_create_windows.c
*/

#include "../include/my.h"

void analyse_events(window_t *window, game_object_t *game_object)
{
    if (window->event.type == sfEvtClosed || \
    (sfKeyboard_isKeyPressed(sfKeyEscape)))
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtKeyPressed)
        manage_key_pressed(window, game_object);
    if (window->event.type == sfEvtMouseMoved && window->status == 1)
        manage_mouse_moved(game_object, window);
}

sfRenderWindow *create_window(int nb)
{
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "My_runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, nb);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
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
        game_object.size_max = rect.width;
    game_object.pos = pos;
    game_object.rect = rect;
    game_object.texture = sfTexture_createFromFile(filepath, NULL);
    game_object.sprite = sfSprite_create();
    sfSprite_setTexture(game_object.sprite, game_object.texture, sfTrue);
    sfSprite_setTextureRect(game_object.sprite, game_object.rect);
    sfSprite_setPosition(game_object.sprite, game_object.pos);
    return (game_object);
}

void my_create_game_object_next(game_object_t *game_object, window_t *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = {mouse.x, mouse.y};

    game_object[CURSOR] = create_object("sprites/cursor.png", \
    pos, (sfIntRect){0, 0, 200, 200}, CURSOR);
}

void my_create_game_object(game_object_t *game_object, window_t *window)
{
    game_object[BACK_1] = create_object("sprites/background_1.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, BACK_1);
    game_object[BACK] = create_object("sprites/background_2.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, BACK);
    game_object[MID] = create_object("sprites/background_3.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, MID);
    game_object[FRONT_1] = create_object("sprites/background_4.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, FRONT_1);
    game_object[FRONT_2] = create_object("sprites/background_5.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, FRONT_2);
    game_object[PRESS_START] = create_object("sprites/press_start.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, PRESS_START);
    game_object[PLAY] = create_object("sprites/play.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, PLAY);
    game_object[OPTIONS] = create_object("sprites/options.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, OPTIONS);
    game_object[QUIT] = create_object("sprites/quit.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, WIDTH, HEIGHT}, QUIT);
    my_create_game_object_next(game_object, window);
}