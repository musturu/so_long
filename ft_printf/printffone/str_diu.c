/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:51 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:33:32 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	mal_diux(t_format fmt, long int str, int base, int *count);
static int	init_diux(t_format fmt, char *str, int len, long int num);

void	str_num(t_format fmt, int str, int *count)
{
	mal_diux(fmt, str, 10, count);
}

void	str_unsnum(t_format fmt, unsigned int str, int *count)
{
	mal_diux(fmt, str, 10, count);
}

static void	mal_diux(t_format fmt, long int str, int base, int *icount)
{
	char	*ret;
	int		count;
	int		len;
	int		startind;
	char	*sign;

	sign = need_sign(fmt, str);
	count = countdig(str, base) + need_space(str, fmt);
	if (fmt.precision >= fmt.width && fmt.precision >= count)
		len = fmt.precision + need_space(str, fmt);
	else if (fmt.width > count && fmt.width > fmt.precision)
		len = fmt.width;
	else
		len = count;
	ret = ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return ;
	startind = init_diux(fmt, ret, len, str);
	if (str < 0)
		str = -str;
	write_num(fmt, startind, str, ret);
	put_sign(sign, count - countdig(str, base), ret);
	ft_putstr_count(ret, icount, len);
	free(ret);
}

static int	init_diux(t_format fmt, char *str, int len, long int num)
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
		if (fmt.precision > countdig(num, base) + i)
			startindex = len - (countdig(num, base));
		else
			startindex = len - (countdig(num, base));
	}
	ft_memset((str + i), '0', fmt.precision);
	return (startindex);
}
