/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:51:03 by lmoricon          #+#    #+#             */
/*   Updated: 2024/03/02 16:57:48 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
* @param path: path to a file
* return : string of the whole file
*/
char  *file_to_str(char *path)
{
  int  fd;
  char  buf[BUFFER_SIZE + 1];
  char  *ret;
  char  *tofree;
  
  ret = ft_strdup("");
  buf[BUFFER_SIZE] = 0;
  fd = open(path, O_RDONLY);
  while(read(fd, buf, BUFFER_SIZE) > 0)
  {
    tofree = ret;
    ret = ft_strjoin(ret, buf);
    free(tofree);  
  }
  close(fd);
  return (ret);
}

