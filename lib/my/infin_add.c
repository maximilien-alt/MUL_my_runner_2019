/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add_2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

int    my_error(int argc, char *argv[])
{
    int av1_num = 0;
    int av2_num = 0;

    if (argc < 3 || argc > 3) {
        return (1);
    }
    av1_num = my_str_isnum(argv[1]);
    av2_num = my_str_isnum(argv[2]);
    if (av1_num == 0 || av2_num == 0) {
        return (1);
    }
    return (0);
}

char    *my_calc_str(char *str, char *cpy, char *result, int letter)
{
    int str_len = my_strlen(str) - 1;

    while (str_len > 0) {
        if ((str[str_len] + cpy[str_len] - '0') <= '9') {
            result[letter] = str[str_len] + cpy[str_len] - '0';
        } else {
            result[letter] = (str[str_len] + cpy[str_len] - '0') - 10;
            str[str_len - 1] += 1;
        }
        letter += 1;
        str_len += -1;
    }
    if ((str[str_len] + cpy[str_len] - '0') > '9') {
        result[letter] = (str[str_len] + cpy[str_len] - '0') - 10;
        result[letter + 1] = '1';
        result[letter + 2] = '\0';
    } else {
        result[letter] = str[str_len] + cpy[str_len] - '0';
        result[letter + 1] = '\0';
    }
    return (my_revstr(result));
}

char    *create_my_cpy(char *str, char *cpy, char *result, char *str2)
{
    int letter = 0;

    while (str[letter] != '\0') {
        cpy[letter] = str[letter];
        letter += 1;
    }
    while (str2[letter]) {
        cpy[letter] = '0';
        letter += 1;
    }
    cpy[letter] = '\0';
    my_revstr(cpy);
    return (my_calc_str(str2, cpy, result, 0));
}

char    *my_infin_add(char *str, char *str2)
{
    int str_len = my_strlen(str);
    int str_len2 = my_strlen(str2);
    char *result;
    char *cpy;

    if (str_len > str_len2) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        result = malloc(sizeof(char) * (str_len + 3));
        my_revstr(str2);
        cpy = create_my_cpy(str2, cpy, result, str);
        return (my_str_delete_null(result));
    } else {
        cpy = malloc(sizeof(char) * (str_len2 + 1));
        result = malloc(sizeof(char) * (str_len2 + 3));
        my_revstr(str);
        cpy = create_my_cpy(str, cpy, result, str2);
        return (my_str_delete_null(result));
    }
}