/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/System.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>

#define RIGHT 0
#define LEFT 1

typedef struct background {
    sfTexture *t_background;
    sfSprite *sp_background;
} background_t;

typedef struct message {
    sfImage *i_m1;
    sfTexture *t_m;
    sfSprite *sp_m;
    sfVector2f v_m;
    sfVector2f scale;
    sfIntRect animation;
    sfClock *clock;
    int draw;
} message_t;

typedef struct character {
    sfTexture *t_c;
    sfSprite *sp_c;
    sfVector2f v_c;
    int jump;
    sfVector2f scale;
    sfIntRect animation;
    sfClock *clock;
    int looking;
} character_t;

typedef struct enemy {
    sfTexture *t_e;
    sfSprite *sp_e;
    sfVector2f v_e;
    sfVector2f scale;
    sfIntRect animation;
    sfIntRect death_animation;
    sfClock *clock;
    sfClock *deathClock;
    int dead;
} enemy_t;

typedef struct boss {
    sfTexture *t_e;
    sfSprite *sp_e;
    sfVector2f v_e;
    sfVector2f scale;
    sfIntRect animation;
    sfIntRect death_animation;
    sfClock *clock;
    sfClock *deathClock;
    int dead;
    int life;
} boss_t;

typedef struct boss_bar {
    sfTexture *t;
    sfSprite *sp;
    sfVector2f v;
    sfVector2f scale;
    sfTexture *t_2;
    sfSprite *sp_2;
    sfVector2f v_2;
    sfVector2f scale_2;
    sfIntRect animation_boss;
    sfClock *clock;
} boss_bar_t;

typedef struct bird {
    sfTexture *t_b;
    sfSprite *sp_b;
    sfVector2f v_b;
    sfIntRect animation;
    sfClock *clock;
    int right_left;
} bird_t;

typedef struct arrow {
    sfTexture *t_a;
    sfSprite *sp_a;
    sfVector2f v_a;
    sfClock *clock;
    sfVector2f scale;
    int pressed;
    float touched;
    int touched_boss;
} arrow_t;

typedef struct death_counter {
    sfText *text;
    int nbr_death;
    sfVector2f v_text;
    char *string;
} death_counter_t;

typedef struct heart_bar {
    sfTexture *t_heart;
    sfSprite *sp_heart;
    sfVector2f v_heart;
    sfIntRect animation;
    sfVector2f scale;
    sfClock *clock;
    int gameover;
} heart_bar_t;

typedef struct button {
    sfTexture *t_button;
    sfSprite *sp_button;
    sfTexture *t_clicked;
    sfSprite *sp_cliked;
    sfVector2f v_button;
    sfVector2f scale;
} button_t;

typedef struct scene4 {
    button_t button_menu;
    button_t button_back;
} scene4_t;

typedef struct scene3 {
    button_t button;
    death_counter_t death_counter;
    sfVector2f pos_death;
} scene3_t;

typedef struct scene2 {
    button_t button;
} scene2_t;

typedef struct scene1 {
    character_t character;
    enemy_t enemy;
    enemy_t enemy2;
    boss_t boss;
    bird_t bird1;
    bird_t bird2;
    arrow_t arrow;
    death_counter_t death_counter;
    heart_bar_t heart_bar;
    boss_bar_t boss_bar;
    message_t message;
} scene1_t;

typedef struct scene0 {
    button_t button1;
    button_t button2;
} scene0_t;

typedef struct game {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    scene0_t scene0;
    scene1_t scene1;
    scene2_t scene2;
    scene3_t scene3;
    scene4_t scene4;
    background_t map_background;
    background_t menu_background;
    background_t help_background;
    background_t gameover_background;
    sfMusic *music;
    int s;
} game_t;

//message.c
message_t set_message(void);
scene1_t choose_message(scene1_t scene1);
message_t draw_message(message_t message, sfRenderWindow *window);

//boss_bar.c
boss_bar_t set_boss_bar(void);
boss_bar_t set_animation_boss_bar(void);
scene1_t display_boss_bar(scene1_t scene1, sfRenderWindow *window);

//bird.c
bird_t set_bird(char *c, int x, int y);
bird_t animation_left_bird(bird_t bird, sfRenderWindow *window);
bird_t animation_right_bird(bird_t bird, sfRenderWindow *window);
bird_t move_bird(bird_t bird, sfRenderWindow *window);

//character.c
character_t set_character(void);
character_t animation_attack_left(character_t player1, sfRenderWindow * window);
character_t animation_attack_right(character_t player1, sfRenderWindow * window);
character_t animation_right(character_t player1, sfRenderWindow *window);
character_t animation_left(character_t player1, sfRenderWindow *window);
character_t move_character(character_t player1, sfRenderWindow *window);

//enemy.c
enemy_t set_enemy(char *name);
enemy_t animation_left_enemy(enemy_t enemy, sfRenderWindow *window);
enemy_t animation_attack_enemy(enemy_t enemy, sfRenderWindow *window);
enemy_t animation_dead(enemy_t enemy, sfRenderWindow *window);
enemy_t move_enemy(enemy_t enemy, sfRenderWindow *window, arrow_t arrow, float speed);

//boss2.c
boss_t set_boss2(boss_t boss);
scene1_t move_or_attack(scene1_t scene1, sfRenderWindow *window, arrow_t arrow);
scene1_t touch_boss(scene1_t scene1, sfRenderWindow *window, arrow_t arrow);

//boss.c
boss_t set_boss(void);
boss_t animation_left_boss(boss_t boss, sfRenderWindow *window);
boss_t animation_attack_boss(boss_t boss, sfRenderWindow *window);
boss_t animation_dead_boss(boss_t boss, sfRenderWindow *window);
scene1_t move_boss(scene1_t scene1, sfRenderWindow *window, arrow_t arrow);

//arrow2.c
scene1_t shoot_enemy(scene1_t scene1, sfRenderWindow *window);
scene1_t shoot_boss(scene1_t scene1, sfRenderWindow *window);
scene1_t shoot_enemy2(scene1_t scene1, sfRenderWindow *window);

//arrow.c
arrow_t set_arrow(character_t player1);
arrow_t move_arrow(arrow_t arrow, sfRenderWindow *window, character_t player1);
scene1_t shoot(scene1_t scene1, sfRenderWindow *window);

//death_counter.c
death_counter_t set_death_counter(void);
char *my_evil_str(char *str);
char *my_put_nbr(int nbr);
death_counter_t increment_death(death_counter_t counter, enemy_t enemy, sfRenderWindow *window, boss_t boss);

//heart_bar.c
heart_bar_t set_bar(void);
heart_bar_t destroy_heart(heart_bar_t bar, enemy_t enemy, sfRenderWindow *window, boss_t boss);
int swap_gameover(heart_bar_t bar, int s);

//scene4.c
scene4_t set_pause_menu(void);
scene4_t play_pause(scene4_t scene4, sfRenderWindow *window);
int back_pause_menu(scene4_t scene4, sfRenderWindow *window, int s);

//scene3.c
scene3_t set_gameover(void);
scene3_t play_gameover(scene3_t scene3, sfRenderWindow *window, scene1_t scene1);
int back_menu_gameover(scene3_t scene3, sfRenderWindow *window, int s);

//scene2.c
scene2_t set_help(void);
scene2_t play_help(scene2_t scene2, sfRenderWindow *window);
int back_menu(scene2_t scene2, sfRenderWindow *window, int s);

//scene1.c
scene1_t set_game(void);
scene1_t play_game(scene1_t scene1, sfRenderWindow *window);

//scene0.c
scene0_t set_menu(void);
scene0_t play_menu(scene0_t scene0, sfRenderWindow *window);
int swap_scene(scene0_t scene0, sfRenderWindow *window, int s);

//button.c
button_t set_button_play(void);
button_t set_button_help(void);
button_t set_button_back(void);

//background.c
background_t set_background(char *str);

//game.c
game_t set_main(void);
game_t play_scene4(game_t game);
game_t play_scene3(game_t game);
game_t play_scene2(game_t game);
game_t play_scene1(game_t game);
game_t play_scene0(game_t game);

//main.c
void event(sfRenderWindow *window);
int my_window(int helper);

#endif