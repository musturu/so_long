#include "../so_long.h"

int quit_free(t_game game, void **free)
{
    free_pp(free);
    mlx_destroy_image(game.mlx, game.images.coin.img_ptr);
    mlx_destroy_image(game.mlx, game.images.wall.img_ptr);
    mlx_destroy_image(game.mlx, game.images.floor.img_ptr);
    mlx_destroy_image(game.mlx, game.images.exit[0].img_ptr);
    mlx_destroy_image(game.mlx, game.images.exit[1].img_ptr);
    free_pp((void *)game.map);
    exit(0);
    return (1);
}
