/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:04:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:28:29 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	getpower(int count, int basenum)
{
	unsigned long int	i;

	i = 1;
	while (count > 1)
	{
		i *= basenum;
		count--;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long int number, char *base)
{
	int					basen;
	unsigned long int	ipwr;
	char				*ret;
	int					i;

	basen = ft_strlen(base);
	i = 0;
	ipwr = getpower(countd(number, basen), basen);
	ret = ft_calloc(sizeof(char), countd(number, basen));
	while (ipwr != 0)
	{
		ret[i++] = base[(number / ipwr)];
		number %= ipwr;
		ipwr /= basen;
	}
	return (ret);
}
