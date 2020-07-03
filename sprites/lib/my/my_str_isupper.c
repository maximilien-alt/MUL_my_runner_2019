/*
** EPITECH PROJECT, 2019
** is_upper
** File description:
** is_upper
*/

int     my_str_isupper(char const *str)
{
    int letter = 0;
    int number = 0;

    while (str[letter] != '\0') {
        if (str[letter] >= 65 && str[letter] <= 90) {
            number = number + 1;
        }
        letter = letter + 1;
    }
    if (letter == number) {
        return (1);
    }
    return (0);
}
