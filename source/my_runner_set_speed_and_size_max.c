/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_set_speed_and_size_max.c
*/

#include "../include/my.h"
#include "../include/struct.h"

int my_speed(int type)
{
    if (type == PRESS_START || type == PLAY)
        return (1920);
    if (type == CURSOR)
        return (200);
    return (type);
}

int my_size_max(int type)
{
    if (type == PRESS_START)
        return (9600);
    if (type == CURSOR)
        return (1400);
    return (WIDTH);
}