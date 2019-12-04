/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** my_str_delete_null.c
*/

#include <stdlib.h>

int my_strlen(char *str);

char    *my_str_is_easy(char *str, char *cpy)
{
    int str_len = my_strlen(str);
    int letter = 0;

    cpy = malloc(sizeof(char) * str_len);
    while (str[letter]) {
        cpy[letter] = str[letter];
        letter += 1;
    }
    cpy[letter] = '\0';
    return (cpy);
}

char    *my_supr_null(char *str, char *cpy, int letter)
{
    int cursor = 0;
    int i = 0;

    if (cpy[cursor] = '-') {
        cursor += 1;
        i += 1;
    }
    while (letter > 1) {
        cursor += 1;
        letter += -1;
    }
    while (str[cursor]) {
        cpy[i] = str[cursor];
        i += 1;
        cursor += 1;
    }
    cpy[i] = '\0';
    return (cpy);
}

char    *my_cpy_without_null(char *str, char *cpy, int letter, int zero)
{
    int str_len = my_strlen(str);

    if (str[0] != '0')
        return (my_str_is_easy(str, cpy));
    while (str[letter] == '0' && str[letter])
        letter += 1;
    if (letter == str_len) {
        cpy = malloc(sizeof(char) * 2);
        cpy[0] = '0';
        cpy[1] = '\0';
        return (cpy);
    }
    cpy = malloc(sizeof(char) * ((str_len - letter) + 1));
    while (str[letter]) {
        cpy[zero] = str[letter];
        letter += 1;
        zero += 1;
    }
    cpy[zero] = '\0';
    return (cpy);
}

char    *my_str_delete_null(char *str)
{
    int letter = 0;
    int str_len = my_strlen(str);
    char *cpy;

    if (str[0] != '-')
        return (my_cpy_without_null(str, cpy, 0, 0));
    while ((str[letter] == '0' || str[letter] == '-') && str[letter])
        letter += 1;
    if (letter == str_len) {
        cpy = malloc(sizeof(char) * 2);
        cpy[0] = '0';
        cpy[1] = '\0';
        return (cpy);
    }
    if (str[0] == '-') {
        cpy = malloc(sizeof(char) * ((str_len - letter) + 2));
        cpy[0] = '-';
    } else {
        cpy = malloc(sizeof(char) * ((str_len - letter) + 1));
    }
    return (my_supr_null(str, cpy, letter));
}