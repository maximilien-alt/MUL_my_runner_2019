/*
** EPITECH PROJECT, 2019
** is_lower
** File description:
** is_lower
*/

int    my_str_islower(char const *str)
{
    int letter = 0;
    int number = 0;

    while (str[letter] != '\0'){
        if (str[letter] >= 97 && str[letter] <= 122) {
            number = number + 1;
        }
        letter = letter + 1;
    }
    if (letter == number) {
        return (1);
    }
    return (0);
}
