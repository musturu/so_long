/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ptrnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:14:10 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 17:05:31 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_prec(t_format fmt)
{
	int	i;

	i = 0;
	if (fmt.pflag && fmt.precision > 8)
		i = fmt.precision;
	else if (fmt.pflag)
		i = 2;
	return (i);
}

int	init_p(t_format fmt, char *str, int len, unsigned long int num)
{
	int		i;
	char	pad;
	int		startindex;
	int		base;
	int		prec;

	prec = get_prec(fmt);
	base = 16;
	i = 2;
	pad = ' ';
	ft_memset(str, pad, len);
	if (ft_strchr(fmt.flags, '-') && fmt.precision <= countd(num, base))
		startindex = i + prec;
	if (ft_strchr(fmt.flags, '-') && fmt.precision > countd(num, base))
		startindex = i + prec - countd(num, base);
	else if (!ft_strchr(fmt.flags, '-'))
	{
		if (fmt.precision > countd(num, base) + i)
			startindex = len - (countd(num, base) + prec);
		else
			startindex = len - (countd(num, base));
	}
	ft_memset((str + i), '0', fmt.precision);
	return (startindex);
}

static void	mal_p(t_format fmt, unsigned long int str, int *icount)
{
	char	*ret;
	int		count;
	int		len;
	int		startind;

	count = countd(str, 16) + 2;
	if (fmt.precision >= fmt.width && fmt.precision >= count)
		len = fmt.precision + 2;
	else if (fmt.width > count && fmt.width > fmt.precision)
		len = fmt.width;
	else
		len = count;
	ret = ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return ;
	startind = init_p(fmt, ret, len, str);
	write_num(fmt, startind, str, ret);
	put_sign("0x", 2, ret);
	ft_putstr_count(ret, icount, len);
	free(ret);
}

void	str_ptrnum(t_format fmt, void *ptr, int *count)
{
	unsigned long int	num;

	if (ptr == NULL)
		num = 0;
	else
		num = (unsigned long int)ptr;
	mal_p(fmt, num, count);
}
