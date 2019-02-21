/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** character.c
*/

#include "../include/my_hunter.h"

character_t set_character(void)
{
    character_t player1;
    sfImage *i_c = sfImage_createFromFile("character/ForestRanger.png");
    player1.t_c = sfTexture_createFromImage(i_c, NULL);
    player1.sp_c = sfSprite_create();
    player1.v_c.x = 50;
    player1.v_c.y = 600;
    player1.jump = 0;
    player1.scale.x = 3;
    player1.scale.y = 3;
    player1.animation.left = 0;
    player1.animation.top = 0;
    player1.animation.height = 32;
    player1.animation.width = 30;
    player1.clock = sfClock_create();
    player1.looking = RIGHT;
    sfSprite_setTexture(player1.sp_c, player1.t_c, sfTrue);
    sfSprite_setTextureRect(player1.sp_c, player1.animation);
    sfSprite_setPosition(player1.sp_c, player1.v_c);
    sfSprite_setScale(player1.sp_c, player1.scale);
    return (player1);
}

character_t animation_right(character_t player1, sfRenderWindow *window)
{
    player1.looking = RIGHT;
    player1.animation.top = 64;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player1.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (player1.animation.left == 288)
            player1.animation.left = 0;
        else
            player1.animation.left += 32;
        sfClock_restart(player1.clock);
    }
    sfSprite_setTextureRect(player1.sp_c, player1.animation);
    return (player1);
}

character_t animation_left(character_t player1, sfRenderWindow *window)
{
    player1.looking = LEFT;
    player1.animation.top = 32;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player1.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (player1.animation.left == 288)
            player1.animation.left = 0;
        else
            player1.animation.left += 32;
        sfClock_restart(player1.clock);
    }
    sfSprite_setTextureRect(player1.sp_c, player1.animation);
    return (player1);
}

character_t move_character(character_t player1, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (player1.v_c.x <= 1200)
            player1.v_c.x += 4;
        player1 = animation_right(player1, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (player1.v_c.x >= 50)
            player1.v_c.x -= 4;
        player1 = animation_left(player1, window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && player1.looking == RIGHT) {
        player1 = animation_attack_right(player1, window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && player1.looking == LEFT) {
        player1 = animation_attack_left(player1, window);
    }
    sfSprite_setPosition(player1.sp_c, player1.v_c);
    sfRenderWindow_drawSprite(window, player1.sp_c, NULL);
    return (player1);
}