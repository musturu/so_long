/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_per_c_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:36:56 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/06 16:50:54 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_c(t_format format, int c, int *count)
{
	char	*ret;
	int		len;

	if (format.width == 0)
		len = 1;
	else
		len = format.width;
	ret = ft_calloc(sizeof(char), len + 1);
	if (ret == NULL)
		return ;
	ft_memset(ret, ' ', len);
	ret[len] = '\0';
	if (ft_strchr(format.flags, '-'))
		ret[0] = c;
	else
		ret[len - 1] = c;
	ft_putstr_count(ret, count, len);
	free(ret);
}

void	str_perc(int *count)
{
	char	*ret;

	ret = ft_calloc(sizeof(char), 2);
	if (ret == NULL)
		return ;
	ret[0] = '%';
	ft_putstr_count(ret, count, 1);
	free(ret);
}

static void	ft_new_strlcpy(char *dest, char *src, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

static void	aux(int *len, char **str, t_format *format)
{
	if (*str == NULL)
		*str = "(null)";
	*len = ft_strlen(*str);
	if (*len > (*format).width)
	{
		if ((*format).pflag)
		{
			if (*len > (*format).precision)
				*len = (*format).precision;
		}
	}
	if (*len <= (*format).width)
		*len = (*format).width;
}

void	str_s(t_format format, char *str, int *count)
{
	char	*ret;
	int		len;
	int		maxwrite;

	aux(&len, &str, &format);
	ret = ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return ;
	ft_memset(ret, ' ', len);
	if (format.pflag && (int)ft_strlen(str) > format.precision)
		maxwrite = format.precision;
	else
		maxwrite = ft_strlen(str);
	if (ft_strchr(format.flags, '-'))
		ft_new_strlcpy(ret, str, maxwrite);
	else
		ft_strlcpy(ret + (len - maxwrite), str, maxwrite + 1);
	ft_putstr_count(ret, count, len);
	free(ret);
}
