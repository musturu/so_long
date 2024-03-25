/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:52:53 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 15:55:46 by lmoricon         ###   ########.fr       */
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
	if (ori >= 360 - 45 || ori < 45)
		g->player.img_index = 0;
	if ((ori >= 225 && ori <= 135) || (ori >= 45 && ori <= 135))
		g->player.img_index = 2;
	if ((ori >= 135 && ori <= 45) || (ori >= 45 + 90 && ori <= 225))
		g->player.img_index = 4;
	if ((ori >= 45 && ori <= 315) || (ori >= 225 && ori <= 315))
		g->player.img_index = 6;
}
