# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:52:51 by cheseo            #+#    #+#              #
#    Updated: 2023/05/23 13:53:05 by cheseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT
CC			:=	cc
DEBUG		:=	-g3 -fsanitize=address
CFLAGS		:=	-Wall -Wextra -Werror #$(DEBUG)

SRCS_DIR	:=	src

CPPFLAGS	:=	-I./includes
LDFLAGS		:=	-L./mlx -framework OpenGL -framework AppKit #$(DEBUG)
LDLIBS		:=	-lmlx

# ========= LIBFT ========= #
LIBFT		:=	$(SRCS_DIR)/libft/libft.a
LIBFT_DIR	:=	$(SRCS_DIR)/libft

# ========= MANDATORY ========= #
PACK				:=	parse error linked_list utils vec scene ray hit
parse_SRCS			:=	check_input read_input set_struct alloc_object print_struct print_object print_list free_objects
error_SRCS			:=	error
linked_list_SRCS	:=	list_utils_1
utils_SRCS			:=	mlx_util camera_moving
vec_SRCS			:=	vec_util1 vec_util2 vec_util3 vec_util4
scene_SRCS			:=	scene
ray_SRCS			:=	ray phong_lighting
hit_SRCS			:=	hit hit_sphere hit_plane hit_cylinder hit_utils

define choose_dir
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)_SRCS),\
			$(SRCS_DIR)/$(pkg)/$(file).c\
		)\
	) $(SRCS_DIR)/main.c
endef

%.o			:	%.c
				$(CC) $(CFLAGS) $(CPPFLAGS)	-c -o $@ $^

SRCS		:=	$(call choose_dir, $(PACK))
OBJS		:=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)

# $(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(CPPFLAGS) -o $(NAME)
$(NAME)		:	$(OBJS)
				$(MAKE) -C $(LIBFT_DIR)
				$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)
				@echo "🥕💪 make"

clean		:
				$(RM) -r $(OBJS)
				$(MAKE) -C $(LIBFT_DIR) clean
				@echo "🥕💪 make clean"

fclean		:	clean
				$(RM) -r $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean
				@echo "🥕💪 make fclean"

re			:
				$(MAKE) fclean
				$(MAKE) all
				@echo "🥕💪 make re"
