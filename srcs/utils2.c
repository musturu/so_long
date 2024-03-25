/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <lmoricon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:52:53 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 19:05:23 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_count(t_game g)
{
	char	*str;

	str = ft_itoa(g.steps);
	mlx_string_put(g.mlx, g.win, 64, 64, 0, str);
	free(str);
}

void	get_ori(t_game *g)
{
	int	ori;

	ori = g->player.ori;
	if (ori > 23 && ori <= 68)
		g->player.img_index = 1;
	if ((ori > 68 && ori <= 113))
		g->player.img_index = 2;
	if ((ori > 113 && ori <= 158))
		g->player.img_index = 3;
	if ((ori > 158 && ori <= 203))
		g->player.img_index = 4;
	if ((ori > 203 && ori <= 248))
		g->player.img_index = 5;
	if ((ori > 248 && ori <= 293))
		g->player.img_index = 6;
	if ((ori > 293 && ori <= 338))
		g->player.img_index = 7;
	if (ori > 338 || ori < 23)
		g->player.img_index = 0;
}
