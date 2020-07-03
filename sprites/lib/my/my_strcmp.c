/*
** EPITECH PROJECT, 2019
** task06
** File description:
** my_strcmp
*/

int    my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a = 0;

    while (s1[i] == s2[i] && s1[i]) {
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return (0);
    }
    a = s1[i]-s2[i];
    return (a);
}