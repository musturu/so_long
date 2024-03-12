/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:04:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/02 18:06:54 by lmoricon         ###   ########.fr       */
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
static int check_content(char **map, int max_x, int max_y);
static void flood_fill(char **map, int max_x, int max_y);
static int check_flags(char **map, int *flags, int x, int y);
static int fill_check(char **map, int max_y);

int validate(int argc, char **argv)
{
    int max_x;
    int i;
    char **map;
    char *ext;
    if (argc != 2)
        return (-1);
    ext = ft_strrchr(argv[1], '.');
    if (ext == NULL)
        return (-1);
    if (ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0)
        return (-1);
    map = ft_split(file_to_str(argv[1]), '\n');
    i = 0;
    if (!map[i])
        return (-1);
    max_x = ft_strlen(map[i]);
    while (map[++i])
    {
        if ((int)ft_strlen(map[i]) != max_x)
            return (-1);
    }
    return (check_content(map, max_x, i - 1));
}

static int check_content(char **map, int max_x, int max_y)
{
    int x;
    int y;
    int flags[3];

    y = -1;
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    while (++y < max_y)
    {
        x = -1;
        while (++x < max_x)
        {
            if (!(check_flags(map, NULL, x, y)))
                return (-1);
            if ((x == 0 || y == 0 || x == max_x - 1 || y == max_y - 1) &&
                map[y][x] != '1')
                return (-3);
            check_flags(map, flags, x, y);
        }
    }
    if (flags[0] == 1 && flags[1] == 1 && flags[2] >= 1)
        return (fill_check(map, max_y));
    return (-3);
}

static int check_flags(char **map, int *flags, int x, int y) {
  char c;

  c = map[y][x];
  if (flags == NULL)
    return (c == '1' || c == 'P' || c == 'E' || c == '0' || c == 'C');
  else {
    if (c == 'E')
      flags[0] += 1;
    if (c == 'P')
      flags[1] += 1;
    if (c == 'C')
      flags[2] += 1;
  }
  return (0);
}

static int fill_check(char **map, int max_y)
{
    char **map_copy;
    int i;
    int p_pos[2];

    i = -1;
    map_copy = ft_calloc((max_y + 1), sizeof(char *));
    if (map_copy == NULL)
        return (0);
    while (map[++i])
        map_copy[i] = ft_strdup(map[i]);
    i--;
    while (!ft_strchr(map_copy[i], 'P'))
        i--;
    p_pos[0] = (ft_strchr(map_copy[i], 'P') - map_copy[i]);
    p_pos[1] = i;
    flood_fill(map_copy, p_pos[0], p_pos[1]);
    i = -1;
    while (++i < max_y)
    {
        if (ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'E'))
            return (-5);
    }
  free_pp((void **)map_copy);
  return (1);
}

static void flood_fill(char **map, int x, int y)
{
  map[y][x] = '1';
  if (map[y + 1][x] != '1')
    flood_fill(map, x, y + 1);
  if (map[y - 1][x] != '1')
    flood_fill(map, x, y - 1);
  if (map[y][x - 1] != '1')
    flood_fill(map, x - 1, y);
  if (map[y][x + 1] != '1')
    flood_fill(map, x + 1, y);
  return;
}
