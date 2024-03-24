

#include "../so_long.h"

static int    cen_collision(t_game *g);
static char    check_indir(t_game g, t_vec2 dir);
static void    effect(t_game *g, t_vec2 dir);

void    collision_check(t_game *g)
{
    t_vec2 dir;

    dir = init_vec(0, 1);
    effect(g, dir);
    dir = init_vec(0, -1);
    effect(g, dir);
    dir = init_vec(1, 0);
    effect(g, dir);
    dir = init_vec(-1, 0);
    effect(g, dir);
    cen_collision(g);
}

static int    cen_collision(t_game *g)
{
    t_vec2 pos;

    pos = g->player.pos;
    pos.x += (TILE_R / 2);
    pos.y += (TILE_R / 2);
    pos = get_tile(*g, pos);
    if (g->map[pos.y][pos.x] == 'C')
    {
        g->map[pos.y][pos.x] = '0';
        g->coins--;
        if (g->coins == 0)
            g->images.eind = 1;
    }
    else if (g->map[pos.y][pos.x] == 'E' && g->coins == 0)
        return quit_free(*g, "HAI VINTO\n");//EXIT WIN;
    else if (g->map[pos.y][pos.x] == 'N')
        return quit_free(*g, "HAI PERSO\n");//EXIT LOSS
    return (1);
}

static char    check_indir(t_game g, t_vec2 dir)
{
    t_vec2  to_check;

    to_check = g.player.pos;
    to_check.x += (TILE_R / 2) + ((TILE_R / 2) * dir.x);
    to_check.y += (TILE_R / 2) + ((TILE_R / 2) * dir.y);
    to_check = get_tile(g, to_check);
    return (g.map[to_check.y][to_check.x]);
}

static void    effect(t_game *g, t_vec2 dir)
{
    if (check_indir(*g, dir) == '1')
    {
        g->player.pos.y += (-5 * dir.y);
        g->player.pos.x += (-5 * dir.x);
        g->player.v.x *= (-0.5 * dir.x * dir.x);
        g->player.v.y *= (-0.5 * dir.y * dir.y);
    }
}
