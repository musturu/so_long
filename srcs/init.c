/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:05:02 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:28 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void get_images(t_game *g);

void initialize(char *path, t_game *g) {
  int i;

  i = 0;
  g->map = ft_split(file_to_str(path), '\n');
  g->max.x = ft_strlen(g->map[0]);
  while (g->map[i])
    i++;
  g->max.y = i;
  g->mlx = mlx_init();
  g->win = mlx_new_window(g->mlx, g->max.x * TILE_R, i * TILE_R, "so_long");
  get_images(g);
}

static void get_images(t_game *g)
{
    int res;

    res = TILE_R;
  g->images.wall[0] = mlx_xpm_file_to_image((*g).mlx, PATH_TO_WALL, &res, &res);
  g->images.floor[0] = mlx_xpm_file_to_image((*g).mlx, PATH_TO_FLOOR, &res, &res);
  g->images.exit[0] = mlx_xpm_file_to_image((*g).mlx, PATH_TO_EXIT, &res, &res);
  g->images.coin[0] = mlx_xpm_file_to_image((*g).mlx, PATH_TO_COIN, &res, &res);
}
