/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** game.c
*/

#include "../include/my_hunter.h"

game_t set_main(void)
{
    game_t game;

    game.video_mode.width = 1280;
    game.video_mode.height = 720;
    game.video_mode.bitsPerPixel = 32;
    game.scene0 = set_menu();
    game.scene1 = set_game();
    game.scene2 = set_help();
    game.scene3 = set_gameover();
    game.scene4 = set_pause_menu();
    game.map_background = set_background("menu/map.png");
    game.menu_background = set_background("menu/background_menu.png");
    game.help_background = set_background("menu/background_help.png");
    game.gameover_background = set_background("menu/background_over.png");
    game.music = sfMusic_createFromFile("music/Nocturnal Mysteries.ogg");
    sfMusic_play(game.music);
    game.s = 0;
    game.window = sfRenderWindow_create(game.video_mode, "MyHunter",
        sfDefaultStyle, NULL);
    return (game);
}

game_t play_scene2(game_t game)
{
    if (game.s == 2) {
        sfWindow_setMouseCursorVisible(game.window, sfTrue);
        sfRenderWindow_drawSprite(game.window,
            game.help_background.sp_background, NULL);
        game.scene2 = play_help(game.scene2, game.window);
        game.s = back_menu(game.scene2, game.window, game.s);
    }
    return (game);
}

game_t play_scene1(game_t game)
{
    if (game.s == 1) {
        sfWindow_setMouseCursorVisible(game.window, sfFalse);
        sfRenderWindow_drawSprite(game.window,
            game.map_background.sp_background, NULL);
        game.scene1 = play_game(game.scene1, game.window);
        game.s = swap_gameover(game.scene1.heart_bar, game.s);
    }
    return (game);
}

game_t play_scene0(game_t game)
{
    if (game.s == 0) {
        sfWindow_setMouseCursorVisible(game.window, sfTrue);
        sfRenderWindow_drawSprite(game.window,
            game.menu_background.sp_background, NULL);
        game.scene0 = play_menu(game.scene0, game.window);
        game.s = swap_scene(game.scene0, game.window, game.s);
        game.scene1.heart_bar.animation.width = 300;
        game.scene1.death_counter.nbr_death = 0;
        game.scene1.heart_bar.gameover = 0;
        game.scene1.death_counter.string = "0";
        sfText_setString(game.scene1.death_counter.text,
            game.scene1.death_counter.string);
        game.scene1.character.v_c.x = 50;
    }
    return (game);
}