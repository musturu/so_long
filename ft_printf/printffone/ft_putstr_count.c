/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:25:54 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:21:57 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(char *str, int *count, int len)
{
	int	i;

	i = 0;
	while (i != len)
	{
		ft_putchar_count(str[i], count);
		i++;
	}
}
