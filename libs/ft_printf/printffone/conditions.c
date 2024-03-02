/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:34 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:05:35 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_accepted_conv(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	is_accepted_flag(int c)
{
	if (c == '-' || c == ' ' || c == '0' || c == '#' || c == '+')
		return (1);
	else
		return (0);
}

int	is_signed(int c, t_format fmt)
{
	char	conv;

	conv = fmt.conversion;
	if ((c < 0 || ft_strchr(fmt.flags, '+')) && (conv == 'i' || conv == 'd'))
		return (1);
	else
		return (0);
}

int	need_space(int c, t_format fmt)
{
	char	cv;

	cv = fmt.conversion;
	if (((cv == 'x' || cv == 'X') && ft_strchr(fmt.flags, '#')) && c != 0)
		return (2);
	if (is_signed(c, fmt))
		return (1);
	else if (ft_strchr(fmt.flags, ' ')
		&& (fmt.conversion == 'd' || fmt.conversion == 'i') && !fmt.pflag)
		return (1);
	else
		return (0);
}
