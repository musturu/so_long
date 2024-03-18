/*
todo
funzione che prende il tempo passato e calcola la strada fatta tramite
accellerazione (g->player.a) e velocita (g->player.v)


a is pixels/milliseconds(squared)
v is pixels/milliseconds
pos is pixels
ori is degrees(int)
*/

//todo: rivedere fisica e attrito. funziona male il turning 

#include "../so_long.h"
#include <stdlib.h>

static int    collision(t_game *g);

void    phys_update(t_game *g, int time)
{
    static t_dvec2  cupos;

    turn(g, time);
    accel(g);
    if ((abs((int)cupos.x) + abs((int)cupos.y)) >= MIN_MOVE)
    {
        g->player.pos.x =  g->player.pos.x + cupos.x;
        g->player.pos.y = cupos.y + g->player.pos.y;
        cupos.x = 0;
        cupos.y = 0;
    }
    //change Accelleration direction
    g->player.v.x = (g->player.a.x * time) + g->player.v.x;
    g->player.v.y = (g->player.a.y * time) + g->player.v.y;
    cupos.x = (g->player.v.x * time) + cupos.x;
    cupos.y = (g->player.v.y * time) + cupos.y;
    collision(g);
    // printf("pos:%i , %i\n", g->player.pos.x, g->player.pos.y);
    // printf("ori:%i\n", g->player.ori);
    // printf("a:%f , %f\n", g->player.a.x, g->player.a.y);
    // printf("v:%f , %f\n", g->player.v.x, g->player.v.y);
}

static int    collision(t_game *g)
{
    t_vec2  pos;
    t_vec2  pixelpos;
    t_vec2  next_pos;

    pixelpos = g->player.pos;
    pixelpos.x += (TILE_R / 2);
    pixelpos.y += (TILE_R / 2);
    next_pos = pixelpos;
    next_pos.x += (int)(g->player.v.x * 15);
    next_pos.y += (int)(g->player.v.x * 15);
    pos = get_tile(*g, pixelpos);
    next_pos = get_tile(*g, next_pos);
    if (g->map[next_pos.y][next_pos.x] == '1')
    {
        g->player.v.x *= 0;
        g->player.v.y *= 0;
        g->player.a.x *= -0.7;
        g->player.a.y *= -0.7;
    }

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

void    accel(t_game *g)
{
    double rad;
    if (g->player.isaccel != 0)
    {
        rad = g->player.ori * 3.14/180;
        g->player.a.x += g->player.isaccel * AC * cos(rad);
        g->player.a.y += g->player.isaccel * AC * sin(rad);
    }
    else
    {
        g->player.a.x -= g->player.v.x * FRICTION;
        g->player.a.x -= g->player.v.x * FRICTION;
        if (abs((int)(g->player.v.x * 1000)) <= 0.2 * 1000)
            g->player.v.x = 0;
        if (abs((int)(g->player.v.y * 1000)) <= 0.2 * 1000)
            g->player.v.y = 0;
    }
}

void    turn(t_game *g, int change)
{
    if (g->player.isturn != 0)
    {
        g->player.ori = (g->player.ori + change) % 360;
        if (g->player.ori < 0)
        {
            g->player.ori = g->player.ori + 360;
        }
    }
}
