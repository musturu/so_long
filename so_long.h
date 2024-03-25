#ifndef SO_LONG_H
# define SO_LONG_H

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# define TILE_R 128
# define FPS 12
# define AC  0.07
# define DC  -0.07
# define MIN_MOVE 1
# define TURN_SPEED 5
# define FRICTION 0.85

# define PATH_TO_WALL "textures/wall.xpm"
# define PATH_TO_FLOOR "textures/floor2.xpm"
# define PATH_TO_COIN "textures/coin.xpm"
# define PATH_TO_EXIT "textures/exit.xpm"


# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include <stdlib.h>

# include "libs/ft_printf/libft/libft.h"
# include "libs/ft_printf/printffone/ft_printf.h"
# include "libs/mlx/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image;

typedef struct vector2 {
  int x;
  int y;
} t_vec2;

typedef struct dvector2
{
  double  x;
  double  y;
} t_dvec2;

typedef struct s_player
{
  int       img_index;
  t_dvec2   eforce;
  t_dvec2   tforce;
  t_vec2    pos;
  t_dvec2   a;
  t_dvec2   v;
  int       ori;
  char      isaccel;
  char      isturn;
} t_car;

typedef struct s_tile_image {
  t_image wall;
  t_image coin[8];
  int   cind;
  t_image floor;
  t_image exit[2];
  int   eind;
  t_image player[8];
} t_images;

typedef struct s_game
{
  void      *mlx;
  void      *win;
  char      **map;
  t_image   map_img;
  t_vec2    max;
  t_images  images;
  t_car     player;
  int       coins;
  int       steps;
  long long ms;
} t_game;


/* MEMORY */
int free_pp(void **to_free);
int quit_free(t_game game, char *toprint);

/* VALIDATION */
int validate(int argc, char **argv);
char *file_to_str(char *path);

/* GRAPHICS */
void    print_map(t_game game);
void    update_map(t_game game);
t_image	new_file_img(char * path, void *mlx_ptr);
t_image	new_img(int w, int h, void *mlx);
void	put_img_to_img(t_image dst, t_image src, int x, int y);
void    print_player(t_game g);
void    put_count(t_game g);

/* GAMEPLAY */
void    phys_update(t_game *g, int time);
int     update(t_game *g);
void    collision_check(t_game *g);

/* UTILS */
void initialize(char *path, t_game *g);
int   key_hook_down(int key, t_game *game);
int   key_hook_up(int key, t_game *game);
t_vec2 get_tile(t_game g, t_vec2 pixels);
long long	millitime(void);
void	get_ms(t_game *g);
t_vec2 init_vec(int x, int y);
void    get_ori(t_game *g);

#endif
