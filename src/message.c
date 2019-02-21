/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** message.c
*/

#include "../include/my_hunter.h"

message_t set_message(void)
{
    message_t message;
    message.i_m1 = sfImage_createFromFile("message/Untitled.png");
    message.t_m = sfTexture_createFromImage(message.i_m1, NULL);
    message.sp_m = sfSprite_create();
    message.v_m.x = 10;
    message.v_m.y = 250;
    message.scale.x = 0.5;
    message.scale.y = 0.5;
    message.animation.left = 0;
    message.animation.top = 0;
    message.animation.height = 388;
    message.animation.width = 841;
    message.clock = sfClock_create();
    message.draw = 0;
    sfSprite_setTexture(message.sp_m, message.t_m, sfTrue);
    sfSprite_setTextureRect(message.sp_m, message.animation);
    sfSprite_setPosition(message.sp_m, message.v_m);
    sfSprite_setScale(message.sp_m, message.scale);
    return (message);
}

scene1_t choose_message(scene1_t scene1)
{
    if (scene1.death_counter.nbr_death == 10) {
        scene1.message.animation.left = 841;
        scene1.message.draw = 1;
    } else if (scene1.death_counter.nbr_death == 20) {
        scene1.message.animation.left = 1682;
        scene1.message.draw = 1;
    } else if (scene1.death_counter.nbr_death == 1) {
        scene1.message.animation.left = 0;
        scene1.message.draw = 1;
    }
    return (scene1);
}

message_t draw_message(message_t message, sfRenderWindow *window)
{
    if (message.draw == 1) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(message.clock)) >
            sfTime_asSeconds(sfMilliseconds(1000))) {
            message.draw = 0;
        }
    } else {
        message.animation.left = 4205;
        sfClock_restart(message.clock);
    }
    sfSprite_setTextureRect(message.sp_m, message.animation);
    sfRenderWindow_drawSprite(window, message.sp_m, NULL);
    return (message);
}