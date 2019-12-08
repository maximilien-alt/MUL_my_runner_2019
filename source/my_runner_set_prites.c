/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_prites.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void manage_mouse_click(window_t *window, game_object_t *game_object)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = {mouse.x - 100, mouse.y - 100};

    if (window->status == 1 && pos.x > 751 && pos.x < 939 \
    && pos.y > 656 && pos.y < 706)
        sfRenderWindow_close(window->window);
}

void manage_mouse_moved(window_t *window, game_object_t *game_object, \
sfIntRect rect, sfIntRect rect_2)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = {mouse.x - 100, mouse.y - 100};

    sfSprite_setPosition(game_object[CURSOR].sprite, pos);
    if (window->status == 1 && pos.x > 735 && pos.x < 965 \
    && pos.y > 229 && pos.y < 282)
        sfSprite_setTextureRect(game_object[PLAY].sprite, rect);
    else
        sfSprite_setTextureRect(game_object[PLAY].sprite, rect_2);
    if (window->status == 1 && pos.x > 680 && pos.x < 1025 \
    && pos.y > 445 && pos.y < 494)
        sfSprite_setTextureRect(game_object[OPTIONS].sprite, rect);
    else
        sfSprite_setTextureRect(game_object[OPTIONS].sprite, rect_2);
    if (window->status == 1 && pos.x > 751 && pos.x < 939 \
    && pos.y > 656 && pos.y < 706)
        sfSprite_setTextureRect(game_object[QUIT].sprite, rect);
    else
        sfSprite_setTextureRect(game_object[QUIT].sprite, rect_2);
}

void manage_key_pressed(window_t *window, game_object_t *game_object)
{
    if (window->event.key.code == sfKeyRight) {
        for (int i = 1; i < PRESS_START; i += 1)
            game_object[i].speed += 1;
    }
    if (window->event.key.code == sfKeyLeft) {
        for (int i = 1; i <PRESS_START; i += 1)
            game_object[i].speed += -1;
    }
    if (window->status == 0 && window->event.key.code == sfKeySpace) {
        for (int i = 1; i < PRESS_START; i += 1)
            game_object[i].speed += 10;
        window->status = 1;
    }
}

sfText* my_text(void)
{
    sfText* text;
    sfFont* font;
    sfVector2f text_position = {767, 500};
    char * str = "OPTIONS";

    font = sfFont_createFromFile("sprites/text.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, text_position);
    return (text);
}