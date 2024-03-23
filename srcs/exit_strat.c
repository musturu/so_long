#include "../so_long.h"

static void destroy_all(t_game game)
{
    mlx_destroy_image(game.mlx, game.images.coin[0].img_ptr);
    mlx_destroy_image(game.mlx, game.images.wall.img_ptr);
    mlx_destroy_image(game.mlx, game.images.floor.img_ptr);
    mlx_destroy_image(game.mlx, game.images.exit[0].img_ptr);
    mlx_destroy_image(game.mlx, game.images.exit[1].img_ptr);
    mlx_destroy_image(game.mlx, game.images.player[0].img_ptr);
    mlx_destroy_image(game.mlx, game.images.player[2].img_ptr);
    mlx_destroy_image(game.mlx, game.images.player[4].img_ptr);
    mlx_destroy_image(game.mlx, game.images.player[6].img_ptr);
    mlx_destroy_image(game.mlx, game.map_img.img_ptr);
    free_pp((void *)game.map);
    mlx_destroy_window(game.mlx, game.win);
    free(game.mlx);
}

int quit_free(t_game game, char *toprint)
{
    if (game.mlx != NULL)
    {
       destroy_all(game); 
    }
    ft_printf("%s", toprint);
    exit(0);
    return (1);
}

int	free_pp(void **to_free)
{
	int	i;

	i = 0;
    if (*to_free != NULL)
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
	free(to_free);
    }
	return (-1);
}
