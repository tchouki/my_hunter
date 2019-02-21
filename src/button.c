/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene0.c
*/

#include "../include/my_hunter.h"

button_t set_button_play(void)
{
    button_t button;
    sfImage *i_button = sfImage_createFromFile("menu/button_play.png");
    button.t_button = sfTexture_createFromImage(i_button, NULL);
    button.sp_button = sfSprite_create();
    sfImage *i_clicked = sfImage_createFromFile("menu/pressed_play.png");
    button.t_clicked = sfTexture_createFromImage(i_clicked, NULL);
    button.sp_cliked = sfSprite_create();
    button.v_button.x = 440;
    button.v_button.y = 250;
    button.scale.x = 2;
    button.scale.y = 2;
    sfSprite_setTexture(button.sp_button, button.t_button, sfTrue);
    sfSprite_setPosition(button.sp_button, button.v_button);
    sfSprite_setScale(button.sp_button, button.scale);
    sfSprite_setTexture(button.sp_cliked, button.t_clicked, sfTrue);
    sfSprite_setPosition(button.sp_cliked, button.v_button);
    sfSprite_setScale(button.sp_cliked, button.scale);
    return (button);
}

button_t set_button_help(void)
{
    button_t button;
    sfImage *i_button = sfImage_createFromFile("menu/button_help.png");
    button.t_button = sfTexture_createFromImage(i_button, NULL);
    button.sp_button = sfSprite_create();
    sfImage *i_clicked = sfImage_createFromFile("menu/pressed_help.png");
    button.t_clicked = sfTexture_createFromImage(i_clicked, NULL);
    button.sp_cliked = sfSprite_create();
    button.v_button.x = 440;
    button.v_button.y = 400;
    button.scale.x = 2;
    button.scale.y = 2;
    sfSprite_setTexture(button.sp_button, button.t_button, sfTrue);
    sfSprite_setPosition(button.sp_button, button.v_button);
    sfSprite_setScale(button.sp_button, button.scale);
    sfSprite_setTexture(button.sp_cliked, button.t_clicked, sfTrue);
    sfSprite_setPosition(button.sp_cliked, button.v_button);
    sfSprite_setScale(button.sp_cliked, button.scale);
    return (button);
}

button_t set_button_back(void)
{
    button_t button;
    sfImage *i_button = sfImage_createFromFile("menu/button_back.png");
    button.t_button = sfTexture_createFromImage(i_button, NULL);
    button.sp_button = sfSprite_create();
    sfImage *i_clicked = sfImage_createFromFile("menu/pressed_back.png");
    button.t_clicked = sfTexture_createFromImage(i_clicked, NULL);
    button.sp_cliked = sfSprite_create();
    button.v_button.x = 575;
    button.v_button.y = 600;
    button.scale.x = 1.5;
    button.scale.y = 1.5;
    sfSprite_setTexture(button.sp_button, button.t_button, sfTrue);
    sfSprite_setPosition(button.sp_button, button.v_button);
    sfSprite_setScale(button.sp_button, button.scale);
    sfSprite_setTexture(button.sp_cliked, button.t_clicked, sfTrue);
    sfSprite_setPosition(button.sp_cliked, button.v_button);
    sfSprite_setScale(button.sp_cliked, button.scale);
    return (button);
}