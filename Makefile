NAME = cub3D

SRCS_DIR = src/

INC_DIR = includes

SRCS_F = main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_F))

SRCS_O = $(patsubst	%.c, %.o, $(SRCS))

SRCS_D = $(patsubst %.c, %.d, $(SRCS))

CC = cc -Wall -Wextra -Werror -MMD

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) -I$(INC_DIR) -c $< -o $@

$(NAME): Makefile $(SRCS_O) $(SRCS_D) $(SRCS_D)
	$(CC) $(SRCS_O) -I$(INC_DIR) -o $@

clean:
	$(RM) $(SRCS_O) $(SRCS_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(SRCS_D)