/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:04:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:22 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	input: split del file .ber
 *	controllo dei caratteri, devono essere solo 1/0/E/P/C
 *	flag per P (player) ed E(exit), almeno 1 C
 *	deve essere circondata da muri(1)
 *	Deve esserci un path che parte da P ed arrivi ad E (flood_fill)
 *	per ogni errore deve returnare "Error/n[ERROREASCELTA]"
 * */
static int	check_content(char **map, int max_x, int max_y);
static int	is_allowed(char c);
static void	flood_fill(char **map, int max_x, int max_y);



int	validate(char **map)
{
	int	max_x;
	int max_y;
	int	i;

	i = 0;
	max_x = ft_strlen(map[i]);
	while(map[++i])
	{
		if (ft_strlen(map[i]) != max_x)
			return (-1);
	}
	max_y = i;
	return (check_content(map, max_x, max_y));
}

static int check_content(char **map, int max_x, int max_y)
{
	int x;
	int y;
	int flags[3];
	
	x = -1;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (++x < max_x)
	{
		y = -1;
		while (++y < max_y)
		{
			if (!is_allowed(map[x][y]))
				return (-1);
			if ((x == 0 || y == 0 || x == max_x || y == max_y) && map[x][y] != '1')
				return (-2);
			if (map[x][y] == 'E')
				flags[0] = 1;
			if (map[x][y] == 'P')
				flags[1] += 1;
			if (map[x][y] == 'C')
				flags[2] += 1;
		}
	}
	if (flags[0] == 1 && flags[1] == 1 && flags[2] >= 1)
		return (fill_check(map, max_x, max_y));
	return (-3);
}

static int	is_allowed(char c)
{
	return (c == '1' || c == 'P' || c == 'E' || c == '0' || c == 'C');
}

static int fill_check(char **map, int max_x, int max_y)
{
	char	**map_copy;
	int		i;
	int		p_pos[2];

	i = 0;
	map_copy = ft_calloc((max_y + 1), sizeof(char *));
	while(map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	while(!ft_strchr(map_copy[i], 'P')
			i--;
	p_pos[0] = map_copy[i] - ft_strchr(map_copy[i], 'P');
	p_pos[1] = i;
	i = 0;
	i = (flood_fill(copy_map, p_pos[0], p_pos[1], &i);
	//free copia map
	return (i);
}

static int	flood_fill(char **map, int x, int y, int *ret)
{
	if (map[x][y] == 'E')
		*ret = 1;
	if (*ret == 1)
		return (1);
	map[x][y] = '1';
	if (map[x + 1][y] != '1')
		 flood_fill(map, x + 1, y, ret);
	if (map[x - 1][y] != '1')
		 flood_fill(map, x - 1, y, ret);
	if (map[x][y - 1] != '1')
		 flood_fill(map, x, y - 1, ret);
	if (map[x][y + 1] != '1')
		 flood_fill(map, x, y + 1, ret);
	return (0);
}
