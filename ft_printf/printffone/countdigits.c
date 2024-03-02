/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:25:25 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:07:26 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countd(unsigned long int num, int base)
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
