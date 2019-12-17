/*
** EPITECH PROJECT, 2019
** my
** File description:
** include
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#define WIDTH 1920
#define HEIGHT 1080

void my_check_victory(window_t *window, game_object_t *game_object, \
game_object_t *map, music_t musics);
void my_draw_victory(window_t *window, game_object_t *game_object, \
score_t scores);
void my_music_button_next(music_t musics, window_t *window, int check);
void my_runner_set_structures_three(window_t *window, \
music_t *music, score_t *scores, my_clock_t *clock);
void manage_mouse_click_three(window_t *window, game_object_t *game_object, \
music_t musics, score_t scores);
void please_no_lag(window_t *window);
void my_create_map(game_object_t *map, window_t *window);
void my_game_over(window_t *window, music_t musics, score_t scores);
void my_draw_game_over(window_t *window, game_object_t *game_object, \
score_t scores);
int get_my_position(window_t *window, game_object_t *game_object, \
music_t musics);
void my_destroy_map(window_t window, game_object_t *map, int nb_elems);
game_object_t create_object(char *filepath, sfVector2f pos, \
sfIntRect rect, PARALLAX type);
void my_destoy_object(game_object_t *game_object, \
window_t window, music_t musics, score_t scores);
void my_draw_status(window_t *window, game_object_t *game_object, \
score_t scores);
void my_loop(window_t window, game_object_t *game_object, \
music_t musics, score_t score);
char **get_map(char *filepath);
int my_error_handling(int ac, char *av[]);
void my_draw_speed(window_t *window, game_object_t *game_object, \
score_t scores);
void my_draw_status_next(window_t *window, game_object_t *game_object, \
score_t scores);
void manage_mouse_moved_four(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics);
void my_draw_gravity(window_t *window, game_object_t *game_object, \
score_t scores);
void my_check_highscore(score_t *scores);
void my_set_volumes(game_object_t *game_object, music_t music);
void my_draw_volume(window_t *window, game_object_t *game_object, \
score_t scores);
void manage_mouse_click_next(window_t *window, game_object_t *game_object, \
music_t musics);
void my_draw_options(window_t *window, game_object_t *game_object, \
score_t scores);
void my_clock(game_object_t *game_object, my_clock_t *clock, \
window_t *window, score_t *scores);
sfText *my_score(char *score, sfVector2f pos);
char *my_highscore(char *filepath);
void my_draw_jumping(window_t *window, game_object_t *game_object, \
score_t scores);
void my_music_button(music_t musics, window_t *window, int check);
void my_runner_set_structures(window_t *window, music_t *music, \
score_t *score, my_clock_t *clock);
void my_jump(game_object_t *game_object, window_t *window, \
music_t musics, score_t scores);
void my_draw_menu(window_t *window, game_object_t *game_object, \
score_t scores);
void my_draw_playing(window_t *window, game_object_t *game_object, \
score_t scores);
void move_rect(game_object_t *game_object, int offset, \
int max_size, int status);
int my_speed(int type);
int my_size_max(int type);
void manage_mouse_click(window_t *window, game_object_t *game_object, \
music_t musics, score_t scores);
void manage_mouse_moved(window_t *window, game_object_t *game_object, \
sfIntRect rect, music_t musics);
sfText* my_text(void);
void manage_key_pressed(window_t *window, game_object_t *game_object, \
music_t musics, score_t *scores);
sfText *my_press_space(void);
void my_create_game_object(game_object_t *game_object, window_t *window);
sfRenderWindow *create_window(int nb);
void analyse_events(window_t *window, game_object_t *game_object, \
music_t music, score_t scores);
int    my_infin_cmp(char *str, char *str2);
int    my_compute_power_rec(int nb, int p);
int    my_compute_square_root(int nb);
int    my_find_prime_sup(int nb);
int    my_getnbr(char const *str);
int    my_isneg(int n);
int    my_is_prime(int nb);
int    my_lengh(char const *str);
char    **my_malloc_words(char const *str, char **tab);
void    my_putchar(char c);
void    my_put_nbr(int nb);
int     my_putstr(char const *str);
char    *my_revstr(char *str);
int    my_showmem(char const *str, int size);
int    my_showstr(char const *str);
int    my_show_word_array(char * const *tab);
void    my_sort_int_array(int *tab, int size);
char    *my_strcapitalize(char *str);
char    *my_strcat(char *dest, char const *src);
char    my_strcmp(char const *s1, char const *s2);
char    *my_strcpy(char *dest, char const *src);
char    *my_strcpy2(char *dest, char const *src);
char    *my_strdup(char const *src);
int    my_str_isalpha(char const *str);
int    my_str_islower(char const *str);
int    my_str_isnum(char const *str);
int    my_str_isprintable(char const *str);
int    my_str_isupper(char const *str);
int    my_strlen(char const *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char const *src, int nb);
int    my_strncmp(char const *s1, char const *s2, int n);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strstr(char *str, char const *to_find);
char    **my_str_to_word_array(char const *str);
char    *my_strupcase(char *str);
void    my_swap(int *a, int *b);
int    my_prime(int nb);
int    my_strlen4(char const *str);
void    my_swap3(char const *dest, char const *src);
void    **my_malloc_word(char const *str, char * const *tab);
int    my_word_number(char const *str);
char   **my_word_in_tab(char const *str, char *const *tab);
int    my_str_neg(char *str, char *str2);
char    *my_infin_add(char *str, char *str2);
char    *my_infin_add_neg(char *str, char *str2);
char    *my_delete_neg(char *str);
int    my_str_is_negative(char *str);
char    *my_str_delete_null(char *str);
char    *my_cpy_without_null(char *str, char *cpy, int letter, int zero);
char    *my_supr_null(char *str, char *cpy, int letter);
char    *my_str_is_easy(char *str, char *cpy);

#endif /* MY_H_ */