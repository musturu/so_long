#include "../so_long.h"

static void    update_animations(t_game *g);

int key_hook_down(int key, t_game *game)
{
    if (key == 65307)
        return (quit_free(*game, "\n"));
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
    static int animcount;

    milli = millitime();
    diff = milli - g->ms;
    if (diff > 15)
    {
        get_ori(g);
        get_ms(g);
        phys_update(g, 1);
        update_map(*g);
        animcount++;
        if (animcount == 15)
        {
            update_animations(g);
            put_count(*g);
            animcount = 0;
        }
    }
    return (1);
}

static void    update_animations(t_game *g)
{
    static int  flag;
    if (g->images.cind == 7)
        flag = 1;
    if (g->images.cind == 0)
        flag = 0;
    if (flag)
        g->images.cind--;
    else
        g->images.cind++;
}
