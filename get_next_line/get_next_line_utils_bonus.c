/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:56:15 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/12 11:02:19 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	cat_n_rem(char *dst, char *src, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (src[i])
	{
		dst[i + j] = src[i];
		src[i] = '\0';
		i++;
		if (flag && dst[i + j - 1] == '\n')
			break ;
	}
	if (src[i])
		cat_n_rem(src, src + i, 0);
}

void	*ft_strealloc(char *str, int cycle)
{
	char	*ret;

	if (cycle == 1)
		return (str);
	ret = (char *)ft_calloc(sizeof(char), ((cycle * BUFFER_SIZE) + 1));
	if (str && ret)
	{
		cat_n_rem(ret, str, 0);
		free(str);
	}
	return (ret);
}

char	*hasnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	void	*ret;

	ret = malloc(num * size);
	if (ret == NULL)
		return (ret);
	i = 0;
	while (i < num * size)
	{
		((unsigned char *)ret)[i] = '\0';
		i++;
	}
	return (ret);
}
