/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** death_counter.c
*/

#include "../include/my_hunter.h"

boss_bar_t set_boss_bar(void)
{
    boss_bar_t boss_bar;
    sfImage *i = sfImage_createFromFile("enemy/boss_bar_full.png");
    boss_bar.t = sfTexture_createFromImage(i, NULL);
    boss_bar.sp = sfSprite_create();
    boss_bar.v.x = 0;
    boss_bar.v.y = 0;
    boss_bar.scale.x = 0.1;
    boss_bar.scale.y = 0.1;
    boss_bar.animation_boss.top = 0;
    boss_bar.animation_boss.left = 0;
    boss_bar.animation_boss.height = 150;
    boss_bar.animation_boss.width = 1000;
    sfSprite_setTexture(boss_bar.sp, boss_bar.t, sfTrue);
    sfSprite_setTextureRect(boss_bar.sp, boss_bar.animation_boss);
    sfSprite_setPosition(boss_bar.sp, boss_bar.v);
    sfSprite_setScale(boss_bar.sp, boss_bar.scale);
    return (boss_bar);
}

boss_bar_t set_animation_boss_bar(void)
{
    boss_bar_t boss_bar;
    sfImage *i_animation = sfImage_createFromFile("enemy/boss_bar_empty.png");
    boss_bar.t_2 = sfTexture_createFromImage(i_animation, NULL);
    boss_bar.sp_2 = sfSprite_create();
    boss_bar.v_2.x = 0;
    boss_bar.v_2.y = 0;
    boss_bar.scale_2.x = 0.1;
    boss_bar.scale_2.y = 0.1;
    sfSprite_setTexture(boss_bar.sp_2, boss_bar.t_2, sfTrue);
    sfSprite_setPosition(boss_bar.sp_2, boss_bar.v_2);
    sfSprite_setScale(boss_bar.sp_2, boss_bar.scale_2);
    return (boss_bar);
}

scene1_t display_boss_bar(scene1_t scene1, sfRenderWindow *window)
{
    scene1.boss_bar.v.x = scene1.boss.v_e.x + 35;
    scene1.boss_bar.v.y = scene1.boss.v_e.y - 20;
    scene1.boss_bar.v_2.x = scene1.boss.v_e.x + 35;
    scene1.boss_bar.v_2.y = scene1.boss.v_e.y - 20;
    sfSprite_setTextureRect(scene1.boss_bar.sp, scene1.boss_bar.animation_boss);
    sfSprite_setPosition(scene1.boss_bar.sp_2, scene1.boss_bar.v_2);
    sfRenderWindow_drawSprite(window, scene1.boss_bar.sp_2, NULL);
    sfSprite_setPosition(scene1.boss_bar.sp, scene1.boss_bar.v);
    sfRenderWindow_drawSprite(window, scene1.boss_bar.sp, NULL);
    return (scene1);
}