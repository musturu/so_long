/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:42:36 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 17:01:25 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_x(t_format fmt, char *str, int len, unsigned int num)
{
	int		i;
	char	pad;
	int		startindex;
	int		base;

	base = get_base(fmt);
	i = need_space(num, fmt);
	pad = needed_pad(fmt);
	ft_memset(str, pad, len);
	if (ft_strchr(fmt.flags, '-') && fmt.precision <= countd(num, base))
		startindex = need_space(num, fmt);
	if (ft_strchr(fmt.flags, '-') && fmt.precision > countd(num, base))
		startindex = i + fmt.precision - countd(num, base);
	else if (!ft_strchr(fmt.flags, '-'))
	{
		if (fmt.precision > countd(num, base) + i)
			startindex = len - (countd(num, base));
		else
			startindex = len - (countd(num, base));
	}
	ft_memset((str + i), '0', fmt.precision);
	return (startindex);
}

static void	mal_x(t_format fmt, unsigned int str, int *icount)
{
	char	*ret;
	int		count;
	int		len;
	int		startind;

	count = countd(str, 16) + need_space(str, fmt);
	if (fmt.precision >= fmt.width && fmt.precision >= count)
		len = fmt.precision + need_space(str, fmt);
	else if (fmt.width > count && fmt.width > fmt.precision)
		len = fmt.width;
	else
		len = count;
	ret = ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return ;
	startind = init_x(fmt, ret, len, str);
	write_num(fmt, startind, str, ret);
	put_sign(need_sign(fmt, str), need_space(str, fmt), ret);
	ft_putstr_count(ret, icount, len);
	free(ret);
}

void	str_hexnum(t_format fmt, unsigned int str, int *count)
{
	mal_x(fmt, str, count);
}
