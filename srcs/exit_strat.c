#include "../so_long.h"

int quit_free(t_game game, void **free)
{
    free_pp(free);
    free_pp((void *)game.map);
    mlx_destroy_image(game.images.coin.img_ptr, game.win);
    mlx_destroy_image(game.images.wall.img_ptr, game.win);
    mlx_destroy_image(game.images.floor.img_ptr, game.win);
    mlx_destroy_image(game.images.exit[0].img_ptr, game.win);
    mlx_destroy_image(game.images.exit[1].img_ptr, game.win);
    exit(0);
}
