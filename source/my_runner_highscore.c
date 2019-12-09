/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_highscore.c
*/

#include "../include/my.h"
#include "../include/my.h"

sfText *my_score(char *score, sfVector2f pos)
{
    sfText* final_score;
    sfFont* font;

    font = sfFont_createFromFile("sprites/text.ttf");
    final_score = sfText_create();
    sfText_setString(final_score, score);
    sfText_setFont(final_score, font);
    sfText_setCharacterSize(final_score, 80);
    sfText_setPosition(final_score, pos);
    sfText_setColor(final_score, sfCyan);
    return (final_score);
}

char *my_highscore(char *filepath)
{
    char *highscore;
    int fd = 0;
    struct stat st;

    fd = open(filepath, O_RDONLY);
    stat(filepath, &st);
    highscore = malloc(sizeof(char) * st.st_size + 1);
    read(fd, highscore, st.st_size + 1);
    highscore[st.st_size] = '\0';
    close (fd);
    return (highscore);
}