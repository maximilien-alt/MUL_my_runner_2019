/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner_highscore.c
*/

#include "../include/my.h"
#include "../include/struct.h"

void my_check_victory(window_t *window, game_object_t *game_object, \
game_object_t *map, music_t musics)
{
    if (window->status == 2 && \
    map[window->check_map - 1].pos.x <= game_object[NINJA].pos.x) {
        sfSound_play(musics.victory_sound);
        sfMusic_pause(musics.playing);
        window->status = 9;
    }
}

void my_music_button_next(music_t musics, window_t *window, int check)
{
    if (window->check_menu == 0 && check == 5) {
        sfMusic_play(musics.menu_button);
        sfMusic_setLoop(musics.menu_button, sfTrue);
    }
}

void my_check_highscore(score_t *scores)
{
    int fd;

    if (my_infin_cmp(scores->highscore_str, scores->zero) == 0) {
        scores->highscore_str = scores->zero;
        sfText_setString(scores->highscore, scores->zero);
        fd = open("sprites/highscore", O_WRONLY);
        write(fd, scores->highscore_str, my_strlen(scores->highscore_str));
        close(fd);
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