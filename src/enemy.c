/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** enemy.c
*/

#include "../include/my_hunter.h"

enemy_t set_enemy(char *name)
{
    enemy_t enemy;
    sfImage *i_e = sfImage_createFromFile(name);
    enemy.t_e = sfTexture_createFromImage(i_e, NULL);
    enemy.sp_e = sfSprite_create();
    enemy.v_e.x = 1000;
    enemy.v_e.y = 600;
    enemy.scale.x = 3;
    enemy.scale.y = 3;
    enemy.animation.left = 288;
    enemy.animation.top = 0;
    enemy.animation.height = 32;
    enemy.animation.width = 30;
    enemy.death_animation.left = 288;
    enemy.clock = sfClock_create();
    enemy.deathClock = sfClock_create();
    enemy.dead = 0;
    sfSprite_setTexture(enemy.sp_e, enemy.t_e, sfTrue);
    sfSprite_setPosition(enemy.sp_e, enemy.v_e);
    sfSprite_setScale(enemy.sp_e, enemy.scale);
    return (enemy);
}

enemy_t animation_left_enemy(enemy_t enemy, sfRenderWindow *window)
{
    enemy.animation.top = 64;
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (enemy.animation.left == 0)
            enemy.animation.left = 288;
        else
            enemy.animation.left -= 32;
        sfClock_restart(enemy.clock);
    }
    sfSprite_setTextureRect(enemy.sp_e, enemy.animation);
    return (enemy);
}

enemy_t animation_attack_enemy(enemy_t enemy, sfRenderWindow *window)
{
    enemy.animation.top = 96;
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (enemy.animation.left == 0)
            enemy.animation.left = 288;
        else
            enemy.animation.left -= 32;
        sfClock_restart(enemy.clock);
    }
    if (enemy.v_e.x == 52 && enemy.animation.left == 96)
        enemy.v_e.x = 998;
    sfSprite_setTextureRect(enemy.sp_e, enemy.animation);
    return (enemy);
}

enemy_t animation_dead(enemy_t enemy, sfRenderWindow *window)
{
    enemy.death_animation.top = 128;
    enemy.death_animation.width = 30;
    enemy.death_animation.height = 32;
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy.deathClock)) >
        sfTime_asSeconds(sfMilliseconds(80))) {
        if (enemy.death_animation.left != 0)
            enemy.death_animation.left -= 32;
        sfClock_restart(enemy.deathClock);
    }
    sfSprite_setTextureRect(enemy.sp_e, enemy.death_animation);
    return (enemy);
}

enemy_t move_enemy(enemy_t enemy, sfRenderWindow *window, arrow_t arrow,
    float speed)
{
    if (arrow.touched != speed) {
        if (enemy.v_e.x > 52) {
            enemy.v_e.x -= speed;
            enemy = animation_left_enemy(enemy, window);
        } else if (enemy.v_e.x == 52) {
            enemy = animation_attack_enemy(enemy, window);
        }
    } else if (arrow.touched == speed) {
        enemy = animation_dead(enemy, window);
        enemy.dead = 1;
        if (enemy.death_animation.left == 0) {
            enemy.v_e.x = 1000;
            enemy.death_animation.left = 288;
            enemy.dead = 0;
        }
    }
    sfSprite_setPosition(enemy.sp_e, enemy.v_e);
    sfRenderWindow_drawSprite(window, enemy.sp_e, NULL);
    return (enemy);
}