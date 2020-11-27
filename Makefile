MLX = -Lminilibx_opengl_20191021 -lmlx -lm -framework OpenGL -framework AppKit

NAME = cub3D

SFLAGS = -Wall -Wextra -Werror

SRCS = 	cub3d.c \
		bitmap.c \
		check.c \
		dealer.c \
		draw.c \
		else.c \
		errors.c \
		init.c \
		map.c \
		parser.c \
		ray.c \
		utils.c \
		utils_3.c \
		utils2.c

OBJSRCS = $(SRCS:.c=.o) 

$(NAME) : $(OBJSRCS)
	@rm -rf Cub3D
	@$(MAKE) -C ./minilibx_opengl_20191021
	@$(MAKE) bonus -C ./libft
	@gcc $(OBJSRCS) -Icub3d.h -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_opengl_20191021

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all
