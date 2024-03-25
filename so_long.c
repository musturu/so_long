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

int main(int argc, char **argv)
{
    t_game  g;

    g.mlx = NULL;
    if (validate(argc, argv) != 1)
        return (quit_free(g, "Error\nFai il serio\n"));
    initialize(argv[1], &g);
    mlx_hook(g.win, 3, 1L<<1, key_hook_up, &g);
    mlx_hook(g.win, 2, 1L<<0, key_hook_down, &g);
    mlx_loop_hook(g.mlx, update, &g);
    mlx_loop(g.mlx);
}
