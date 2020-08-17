/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

int    my_str_isnum(char const *str)
{
    int letter = 0;
    int number = 0;

    while (str[letter] != '\0') {
        if ((str[letter] >= '0' && str[letter] <= '9') || str[letter] == '-') {
            number = number  + 1;
        }
        letter = letter + 1;
    }
    if (letter == number) {
        return (1);
    }
    return (0);
}
