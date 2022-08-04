NAME = cub3D

SRCS_DIR = src/

LIBMLX_DIR = mlx/

LIBMLX = libmlx.a

INC_DIR = includes

SRCS_F = main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_F))

SRCS_O = $(patsubst	%.c, %.o, $(SRCS))

SRCS_D = $(patsubst %.c, %.d, $(SRCS))

CC = cc -Wall -Wextra -Werror -MMD

RM = rm -rf

all: libmakes $(NAME) 

%.o: %.c
	$(CC) -I$(INC_DIR) -I$(LIBMLX_DIR) -c $< -o $@

$(NAME): Makefile $(SRCS_O)
	$(CC) $(SRCS_O) -I$(INC_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

libmakes: 
	@make -C $(LIBMLX_DIR)

clean:
	$(RM) $(SRCS_O) $(SRCS_D)
	$(RM) $(LIBMLX_DIR)*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(addprefix $(LIBMLX_DIR), $(LIBMLX))

re: fclean all

.PHONY: all clean fclean re

-include $(SRCS_D)