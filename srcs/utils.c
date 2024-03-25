/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:12:32 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:08 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

long long	millitime(void)
{
	struct timeval	time;
	long long		microtime;

	gettimeofday(&time, NULL);
	microtime = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (microtime);
}

void	get_ms(t_game *g)
{
	long long	now;

	now = millitime();
	if (now > g->ms)
		g->ms = now;
}

t_vec2	get_tile(t_game g, t_vec2 pixels)
{
	t_vec2	ret;

	if (pixels.x < 0 || pixels.y < 0)
	{
		ret.x = 0;
		ret.y = 0;
		return (ret);
	}
	ret.x = (pixels.x / TILE_R) % (g.max.x);
	ret.y = (pixels.y / TILE_R) % (g.max.y);
	return (ret);
}

t_vec2	init_vec(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
