/*
** EPITECH PROJECT, 2019
** is_alpha
** File description:
** is_alpha
*/

int    my_str_isalpha(char const *str)
{
    int letter = 0;
    int number = 0;

    while (str[letter] != '\0') {
        if ((str[letter] >= 65 && str[letter] <= 90) ||
                (str[letter] >= 97 && str[letter] <= 122)) {
                    number = number + 1;
        }
        letter = letter + 1;
    }
    if (number == letter) {
        return (1);
    }
    return (0);
}
