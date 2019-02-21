/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** boss2.c
*/

#include "../include/my_hunter.h"

boss_t set_boss2(boss_t boss)
{
    boss.clock = sfClock_create();
    boss.deathClock = sfClock_create();
    boss.dead = 0;
    boss.life = 4;
    return (boss);
}

scene1_t move_or_attack(scene1_t scene1, sfRenderWindow *window, arrow_t arrow)
{
    if (scene1.boss.v_e.x > 52) {
        scene1.boss.v_e.x -= 2;
        scene1.boss = animation_left_boss(scene1.boss, window);
    } else if (scene1.boss.v_e.x == 52) {
        scene1.boss = animation_attack_boss(scene1.boss, window);
    }
    return (scene1);
}

scene1_t touch_boss(scene1_t scene1, sfRenderWindow *window, arrow_t arrow)
{
    scene1.boss.life -= 1;
    scene1.boss_bar.animation_boss.width -= 200;
    sfSprite_setTextureRect(scene1.boss_bar.sp, scene1.boss_bar.animation_boss);
    sfSprite_setPosition(scene1.boss_bar.sp_2, scene1.boss_bar.v_2);
    sfRenderWindow_drawSprite(window, scene1.boss_bar.sp_2, NULL);
    scene1.arrow.touched_boss = 0;
    sfClock_restart(scene1.boss.clock);
    return (scene1);
}