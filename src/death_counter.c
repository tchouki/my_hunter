/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** death_counter.c
*/

#include "../include/my_hunter.h"

death_counter_t set_death_counter(void)
{
    death_counter_t death;
    death.text = sfText_create();
    death.v_text.x = 10;
    death.v_text.y = 10;
    death.nbr_death = 0;
    death.string = malloc(sizeof(int) * death.nbr_death);
    death.string = my_put_nbr(death.nbr_death);
    sfFont *font = sfFont_createFromFile("font/VCR_OSD_MONO_1.001.ttf");

    sfText_setPosition(death.text, death.v_text);
    sfText_setFont(death.text, font);
    sfText_setString(death.text, death.string);
    return (death);
}

char *my_evil_str(char *str)
{
    int count = 0;
    int i = 0;
    int midcount;
    int inter;

    while (str[count] != '\0') {
        count++;
    }
    midcount = count/2;
    while (count > midcount) {
        inter = str[count-1];
        str[count-1] = str[i];
        str[i] = inter;
        i++;
        count--;
    }
    return (str);
}

char *my_put_nbr(int nbr)
{
    int temp;
    int i = 0;
    char *result = malloc(sizeof(char) * nbr);

    if (nbr == 0) {
        result[i] = '0';
        i++;
    }
    while (nbr > 0) {
        temp = nbr % 10;
        result[i] = temp + 48;
        nbr /= 10;
        i++;
    }
    result[i] = '\0';
    result = my_evil_str(result);
    return (result);
}

death_counter_t increment_death(death_counter_t counter, enemy_t enemy,
    sfRenderWindow *window, boss_t boss)
{
    if (enemy.v_e.x == 1000 || boss.v_e.x == 1000) {
        counter.nbr_death++;
        counter.string = malloc(sizeof(int) * counter.nbr_death + 1);
        counter.string = my_put_nbr(counter.nbr_death);
        sfText_setString(counter.text, counter.string);
    }
    sfRenderWindow_drawText(window, counter.text, NULL);
    return (counter);
}