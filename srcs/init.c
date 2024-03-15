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
static void get_content(t_game *g, int max_x, int max_y);
static void init_player(t_game *g);

void initialize(char *path, t_game *g)
{
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
  get_content(g, g->max.x, g->max.y);
  init_player(g);
}

static void get_images(t_game *g)
{
    g->images.wall = new_file_img(PATH_TO_WALL, g->mlx);
    g->images.floor = new_file_img(PATH_TO_FLOOR, g->mlx);
    g->images.coin = new_file_img(PATH_TO_COIN, g->mlx);
    g->images.exit[0] = new_file_img(PATH_TO_EXIT, g->mlx);
    g->images.exit[1] = new_file_img("textures/exit2.xpm", g->mlx);
    g->images.player[0] = new_file_img("textures/player0.xpm", g->mlx);
    //g->images.player[1] = new_file_img("textures/player1.xpm", g->mlx);
    g->images.player[2] = new_file_img("textures/player2.xpm", g->mlx);
    //g->images.player[3] = new_file_img("textures/player3.xpm", g->mlx);
    g->images.player[4] = new_file_img("textures/player4.xpm", g->mlx);
    //g->images.player[5] = new_file_img("textures/player5.xpm", g->mlx);
    g->images.player[6] = new_file_img("textures/player6.xpm", g->mlx);
    //g->images.player[7] = new_file_img("textures/player7.xpm", g->mlx);
}

static void get_content(t_game *g, int max_x, int max_y)
{
  int x;
  int y;
  int coins;
  t_vec2 player_pos;

  x = -1;
  coins = 0;
  while (++x < max_x)
  {
    y = -1;
    while (++y < max_y)
    {
      if (g->map[y][x] == 'C')
        coins++;
      if (g->map[y][x] == 'P')
      {
        player_pos.x = x * TILE_R;
        player_pos.y = y * TILE_R;
      }
    }
  }
  g->player.pos = player_pos;
  g->coins = coins;
}

static void init_player(t_game *g)
{
  g->player.a.x = 0;
  g->player.a.y = 0;
  g->player.v.x = 0;
  g->player.v.y = 0;
  g->player.ori = 0;
  g->player.img_index = 0;
  g->ms = 0;
}
