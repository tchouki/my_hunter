/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** arrow2.c
*/

#include "../include/my_hunter.h"

scene1_t shoot_enemy(scene1_t scene1, sfRenderWindow *window)
{
    if (scene1.arrow.v_a.x == 1500 || (scene1.arrow.v_a.x >=
        scene1.enemy.v_e.x -15 && scene1.arrow.v_a.x <= scene1.enemy.v_e.x + 15)
        || scene1.arrow.v_a.y == 670) {
        if (scene1.arrow.v_a.x >= scene1.enemy.v_e.x - 15 &&
            scene1.arrow.v_a.x <= scene1.enemy.v_e.x + 15)
            scene1.arrow.touched = 2;
        scene1.arrow.pressed = 0;
        scene1.arrow.v_a.x = -200;
        sfSprite_setPosition(scene1.arrow.sp_a, scene1.arrow.v_a);
        sfRenderWindow_drawSprite(window, scene1.arrow.sp_a, NULL);
    }
    if (scene1.enemy.v_e.x == 1000)
        scene1.arrow.touched = 0;
    return (scene1);
}

scene1_t shoot_boss(scene1_t scene1, sfRenderWindow *window)
{
    if (scene1.arrow.v_a.x == 1500 || (scene1.arrow.v_a.x >=
        scene1.boss.v_e.x -15 && scene1.arrow.v_a.x <= scene1.boss.v_e.x + 15)
        || scene1.arrow.v_a.y == 670) {
        if (scene1.arrow.v_a.x >= scene1.boss.v_e.x - 15 && scene1.arrow.v_a.x
            <= scene1.boss.v_e.x + 15)
            scene1.arrow.touched_boss = 2;
        scene1.arrow.pressed = 0;
        scene1.arrow.v_a.x = -200;
        sfSprite_setPosition(scene1.arrow.sp_a, scene1.arrow.v_a);
        sfRenderWindow_drawSprite(window, scene1.arrow.sp_a, NULL);
    }
    if (scene1.boss.v_e.x == 1000)
        scene1.arrow.touched_boss = 0;
    return (scene1);
}

scene1_t shoot_enemy2(scene1_t scene1, sfRenderWindow *window)
{
    if (scene1.arrow.v_a.x == 1500 || (scene1.arrow.v_a.x >=
        scene1.enemy2.v_e.x -15 && scene1.arrow.v_a.x <=
        scene1.enemy2.v_e.x + 15 && scene1.arrow.v_a.y >= 630) ||
        scene1.arrow.v_a.y == 670) {
        if (scene1.arrow.v_a.x >= scene1.enemy2.v_e.x - 15 &&
            scene1.arrow.v_a.x <= scene1.enemy2.v_e.x + 15 && scene1.arrow.v_a.y
            >= 630)
            scene1.arrow.touched = 4;
        scene1.arrow.pressed = 0;
        scene1.arrow.v_a.x = -200;
        sfSprite_setPosition(scene1.arrow.sp_a, scene1.arrow.v_a);
        sfRenderWindow_drawSprite(window, scene1.arrow.sp_a, NULL);
    }
    if (scene1.enemy2.v_e.x == 1000)
        scene1.arrow.touched = 0;
    return (scene1);
}