/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** game2.c
*/

#include "../include/my_hunter.h"

game_t play_scene4(game_t game)
{
    if (game.s == 4) {
        sfWindow_setMouseCursorVisible(game.window, sfTrue);
        sfRenderWindow_drawSprite(game.window,
            game.menu_background.sp_background, NULL);
        game.scene4 = play_pause(game.scene4, game.window);
        game.s = back_pause_menu(game.scene4, game.window, game.s);
    }
    return (game);
}

game_t play_scene3(game_t game)
{
    if (game.s == 3) {
        sfWindow_setMouseCursorVisible(game.window, sfTrue);
        sfRenderWindow_drawSprite(game.window,
            game.gameover_background.sp_background, NULL);
        game.scene3 = play_gameover(game.scene3, game.window, game.scene1);
        game.s = back_menu_gameover(game.scene3, game.window, game.s);
    }
    return (game);
}