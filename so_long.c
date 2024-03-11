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
#include "libs/ft_printf/printffone/ft_printf.h"

int main(int argc, char **argv)
{
    t_game g;

   if (validate(argc, argv) != 1)
        return (ft_printf("Fai il serio\n"));
    initialize(argv[1], &g);
    mlx_loop(g.mlx);
}
