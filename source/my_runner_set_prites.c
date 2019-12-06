/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_prites.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void manage_mouse_moved(game_object_t *game_object, window_t *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = {mouse.x - 100, mouse.y - 100};

    sfSprite_setPosition(game_object[CURSOR].sprite, pos);
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
    if (window->event.key.code == sfKeySpace && window->status == 0)
        window->status = 1;
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