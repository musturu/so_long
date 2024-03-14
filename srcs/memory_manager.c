/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:01:35 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/02 16:52:20 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_pp(void **to_free)
{
	int	i;

	i = 0;
    if (!to_free)
        return  ;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
