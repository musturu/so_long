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
// better collision;
#include "../so_long.h"
#include <math.h>
#include <stdio.h>

static void    turn(t_game *g);
static void    accel(t_game *g);
static void turn_ori(t_game *g, int change);

void    phys_update(t_game *g, int time)
{
    static t_dvec2  cupos;

    turn(g);
    accel(g);
    g->player.a.x = g->player.tforce.x + g->player.eforce.x;
    g->player.a.y = g->player.tforce.y + g->player.eforce.y;
    g->player.v.x += g->player.a.x * time;
    g->player.v.y += g->player.a.y * time;
    cupos.x = (g->player.v.x * time) + cupos.x;
    cupos.y = (g->player.v.y * time) + cupos.y;
    if ((abs((int)cupos.x) + abs((int)cupos.y)) >= MIN_MOVE)
    {
        g->player.pos.x =  g->player.pos.x + cupos.x;
        g->player.pos.y = cupos.y + g->player.pos.y;
        cupos.x = 0;
        cupos.y = 0;
    } 
    collision_check(g);
}

static void    accel(t_game *g)
{
    double rad;

    if (g->player.isaccel != 0)
    {
        rad = g->player.ori * 3.14/180;
        if (g->player.isaccel == 1)
        {
            g->player.eforce.y = AC * sin(rad);
            g->player.eforce.x = AC * cos(rad);
        }
        else
        {
            g->player.eforce.x = DC * cos(rad);
            g->player.eforce.y = DC * sin(rad);
        }
    }
    else
    {
        g->player.eforce.x = -(g->player.v.x)/200;
        g->player.eforce.y = -(g->player.v.y)/200;
        if (abs((int)(g->player.v.x * 1000)) <= 0.2 * 1000)
            g->player.v.x = 0;
        if (abs((int)(g->player.v.y * 1000)) <= 0.2 * 1000)
            g->player.v.y = 0;
    }
}


static void    turn(t_game *g)
{
    double  square;

    square = pow(g->player.v.x, 2) + pow(g->player.v.y, 2);
    turn_ori(g,  sqrt(square / 2) * g->player.isturn);
    if (g->player.isturn == -1)
    {
        g->player.tforce.y = 2 * (-g->player.v.x)/64;
        g->player.tforce.x = 2 * (g->player.v.y)/64;
    }
    else if (g->player.isturn == 1)
    {
        g->player.tforce.y = 2 * (g->player.v.x)/64;
        g->player.tforce.x = 2 * (-g->player.v.y)/64;
    }
    else if (g->player.isturn == 0)
    {
        g->player.tforce.x = 0;
        g->player.tforce.y = 0;
    }
    return ;
}

static void turn_ori(t_game *g, int change)
{
    g->player.ori = (g->player.ori + change) % 360;
    if (g->player.ori < 0)
    {
        g->player.ori += 360;
    }
    printf("%d\n", g->player.ori);
}
