/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** character2.c
*/

#include "../include/my_hunter.h"

character_t animation_attack_left(character_t player1, sfRenderWindow * window)
{
    player1.animation.top = 128;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player1.clock)) >
        sfTime_asSeconds(sfMilliseconds(50))) {
        if (player1.animation.left == 0)
            player1.animation.left = 288;
        else
            player1.animation.left -= 32;
        sfClock_restart(player1.clock);
    }
    sfSprite_setTextureRect(player1.sp_c, player1.animation);
    return (player1);
}

character_t animation_attack_right(character_t player1, sfRenderWindow * window)
{
    player1.animation.top = 96;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player1.clock)) >
        sfTime_asSeconds(sfMilliseconds(50))) {
        if (player1.animation.left == 288)
            player1.animation.left = 0;
        else
            player1.animation.left += 32;
        sfClock_restart(player1.clock);
    }
    sfSprite_setTextureRect(player1.sp_c, player1.animation);
    return (player1);
}