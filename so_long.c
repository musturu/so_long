/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:58:34 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/05 16:33:34 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_game	g;
	char	*ext;

	game = &g;
	if (argc != 2)
		return (0); //error
	ext = ft_strrchr(argv[1], '.');
	if (ft_strncmp(ext, ".ber", ft_strlen(ext)) == 0)
    {
		initialize(argv[1], game);
		mlx_loop(game -> mlx);
	}
}
