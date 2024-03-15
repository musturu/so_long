#include "../so_long.h"

static void    get_ori(t_game *g);

int key_hook(int key, t_game *game)
{
    if (key == 65307)
        return (quit_free(*game, NULL));
    if (key == 119)
        accel(game, AC);
    if (key == 97)
        turn(game, TURN_SPEED);
    if (key == 115)
        accel(game, DC);
    if (key == 100)
        turn(game, - TURN_SPEED);
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
    if ((ori + 359 % 360) >= 360-45 && ori < 45)
        g->player.img_index = 0;
    if ((ori + 359 % 360) >= 360-45-90 && g->player.ori < 90 + 45)
        g->player.img_index = 2;
    if ((ori + 359 % 360) >= 360-45-90-90 && g->player.ori < 90 + 90 + 45)
        g->player.img_index = 4;
    if ((ori + 359 % 360) >= 360-45-90-90-90 && g->player.ori < 90 + 90 + 90 + 45)
        g->player.img_index = 6;
}
