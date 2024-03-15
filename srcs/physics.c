/*
todo
funzione che prende il tempo passato e calcola la strada fatta tramite
accellerazione (g->player.a) e velocita (g->player.v)


a is pixels/milliseconds(squared)
v is pixels/milliseconds
pos is pixels
ori is degrees(int)
*/

#include "../so_long.h"

void    phys_update(t_game *g, int time)
{
    static t_dvec2  cumupos;

    if (cumupos.x + cumupos.y >= MIN_MOVE)
    {
        g->player.pos.x += cumupos.x;
        g->player.pos.y += cumupos.y;
        cumupos.x = 0;
        cumupos.y = 0;
    }
    /*if (g->player.a.x != 0)
        g->player.a.x /= 5/g->player.a.x;
    if (g->player.a.y != 0)
        g->player.a.y /= 5/g->player.a.y;*/

    //change Accelleration direction
    cumupos.x += g->player.v.x * (time + (g->player.a.x * time * time)/2);
    cumupos.y += g->player.v.y * (time + (g->player.a.y * time * time)/2);
    g->player.v.x += g->player.a.x * time;
    g->player.v.y += g->player.a.y * time;
    printf("pos:%i , %i\n", g->player.pos.x, g->player.pos.y);
    printf("ori:%i\n", g->player.ori);
    printf("a:%f , %f\n", g->player.a.x, g->player.a.y);
    printf("v:%f , %f\n", g->player.v.x, g->player.v.y);
}

t_vec2 get_tile(t_vec2 pixels)
{
    t_vec2 ret;

    ret.x = pixels.x / TILE_R;
    ret.y = pixels.y / TILE_R;
    return (ret);
}

int    collision(t_game *g)
{
    t_vec2  pos;

    pos = get_tile(g->player.pos);

    if (g->map[pos.y][pos.x] == 'C')
    {
        g->map[pos.y][pos.x] = '0';
        g->coins--;
    }
    else if (g->map[pos.y][pos.x] == 'E' && g->coins == 0)
    {
        return quit_free(*g, NULL);//EXIT WIN;
    }
    else if (g->map[pos.y][pos.x] == 'N')
    {
        return quit_free(*g, NULL);//EXIT LOSS
    }
    return (0);
}

void    accel(t_game *g, double change)
{
    double rad;

    rad = g->player.ori * 3.14/180;
    g->player.a.x += change * cos(rad);
    g->player.a.y += change * sin(rad);
    return ;
}

void    turn(t_game *g, int change)
{
    g->player.ori = (g->player.ori + change) % 360;
    if (g->player.ori < 0)
    {
        g->player.ori = g->player.ori + 360;
    }
    return ;
}
