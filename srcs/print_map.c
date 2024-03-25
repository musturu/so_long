/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <lmoricon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:01 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 19:33:13 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_image	get_im(t_game game, char c);
static t_vec2	pos_image(char c, t_vec2 pxp);

void	update_map(t_game g)
{
	int		x;
	int		y;
	t_vec2	pos;

	x = 0;
	y = 0;
	while (x < g.max.x)
	{
		y = 0;
		while (y < g.max.y)
		{
			put_img_to_img(g.map_img, g.images.floor, x * TILE_R, y * TILE_R);
			pos = init_vec(x, y);
			pos = pos_image(g.map[y][x], pos);
			put_img_to_img(g.map_img, get_im(g, g.map[y][x]), pos.x, pos.y);
			y++;
		}
		x++;
	}
	put_img_to_img(g.map_img, g.images.player[g.player.img_index],
		g.player.pos.x, g.player.pos.y);
	mlx_put_image_to_window(g.mlx, g.win, g.map_img.img_ptr, 0, 0);
	put_count(g);
}

void	print_map(t_game g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < g.max.x)
	{
		y = 0;
		while (y < g.max.y)
		{
			put_img_to_img(g.map_img, g.images.floor, x * TILE_R, y * TILE_R);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(g.mlx, g.win, g.map_img.img_ptr, 0, 0);
}

static t_image	get_im(t_game game, char c)
{
	if (c == '1')
		return (game.images.wall);
	if (c == 'C')
		return (game.images.coin[game.images.cind]);
	if (c == 'E')
		return (game.images.exit[game.images.eind]);
	if (c == 'N')
		return (game.images.exit[1]);
	else
		return (game.images.floor);
}

static t_vec2	pos_image(char c, t_vec2 pxp)
{
	if (c == '1' || c == '0' || c == 'P')
		return (init_vec((pxp.x * TILE_R), (pxp.y * TILE_R)));
	else
		return (init_vec((pxp.x * TILE_R) + 32, (pxp.y * TILE_R) + 32));
}
