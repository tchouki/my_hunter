/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** heart_bar.c
*/

#include "../include/my_hunter.h"

heart_bar_t set_bar(void)
{
    heart_bar_t bar;
    sfImage *i_heart = sfImage_createFromFile("character/heart_bar.png");
    bar.t_heart = sfTexture_createFromImage(i_heart, NULL);
    bar.sp_heart = sfSprite_create();
    bar.v_heart.x = -8;
    bar.v_heart.y = 35;
    bar.scale.x = 0.5;
    bar.scale.y = 0.5;
    bar.animation.top = 0;
    bar.animation.left = 0;
    bar.animation.height = 100;
    bar.animation.width = 300;
    bar.clock = sfClock_create();
    sfSprite_setTexture(bar.sp_heart, bar.t_heart, sfTrue);
    sfSprite_setTextureRect(bar.sp_heart, bar.animation);
    sfSprite_setPosition(bar.sp_heart, bar.v_heart);
    sfSprite_setScale(bar.sp_heart, bar.scale);
    return (bar);
}

heart_bar_t destroy_heart(heart_bar_t bar, enemy_t enemy,
    sfRenderWindow *window, boss_t boss)
{
    if (enemy.v_e.x == 52 && enemy.animation.left == 128 &&
        sfTime_asSeconds(sfClock_getElapsedTime(bar.clock)) >
        sfTime_asSeconds(sfMilliseconds(200)) && bar.animation.width != 0) {
        bar.animation.width -= 100;
        sfClock_restart(bar.clock);
    }
    if (boss.v_e.x == 52 && boss.animation.left == 128 &&
        sfTime_asSeconds(sfClock_getElapsedTime(bar.clock)) >
        sfTime_asSeconds(sfMilliseconds(200)) && bar.animation.width != 0) {
        bar.animation.width -= 100;
        sfClock_restart(bar.clock);
    }
    if (bar.animation.width == 0) {
        bar.gameover = 1;
    }
    sfSprite_setTextureRect(bar.sp_heart, bar.animation);
    sfRenderWindow_drawSprite(window, bar.sp_heart, NULL);
    return (bar);
}

int swap_gameover(heart_bar_t bar, int s)
{
    if (bar.gameover == 1)
        s = 3;
    return (s);
}