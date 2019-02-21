/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** boss.c
*/

#include "../include/my_hunter.h"

boss_t set_boss(void)
{
    boss_t boss;
    sfImage *i_e = sfImage_createFromFile("enemy/LuckyOrc.png");
    boss.t_e = sfTexture_createFromImage(i_e, NULL);
    boss.sp_e = sfSprite_create();
    boss.v_e.x = 1000;
    boss.v_e.y = 540;
    boss.scale.x = 5;
    boss.scale.y = 5;
    boss.animation.left = 288;
    boss.animation.top = 0;
    boss.animation.height = 32;
    boss.animation.width = 30;
    boss.death_animation.left = 288;
    boss = set_boss2(boss);
    sfSprite_setTexture(boss.sp_e, boss.t_e, sfTrue);
    sfSprite_setPosition(boss.sp_e, boss.v_e);
    sfSprite_setScale(boss.sp_e, boss.scale);
    return (boss);
}

boss_t animation_left_boss(boss_t boss, sfRenderWindow *window)
{
    boss.animation.top = 64;
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (boss.animation.left == 0)
            boss.animation.left = 288;
        else
            boss.animation.left -= 32;
        sfClock_restart(boss.clock);
    }
    sfSprite_setTextureRect(boss.sp_e, boss.animation);
    return (boss);
}

boss_t animation_attack_boss(boss_t boss, sfRenderWindow *window)
{
    boss.animation.top = 96;
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (boss.animation.left == 0)
            boss.animation.left = 288;
        else
            boss.animation.left -= 32;
        sfClock_restart(boss.clock);
    }
    if (boss.v_e.x == 52 && boss.animation.left == 96)
        boss.v_e.x = 998;
    sfSprite_setTextureRect(boss.sp_e, boss.animation);
    return (boss);
}

boss_t animation_dead_boss(boss_t boss, sfRenderWindow *window)
{
    boss.death_animation.top = 128;
    boss.death_animation.width = 30;
    boss.death_animation.height = 32;
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss.deathClock)) >
        sfTime_asSeconds(sfMilliseconds(80))) {
        if (boss.death_animation.left != 0)
            boss.death_animation.left -= 32;
        sfClock_restart(boss.deathClock);
    }
    sfSprite_setTextureRect(boss.sp_e, boss.death_animation);
    return (boss);
}

scene1_t move_boss(scene1_t scene1, sfRenderWindow *window, arrow_t arrow)
{
    if (arrow.touched_boss == 0) {
        scene1 = move_or_attack(scene1, window, arrow);
    } else if (arrow.touched_boss == 2 &&
        sfTime_asSeconds(sfClock_getElapsedTime(scene1.boss.clock)) >
        sfTime_asSeconds(sfMilliseconds(500)) && scene1.boss.life > 0) {
        scene1 = touch_boss(scene1, window, arrow);
    } else if (scene1.boss.life == 0) {
        scene1.boss = animation_dead_boss(scene1.boss, window);
        scene1.boss.dead = 1;
        if (scene1.boss.death_animation.left == 0) {
            scene1.boss.v_e.x = 1000;
            scene1.boss.death_animation.left = 288;
            scene1.boss.dead = 0;
        }
    }
    sfSprite_setPosition(scene1.boss.sp_e, scene1.boss.v_e);
    sfRenderWindow_drawSprite(window, scene1.boss.sp_e, NULL);
    return (scene1);
}