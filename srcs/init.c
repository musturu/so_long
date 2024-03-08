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
}
