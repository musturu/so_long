# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
MFLAGS	= -lXext -lX11 -lm -lbsd

# Directories
SRCDIR = srcs
OBJDIR = objs
FT_PRINTFDIR = libs/ft_printf
LIBFTDIR = libs/ft_printf/libft
MLXDIR = libs/mlx

# Libraries
LIBSFLAG = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf -L$(MLXDIR) -lmlx_Linux

# Source files
SRCS = so_long.c \
	   srcs/fd_to_string.c srcs/print_map.c srcs/init.c \
	   srcs/physics.c srcs/validation.c srcs/graphics_utils.c \
	   srcs/hooks.c srcs/exit_strat.c srcs/utils.c srcs/collision.c srcs/utils2.c
OBJS = so_long.o \
	   objs/fd_to_string.o objs/print_map.o objs/init.o \
	   objs/physics.o objs/validation.o objs/graphics_utils.o \
	   objs/hooks.o objs/exit_strat.o objs/utils.o objs/collision.o objs/utils2.o


# Executable name
NAME = so_long

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror  $(LIBSFLAG) -I/usr/include -I$(MLXDIR) -O3 -c $< -o $@


$(NAME): $(OBJS)
	@ make -C $(FT_PRINTFDIR)
	@ make -C $(MLXDIR)
	@ make -C $(LIBFTDIR)
	$(CC) $(OBJS) -L$(MLXDIR) -lmlx_Linux -L/usr/lib -I$(MLXDIR) -lXext -lX11 -lm -lz $(LIBSFLAG) -o $(NAME)

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
