#include "../so_long.h"

int quit_free(t_game game, char *toprint)
{
    if (game.mlx != NULL)
    {
        mlx_destroy_image(game.mlx, game.images.coin.img_ptr);
        mlx_destroy_image(game.mlx, game.images.wall.img_ptr);
        mlx_destroy_image(game.mlx, game.images.floor.img_ptr);
        mlx_destroy_image(game.mlx, game.images.exit[0].img_ptr);
        mlx_destroy_image(game.mlx, game.images.exit[1].img_ptr);
        free_pp((void *)game.map);
    }
    ft_printf("%s", toprint);
    exit(0);
    return (1);
}
