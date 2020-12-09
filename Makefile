NAME = Wolf3d

SRCS =  ./src/main.c \
	./src/read_map.c\
	./src/ray_cast.c\
	./src/key_push.c\
	./src/draw_around.c\
	./src/texture.c\
	./src/mini_map.c\
	./src/music.c\
	./src/key_push1.c\
	./src/key_push2.c\
	./src/other.c\
	./src/other1.c\
	./src/free_memory.c\
	./src/ray_cast1.c\
	./src/ray_cast2.c\

OB = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

INCLUDES = -I $(HEADER_DIR) -I $(LIBFT_PATH)

HEADER_DIR = ./include/
HEADER_LIST = wolf.h keys.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT = libft/libft.a
LIBFT_PATH = libft
MINILIBX = ./minilibx/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean clean re

all: $(NAME)
$(NAME): $(LIBFT) $(OB) $(HEADER)
	gcc $(FLAG) $(OB) -o $(NAME) -L $(LIBFT_PATH) -lft -L $(MINILIBX) -lpthread -g fmod/libfmod.dylib


$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c $(HEADER)
	@gcc $(FLAG) $(INCLUDES) -c $< -o $@

norme:
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(INCLUDES)
	@echo
	norminette ./$(SRCS)
clean:
	@/bin/rm -f $(OB)
	@$(MAKE) -C $(LIBFT_PATH) clean
fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
re: fclean all


# -L $(MINILIBX) -lpthread
