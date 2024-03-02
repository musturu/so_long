/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:15 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 15:55:17 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pipeline(const char *str, va_list ap, int *count, int *i);

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			pipeline(str + i, ap, &count, &i);
			i++;
		}
		else
		{
			ft_putchar_count(str[i], &count);
			i++;
		}
	}
	return (count);
}

void	stringify(t_format format, va_list ap, int *count)
{
	if (format.conversion == '%')
		return (str_perc(count));
	if (format.conversion == 'c')
		return (str_c(format, va_arg(ap, int), count));
	if (format.conversion == 's')
		return (str_s(format, va_arg(ap, char *), count));
	if (format.conversion == 'p')
		return (str_ptrnum(format, va_arg(ap, void *), count));
	if (format.conversion == 'd')
		return (str_num(format, va_arg(ap, int), count));
	if (format.conversion == 'i')
		return (str_num(format, va_arg(ap, int), count));
	if (format.conversion == 'u')
		return (str_unsnum(format, va_arg(ap, unsigned int), count));
	if (format.conversion == 'x')
		return (str_hexnum(format, va_arg(ap, unsigned int), count));
	if (format.conversion == 'X')
		return (str_hexnum(format, va_arg(ap, unsigned int), count));
	else
		return ;
}

void	pipeline(const char *str, va_list ap, int *count, int *i)
{
	t_format	format;
	char		*toform;

	toform = get_format(str);
	if (toform == NULL)
		return ;
	*i += ft_strlen(toform) - 1;
	format = read_format(toform);
	stringify(format, ap, count);
	free(format.flags);
}
