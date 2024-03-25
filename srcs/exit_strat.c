/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_strat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <lmoricon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:02:35 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 17:50:58 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	destroy_all(t_game game)
{
	mlx_destroy_image(game.mlx, game.images.coin[0].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[1].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[2].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[3].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[4].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[5].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[6].img_ptr);
	mlx_destroy_image(game.mlx, game.images.coin[7].img_ptr);
	mlx_destroy_image(game.mlx, game.images.wall.img_ptr);
	mlx_destroy_image(game.mlx, game.images.floor.img_ptr);
	mlx_destroy_image(game.mlx, game.images.exit[0].img_ptr);
	mlx_destroy_image(game.mlx, game.images.exit[1].img_ptr);
	mlx_destroy_image(game.mlx, game.images.player[0].img_ptr);
	mlx_destroy_image(game.mlx, game.images.player[2].img_ptr);
	mlx_destroy_image(game.mlx, game.images.player[4].img_ptr);
	mlx_destroy_image(game.mlx, game.images.player[6].img_ptr);
	mlx_destroy_image(game.mlx, game.map_img.img_ptr);
	free_pp(game.map);
	mlx_destroy_window(game.mlx, game.win);
	free(game.mlx);

}

int	quit_free(t_game game, char *toprint)
{
	if (game.mlx != NULL)
	{
		destroy_all(game);
	}
	ft_printf("%s", toprint);
	exit(0);
	return (1);
}

int	free_pp(char **to_free)
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
