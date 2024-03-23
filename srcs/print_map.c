#include "../so_long.h"

static t_image get_im(t_game game, char c);
static t_vec2 pos_image(char c, t_vec2 pxp);

void    update_map(t_game game)
{
    int     x;
    int     y;
    t_vec2  pos;

    x = 0;
    y = 0;
    while (x < game.max.x)
    {
        y = 0;
        while (y < game.max.y)
        {
            put_img_to_img(game.map_img, game.images.floor, x * TILE_R, y * TILE_R);
            pos = init_vec(pos, x, y);
            pos = pos_image(game.map[y][x], pos);
            put_img_to_img(game.map_img, get_im(game, game.map[y][x]), pos.x, pos.y);
            y++;
        }
        x++;
    }
    put_img_to_img(game.map_img, game.images.player[game.player.img_index],
        game.player.pos.x, game.player.pos.y);
    mlx_put_image_to_window(game.mlx, game.win, game.map_img.img_ptr, 0, 0);
}

void    print_map(t_game game)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (x < game.max.x)
    {
        y = 0;
        while (y < game.max.y)
        {
            put_img_to_img(game.map_img, game.images.floor, x * TILE_R, y * TILE_R);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(game.mlx, game.win, game.map_img.img_ptr, 0, 0);
}

void    print_player(t_game g)
{
    t_vec2 p;
    int x;
    int y;
    t_vec2 pxp;
    t_vec2 printp;

    x = -2;
    p = g.player.pos;
    while(x <= 2)
    {
        y = -2;
        while (y <= 2)
        {
            pxp.x = p.x + (x * TILE_R);
            pxp.y = p.y + (y * TILE_R);
            pxp = get_tile(g, pxp);
            put_img_to_img(g.map_img, g.images.floor, pxp.x * TILE_R, pxp.y * TILE_R);
            printp = pos_image(g.map[pxp.y][pxp.x], printp);
            put_img_to_img(g.map_img, get_im(g, g.map[pxp.y][pxp.x]),
                printp.x, printp.y);
            y++;
        }
        x++;
    }
    put_img_to_img(g.map_img, g.images.player[g.player.img_index],
        g.player.pos.x, g.player.pos.y);
    mlx_put_image_to_window(g.mlx, g.win, g.map_img.img_ptr, 0, 0);
}

static t_image get_im(t_game game, char c)
{
    if (c == '1')
        return (game.images.wall);
    if (c == 'C')
        return (game.images.coin[game.images.cind]);
    if (c == 'E')
        return (game.images.exit[game.images.eind]);
    else
        return (game.images.floor);
}

static t_vec2 pos_image(char c, t_vec2 pxp)
{
    if (c == '1' || c == '0' || c == 'P')
        return (init_vec(pxp, (pxp.x * TILE_R), (pxp.y * TILE_R)));
    else
        return (init_vec(pxp, (pxp.x * TILE_R) + 32, (pxp.y * TILE_R) + 32));
    
}

