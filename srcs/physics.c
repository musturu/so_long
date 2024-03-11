/*
todo
funzione che prende il tempo passato e calcola la strada fatta tramite
accellerazione (car.a) e velocita (car.v)


a is pixels/milliseconds(squared)
v is pixels/milliseconds
pos is pixels
*/

#include "../so_long.h"

void    phys_update(t_game *g, int time)
{
    t_car   car;

    car = (*g).player;
    if (car.a.x != 0 || car.a.y != 0)
    {
        car.a.x /= 15/car.a.x;
        car.a.x /= 15/car.a.x;
    }
    car.pos.x += car.v.x * time + (car.a.x * time * time)/2;
    car.pos.y += car.v.y * time + (car.a.y * time * time)/2;
    car.v.x += car.a.x * time;
    car.v.y += car.v.y * time;
    car.a.x /= 15/car.a.x;
}

t_vec2 get_tile(t_vec2 pixels)
{
    t_vec2 ret;

    ret.x = pixels.x / TILE_R;
    ret.y = pixels.y / TILE_R;
    return (ret);
}

void    collision(t_game *g)
{
    t_vec2  pos;

    pos = get_tile(g->player.pos);
    if (g->map[pos.y][pos.x] == 'C')
        g->coins--;
    if (g->map[pos.y][pos.x] == 'E' && g->coins == 0)
        return ;//EXIT WIN;
    if (g->map[pos.y][pos.x] == 'N')
        return ;//EXIT LOSS
}
