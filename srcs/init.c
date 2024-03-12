/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:05:02 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/12 09:09:21 by lmoricon         ###   ########.fr       */
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
  g->map_img = new_img(g->max.x * TILE_R, i * TILE_R, g->mlx);
}

static void get_images(t_game *g)
{
    g->images.wall = new_file_img(PATH_TO_WALL, g->mlx);
    g->images.floor = new_file_img(PATH_TO_FLOOR, g->mlx);
    g->images.exit[0] = new_file_img(PATH_TO_EXIT, g->mlx);
    g->images.coin = new_file_img(PATH_TO_COIN, g->mlx);
}
