/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:53:46 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:11:01 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	needed_pad(t_format fmt)
{
	if (!ft_strchr(fmt.flags, '-') && ft_strchr(fmt.flags, '0') && !fmt.pflag)
		return ('0');
	else
		return (' ');
}

char	*need_sign(t_format fmt, int c)
{
	char	conv;

	conv = fmt.conversion;
	if ((conv == 'x' || conv == 'X'))
	{
		if (conv == 'x' && ft_strchr(fmt.flags, '#') && c != 0)
			return ("0x");
		if (conv == 'X' && ft_strchr(fmt.flags, '#') && c != 0)
			return ("0X");
		return (0);
	}
	if (is_signed(c, fmt))
	{
		if (c < 0)
			return ("-");
		else
			return ("+");
	}
	else if (ft_strchr(fmt.flags, ' ')
		&& (conv == 'd' || conv == 'i') && !fmt.pflag)
		return (" ");
	else
		return (0);
}

void	put_sign(char *sign, int sign_num, char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		if (ft_isalnum(dest[i]))
		{
			if (i == 0)
				ft_memcpy(dest, sign, sign_num);
			else
				ft_memcpy(dest + i - sign_num, sign, sign_num);
			return ;
		}
		i++;
	}
}
