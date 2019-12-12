/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_highscore.c
*/

#include "../include/my.h"
#include "../include/my.h"

void please_no_lag(window_t *window)
{
    for (int i = 0; i < window->check_map; i += 1) {
        if (window->map_object[i].pos.x < - 20) {
            //sfSprite_destroy(window->map_object[i].sprite);
            sfTexture_destroy(window->map_object[i].texture);
        }
    }
}

void my_destroy_map(window_t window, game_object_t *map, int nb_elems)
{
    for (int i = 0; i < nb_elems; i += 1) {
        sfTexture_destroy(map[i].texture);
        sfSprite_destroy(map[i].sprite);
    }
}

void my_check_highscore(score_t scores)
{
    int fd;

    if (my_infin_cmp(scores.highscore_str, scores.zero) == 0) {
        scores.highscore_str = scores.zero;
        fd = open("sprites/highscore", O_WRONLY);
        write(fd, scores.highscore_str, my_strlen(scores.highscore_str));
    }
}

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