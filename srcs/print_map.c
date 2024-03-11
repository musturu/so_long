#include "../so_long.h"

static void print_tile(t_game g, char c, int x, int y);
static void *get_im(t_game game, char c);

void    print_map(t_game game)
{
    int x;
    int y;

    x = 0;
    while (x < game.max.x)
    {
        y = 0;
        while (y < game.max.y)
        {
            print_tile(game, game.map[y][x], x, y);
            y++;
        }
        x++;
    }
    
}

static void print_tile(t_game g, char c, int x, int y)
{
    mlx_put_image_to_window(g.mlx, g.win, get_im(g, c), x * TILE_R, y * TILE_R);
}

static void *get_im(t_game game, char c)
{
    if (c == '0')
        return (game.images.floor[0]);
    if (c == 'C')
        return (game.images.coin[0]);
    if (c == 'E')
        return (game.images.exit[0]);
    else
        return (game.images.wall[0]);
}
