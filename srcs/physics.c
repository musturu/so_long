/*
todo
funzione che prende il tempo passato e calcola la strada fatta tramite
accellerazione (car.a) e velocita (car.v)


a is pixels/milliseconds(squared)
v is pixels/milliseconds
pos is pixels
ori is degrees(int)
*/

#include "../so_long.h"

void    phys_update(t_game *g, int time)
{
    static tf_vec2  cumupos;
    t_car   car;


    car = (*g).player;
    if (cumupos.x + cumupos.y >= MIN_MOVE)
    {
        car.pos.x += cumupos.x;
        car.pos.y += cumupos.y;
        cumupos.x = 0;
        cumupos.y = 0;
    }
    if (car.a.x != 0)
        car.a.x /= 15/car.a.x;
    if (car.a.y != 0)
        car.a.x /= 15/car.a.x;
    //change Accelleration direction
    cumupos.x += car.v.x * time + (car.a.x * time * time)/2;
    cumupos.y += car.v.y * time + (car.a.y * time * time)/2;
    car.v.x += car.a.x * time;
    car.v.y += car.v.y * time;
    car.a.x /= 15/car.a.x;
}

t_vec2 get_tile(t_vec2 pixels)
{
    t_vec2 ret;

    ret.x = pixels.x + (TILE_R / 2) / TILE_R;
    ret.y = pixels.y + (TILE_R / 2) / TILE_R;
    return (ret);
}

void    collision(t_game *g)
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
}

void    accel(t_game g, int change)
{

    g.player.a.x += change * cos(g.player.ori);
    g.player.a.y += change * sin(g.player.ori);
    return ;
}

void    turn(t_game g, int change)
{
    g.player.ori += change;
    return ;
}
