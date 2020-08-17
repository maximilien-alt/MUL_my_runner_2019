/*
** EPITECH PROJECT, 2019
** is_printable
** File description:
** is_printable
*/

int    my_str_isprintable(char const *str)
{
    int letter = 0;
    int number = 0;

    while (str[letter] != '\0') {
        if (str[letter] >= 32 && str[letter] != 127) {
            number = number + 1;
        }
        letter = letter + 1;
    }
    if (number == letter) {
        return (1);
    }
    return (0);
}

