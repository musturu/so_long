#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define TILE_R 64

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# include "libs/ft_printf/printffone/ft_printf.h"
# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

typedef struct vector2
{
    int x;
    int y;
}   t_vec2;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    t_vec2  max;
    
}   t_game;
/* MEMORY */
void    free_pp(void **to_free);

/* VALIDATION */
int     validate(char **map);
char    *file_to_str(char *path);

/* GRAPHICS */

/* GAMEPLAY */

/* UTILS */
void    initialize(char *path, t_game *g);


#endif
