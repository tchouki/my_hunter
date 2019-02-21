/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene1.c
*/

#include "../include/my_hunter.h"

scene1_t set_game(void)
{
    scene1_t scene1;
    scene1.character = set_character();
    scene1.enemy = set_enemy("enemy/HunterOrc.png");
    scene1.enemy2 = set_enemy("enemy/ArmourPsionicGoblin.png");
    scene1.boss = set_boss();
    scene1.bird1 = set_bird("list_bird/bird_1_bluejay.png", 1300, 100);
    scene1.bird2 = set_bird("list_bird/bird_1_red.png", 2000, 200);
    scene1.arrow = set_arrow(scene1.character);
    scene1.death_counter = set_death_counter();
    scene1.heart_bar = set_bar();
    scene1.boss_bar = set_boss_bar();
    scene1.boss_bar = set_animation_boss_bar();
    scene1.message = set_message();
    return (scene1);
}

scene1_t spawn_boss(scene1_t scene1, sfRenderWindow *window)
{
    if (scene1.death_counter.nbr_death % 10 == 0 &&
        scene1.death_counter.nbr_death != 0) {
        scene1 = move_boss(scene1, window, scene1.arrow);
        scene1 = display_boss_bar(scene1, window);
        scene1.enemy.v_e.x = 990;
        scene1.enemy2.v_e.x = 990;
    } else {
        scene1.boss.v_e.x = 990;
        scene1.boss_bar.animation_boss.width = 1000;
        scene1.boss.life = 4;
        scene1.enemy = move_enemy(scene1.enemy, window, scene1.arrow, 2);
        scene1.enemy2 = move_enemy(scene1.enemy2, window, scene1.arrow, 4);
    }
    return (scene1);
}

scene1_t play_game(scene1_t scene1, sfRenderWindow *window)
{
    scene1.character = move_character(scene1.character, window);
    scene1 = spawn_boss(scene1, window);
    scene1.heart_bar = destroy_heart(scene1.heart_bar, scene1.enemy, window,
        scene1.boss);
    scene1.heart_bar = destroy_heart(scene1.heart_bar, scene1.enemy2, window,
        scene1.boss);
    scene1.bird1 = move_bird(scene1.bird1, window);
    scene1.bird2 = move_bird(scene1.bird2, window);
    scene1 = shoot(scene1, window);
    scene1.death_counter = increment_death(scene1.death_counter, scene1.enemy,
        window, scene1.boss);
    scene1.death_counter = increment_death(scene1.death_counter, scene1.enemy2,
        window, scene1.boss);
    scene1 = choose_message(scene1);
    scene1.message = draw_message(scene1.message, window);
    return (scene1);
}