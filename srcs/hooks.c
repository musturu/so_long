#include "../so_long.h"
#include <stdio.h>

static void    get_ori(t_game *g);

int key_hook_down(int key, t_game *game)
{
    if (key == 65307)
        return (quit_free(*game, NULL, "\n"));
    if (key == 119)
        game->player.isaccel = 1;
    if (key == 97)
        game->player.isturn = -1;
    if (key == 115)
        game->player.isaccel = -1;
    if (key == 100)
        game->player.isturn = 1;
    return (1);
}

int key_hook_up(int key, t_game *game)
{
    if (key == 119)
        game->player.isaccel = 0;
    if (key == 97)
        game->player.isturn = 0;
    if (key == 115)
        game->player.isaccel = 0;
    if (key == 100)
        game->player.isturn = 0;
    return (1);
}

int    update(t_game *g)
{
    long long milli;
    long long diff;

    milli = millitime();
    diff = milli - g->ms;
    if (diff > 15)
    {
        get_ori(g);
        get_ms(g);
        phys_update(g, 1);
        print_player(*g);
    }
    return (1);
}

static void    get_ori(t_game *g)
{
    int ori;

    ori = g->player.ori;
    if (ori >= 360 - 45 || ori < 45)
        g->player.img_index = 0;
    if ((ori >= 360-45-90 && ori <= 360-45-90-90) || (ori >= 45 && ori <= 45+90))
        g->player.img_index = 2;
    if ((ori >= 360-45-90-90 && ori <= 360-45-90-90-90) || (ori >= 45+90 && ori <= 45+90+90))
        g->player.img_index = 4;
    if ((ori >= 360-45-90-90-90 && ori <= 360-45-90-90-90-90) || (ori >= 45+90+90 && ori <= 45+90+90+90))
        g->player.img_index = 6;
}
