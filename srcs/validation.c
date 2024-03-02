/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:04:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/27 16:06:31 by lmoricon         ###   ########.fr       */
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
	int pflag;
	int eflag;
	int	ccount;
	
	x = -1;
	pflag = 0;
	eflag = 0;
	ccount = 0;
	while (++x < max_x)
	{
		y = -1;
		while (++y < max_y)
		{
			if (!is_allowed(map[x][y]))
				return (-1);
			if ((x == 0 || y == 0 || x == max_x || y == max_y) && map[x][y] != '1')
				return (-2); //controlla che il perimetro sia fatto da '1'i
			if (map[x][y] == 'E')
				eflag = 1;
			if (map[x][y] == 'P')
				pflag += 1;
			if (map[x][y] == 'C')
				ccount += 1;
		}
	}
	if (pflag == 1 && ccount >= 1 && eflag == 1)
		return (fill_check(map, max_x, max_y));
	else
		return (-3);
}

static int	is_allowed(char c)
{
	return (c == '1' || c == 'P' || c == 'E' || c == '0' || c == 'C');
}

static int fill_check(char **map, int max_x, int max_y)
{
	//todo: copiare map
	//trovare P ed E
	// fare flood_fill sulla copia con x e y posizioni di 'P' 
	// controllare che dove prima c-era E adesso ci sia 1
	//free copia map
	//return 1
}

/*
flood_fill di merda, da chiamare con x e y posizioni di P, chiama se stessa se la cella vicina != 1
in questo modo dopo che ha finito controllo la vecchia posizione di E, se adesso == 1 allora la mappa
dovrebbe essere giocabile.
*/
static void	flood_fill(char **map, int x, int y)
{
	map[x][y] = '1';
	if (map[x + 1][y] != '1')
		 flood_fill(map, x + 1, y);
	if (map[x - 1][y] != '1')
		 flood_fill(map, x - 1, y);
	if (map[x][y - 1] != '1')
		 flood_fill(map, x, y - 1);
	if (map[x][y + 1] != '1')
		 flood_fill(map, x, y + 1);
}
