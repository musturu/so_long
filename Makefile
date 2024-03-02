# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
MFLAGS	= -lmlx -framework OpenGL -framework AppKit

# Directories
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = libft
FT_PRINTFDIR = ft_printf
MLXDIR = mlx

# Libraries
LIBS = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf -L$(MLXDIR) -lmlx

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c get_next_line/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Executable name
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(LIBFTDIR)
	@ make -C $(FT_PRINTFDIR)
	@ make -C ./mlx
	$(CC) $(CFLAGS) $^  $(MFLAGS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re