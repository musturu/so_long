/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:53:00 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/12 10:54:33 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[4096][BUFFER_SIZE + 1];
	int			readr;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	i = 0;
	readr = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readr >= 0 && hasnl(line) == 0)
	{
		if (!*buf[fd])
			readr = read(fd, buf[fd], BUFFER_SIZE);
		if (readr <= 0)
			break ;
		i++;
		line = ft_strealloc(line, i);
		cat_n_rem(line, buf[fd], 1);
	}
	if (line && *line)
		return (line);
	free(line);
	return (0);
}
