#include "../so_long.h"

static t_image get_im(t_game game, char c);

void    print_map(t_game game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < game.max.x)
    {
        y = 0;
        while (y < game.max.y)
        {
            put_img_to_img(game.map_img, game.images.floor, x * TILE_R, y * TILE_R);
            put_img_to_img(game.map_img, get_im(game, game.map[y][x]), x * TILE_R, y * TILE_R);
            y++;
        }
        x++;
    }
   mlx_put_image_to_window(game.mlx, game.win, game.map_img.img_ptr, 0, 0);
}

static t_image get_im(t_game game, char c)
{
    if (c == '0' || c == 'P')
        return (game.images.floor);
    if (c == 'C')
        return (game.images.coin);
    if (c == 'E')
        return (game.images.exit[0]);
    else
        return (game.images.wall);
}

