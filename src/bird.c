/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** bird.c
*/

#include "../include/my_hunter.h"

bird_t set_bird(char *c, int x, int y)
{
    bird_t bird;
    sfImage *i_b = sfImage_createFromFile(c);
    bird.t_b = sfTexture_createFromImage(i_b, NULL);
    bird.sp_b = sfSprite_create();
    bird.v_b.x = x;
    bird.v_b.y = y;
    bird.animation.left = 0;
    bird.animation.top = 0;
    bird.animation.height = 32;
    bird.animation.width = 32;
    bird.clock = sfClock_create();
    bird.right_left = 0;
    sfSprite_setTexture(bird.sp_b, bird.t_b, sfTrue);
    sfSprite_setTextureRect(bird.sp_b, bird.animation);
    sfSprite_setPosition(bird.sp_b, bird.v_b);
    return (bird);
}

bird_t animation_left_bird(bird_t bird, sfRenderWindow *window)
{
    bird.animation.top = 0;
    if (sfTime_asSeconds(sfClock_getElapsedTime(bird.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (bird.animation.left == 64)
            bird.animation.left = 0;
        else
            bird.animation.left += 32;
        sfClock_restart(bird.clock);
    }
    sfSprite_setTextureRect(bird.sp_b, bird.animation);
    return (bird);
}

bird_t animation_right_bird(bird_t bird, sfRenderWindow *window)
{
    bird.animation.top = 96;
    if (sfTime_asSeconds(sfClock_getElapsedTime(bird.clock)) >
        sfTime_asSeconds(sfMilliseconds(100))) {
        if (bird.animation.left == 64)
            bird.animation.left = 0;
        else
            bird.animation.left += 32;
        sfClock_restart(bird.clock);
    }
    sfSprite_setTextureRect(bird.sp_b, bird.animation);
    return (bird);
}

bird_t move_bird(bird_t bird, sfRenderWindow *window)
{
    if (bird.right_left == 0) {
        if (bird.v_b.x == -1000) {
            bird.right_left = 1;
            bird.v_b.y = sfTime_asSeconds(sfClock_getElapsedTime(bird.clock)) +
            sfTime_asSeconds(sfClock_getElapsedTime(bird.clock));
        }
        bird.v_b.x -= 5;
        bird = animation_left_bird(bird, window);
    }
    if (bird.right_left == 1) {
        if (bird.v_b.x == 2000) {
            bird.right_left = 0;
            bird.v_b.y = sfTime_asSeconds(sfClock_getElapsedTime(bird.clock));
        }
        bird.v_b.x += 5;
        bird = animation_right_bird(bird, window);
    }
    sfSprite_setPosition(bird.sp_b, bird.v_b);
    sfRenderWindow_drawSprite(window, bird.sp_b, NULL);
    return (bird);
}