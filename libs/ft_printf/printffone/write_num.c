/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:44:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 17:06:39 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_num(t_format fmt, int index, unsigned long int number, char *dest)
{
	char	*ito;
	char	*base;
	char	c;

	c = fmt.conversion;
	base = "0123456789";
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ito = ft_itoa_base(number, base);
	ft_memcpy(dest + index, ito, ft_strlen(ito));
	free(ito);
}
