/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:58:34 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/02 17:26:53 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char **map;

	if (argc != 2)
		return (0); //error
	map = ft_split(file_to_str(argv[1]), '\n');
	int i = -1;
	while (map[++i])
		ft_printf("%s\n", map[i]);
	ft_printf("validation:%d\n", validate(map));
}
