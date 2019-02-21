/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main.c
*/

#include "../include/my_hunter.h"

void event(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfEvent e;
    while (sfRenderWindow_pollEvent(window, &e)) {
        pos = sfMouse_getPositionRenderWindow(window);
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int my_window(int helper)
{
    game_t game = set_main();
    sfRenderWindow_setFramerateLimit(game.window, 60);
    if (helper == 1)
        game.s = 2;
    while (sfRenderWindow_isOpen(game.window)) {
        sfMusic_setLoop(game.music, sfTrue);
        event(game.window);
        game = play_scene4(game);
        game = play_scene3(game);
        game = play_scene2(game);
        game = play_scene1(game);
        game = play_scene0(game);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game.s == 1)
            game.s = 4;
        sfRenderWindow_display(game.window);
    }
    sfMusic_destroy(game.music);
    sfRenderWindow_destroy(game.window);
    return (0);
}

int main(int argc, char **argv)
{
    int helper = 0;

    if (argv[1] != NULL) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            helper = 1;
    }
    my_window(helper);
    return (0);
}