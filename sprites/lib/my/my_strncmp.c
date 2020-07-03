/*
** EPITECH PROJECT, 2019
** task06
** File description:
** my_strcmp
*/

int    my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int a = 0;

    if (n <= 0) {
        return (0);
    }
    while (n > 0) {
        if (s1[i] == s2[i]) {
            i++;
        }
        if (s1[i] == '\0' && s2[i] == '\0') {
            return (0);
        }
        n--;
    }
    a = s1[i]-s2[i];
    return (a);
}
