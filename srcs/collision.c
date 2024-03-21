

#include "../so_long.h"

static int    cen_collision(t_game *g);
static char    check_indir(t_game g, t_vec2 dir);

void    collision_check(t_game *g)
{
    t_vec2 dir;

    dir = init_vec(dir, 0, 1);
    if (check_indir(*g, dir) == '1')
    {
        (*g).player.pos.y -= 32;
        g->player.v.y *= -0.7;
    }
    dir = init_vec(dir, 0, -1);
    if (check_indir(*g, dir) == '1')
    {
        g->player.pos.y += 32;
        g->player.v.y *= -0.7;
    }
    dir = init_vec(dir, 1, 0);
    if (check_indir(*g, dir) == '1')
    {
        g->player.pos.x -= 32;
        g->player.v.x *= -0.7;
    }
    dir = init_vec(dir, -1, 0);
    if (check_indir(*g, dir) == '1')
    {
        g->player.pos.x += 32;
        g->player.v.x *= -0.7;
    }
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


/*static int    collision(t_game *g)
{
    t_vec2  pos;
    t_vec2  pixelpos;
    t_vec2  next_pos;

    pixelpos = g->player.pos;
    pixelpos.x += (TILE_R / 2);
    pixelpos.y += (TILE_R / 2);
    next_pos = pixelpos;
    next_pos.x += (int)(g->player.v.x * 5);
    next_pos.y += (int)(g->player.v.y * 5);
    pos = get_tile(*g, pixelpos);
    next_pos = get_tile(*g, next_pos);
    if (g->map[next_pos.y][next_pos.x] == '1')
    {
        g->player.v.x *= -0.8;
        g->player.v.y *= -0.8;
        g->player.a.x = 0;
        g->player.a.y = 0;
    }
    if (g->map[pos.y][pos.x] == 'C')
    {
        g->map[pos.y][pos.x] = '0';
        g->coins--;
    }
    else if (g->map[pos.y][pos.x] == 'E' && g->coins == 0)
        return quit_free(*g, NULL);//EXIT WIN;
    else if (g->map[pos.y][pos.x] == 'N')
        return quit_free(*g, NULL);//EXIT LOSS
    return (0);
}*/