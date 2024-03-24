#include "../so_long.h"

void    put_count(t_game g)
{
    char *str;

    str = ft_itoa(g.steps);
    mlx_string_put(g.mlx, g.win, 64, 64, 0, str);
    free(str);
}

void    get_ori(t_game *g)
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
