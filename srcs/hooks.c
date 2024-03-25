/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <lmoricon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:41:01 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/25 19:06:58 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_animations(t_game *g, int *count);
static void	enemy_move(t_game *g, int *count);

int	key_hook_down(int key, t_game *game)
{
	if (key == 65307)
		return (quit_free(*game, "\n"));
	if (key == 119)
		game->player.isaccel = 1;
	if (key == 97)
		game->player.isturn = -1;
	if (key == 115)
		game->player.isaccel = -1;
	if (key == 100)
		game->player.isturn = 1;
	return (1);
}

int	key_hook_up(int key, t_game *game)
{
	if (key == 119)
		game->player.isaccel = 0;
	if (key == 97)
		game->player.isturn = 0;
	if (key == 115)
		game->player.isaccel = 0;
	if (key == 100)
		game->player.isturn = 0;
	return (1);
}

int	update(t_game *g)
{
	long long	milli;
	long long	diff;
	static int	animcount;
	static int	enemycount;

	milli = millitime();
	diff = milli - g->ms;
	if (diff > 15)
	{
		get_ori(g);
		get_ms(g);
		phys_update(g, 1);
		update_map(*g);
		animcount++;
		enemycount++;
		if (enemycount == 60)
			enemy_move(g, &enemycount);
		if (animcount == 15)
			update_animations(g, &animcount);
	}
	return (1);
}

static void	enemy_move(t_game *g, int *count)
{
	(void)g;
	*count = 0;
}

static void	update_animations(t_game *g, int *count)
{
	static int	flag;

	*count = 0;
	if (g->images.cind == 7)
		flag = 1;
	if (g->images.cind == 0)
		flag = 0;
	if (flag)
		g->images.cind--;
	else
		g->images.cind++;
}
