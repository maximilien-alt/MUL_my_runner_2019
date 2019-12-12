/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_analyse_events_and_create_windows.c
*/

#include "../include/my.h"

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
    game_object.vel.x = 0;
    game_object.vel.y = 0;
    game_object.speed = my_speed(type);
    game_object.size_max = my_size_max(type);
    game_object.pos = pos;
    game_object.rect = rect;
    game_object.texture = sfTexture_createFromFile(filepath, NULL);
    game_object.sprite = sfSprite_create();
    sfSprite_setTexture(game_object.sprite, game_object.texture, sfTrue);
    sfSprite_setTextureRect(game_object.sprite, game_object.rect);
    sfSprite_setPosition(game_object.sprite, game_object.pos);
    if (type == CURSOR)
        sfSprite_setOrigin(game_object.sprite, (sfVector2f){100, 100});
    if (type == NINJA)
        sfSprite_setOrigin(game_object.sprite, (sfVector2f){84, 117.5});
    return (game_object);
}

void my_create_game_object_three(game_object_t *game_object, window_t *window)
{
    game_object[SPEED] = create_object("sprites/volume.png", \
    (sfVector2f){250, 500}, (sfIntRect){400, 0, 400, 200}, SPEED);
    game_object[SPEED_CHECK] = create_object("sprites/volume_check.png", \
    (sfVector2f){350, 500}, (sfIntRect){0, 0, 200, 200}, SPEED_CHECK);
    game_object[GAME_OVER] = create_object("sprites/game_over.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, GAME_OVER);
}

void my_create_game_object_next(game_object_t *game_object, window_t *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = {mouse.x, mouse.y};

    game_object[CURSOR] = create_object("sprites/cursor.png", \
    pos, (sfIntRect){0, 0, 200, 200}, CURSOR);
    game_object[NINJA] = create_object("sprites/ninja.png", \
    (sfVector2f){1920/2, 920}, (sfIntRect){0, 0, 168, 235}, NINJA);
    game_object[MENU_BACK] = create_object("sprites/back.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, MENU_BACK);
    game_object[MENU_OPTIONS] = create_object("sprites/options_2.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, MENU_OPTIONS);
    game_object[VOLUME] = create_object("sprites/volume.png", \
    (sfVector2f){850, 500}, (sfIntRect){0, 0, 200, 200}, VOLUME);
    game_object[VOLUME_CHECK] = create_object("sprites/volume_check.png", \
    (sfVector2f){850, 500}, (sfIntRect){0, 0, 200, 200}, VOLUME_CHECK);
    game_object[GRAVITY] = create_object("sprites/volume.png", \
    (sfVector2f){1350, 500}, (sfIntRect){200, 0, 200, 200}, GRAVITY);
    game_object[GRAVITY_CHECK] = create_object("sprites/volume_check.png", \
    (sfVector2f){1350, 500}, (sfIntRect){0, 0, 200, 200}, GRAVITY_CHECK);
    my_create_game_object_three(game_object, window);
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