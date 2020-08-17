/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

char    *my_strdup(char const *src)
{
    int i = 0;
    int a = 0;
    char *str;

    while (src[i] != '\0') {
        i++;
    }
    str = malloc(sizeof(char) * (i+1));
    while (src[a] != '\0') {
        str[a] = src[a];
        a++;
    }
    str[i] = '\0';
    return (str);
}
