#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# include "libs/ft_printf/printffone/ft_printf.h"
# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

//MEMORY
void    free_pp(void **to_free);

//VALIDATION
int     validate(char **map);
char    *file_to_str(char *path);

//GRAPHICS

//GAMEPLAY


#endif
