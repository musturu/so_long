/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:06:09 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:06:58 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countdig(long int num, int base)
{
	int	count;

	count = 1;
	while (num / base != 0)
	{
		count++;
		num = num / base;
	}
	return (count);
}
