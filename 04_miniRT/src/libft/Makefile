# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 07:51:47 by cheseo            #+#    #+#              #
#    Updated: 2023/05/08 19:55:13 by cheseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
INCS	:=	-I ../../includes
CFLAGS	:=	-Wall -Wextra -Werror
AR		:=	ar rcs

SRCS	:= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c my_atoi.c \
			ft_strcmp.c ft_split_charset.c ft_free_2d_array.c ft_atod.c
OBJS	:=	$(SRCS:.c=.o)

B_SRCS	:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_OBJS	:=	$(B_SRCS:.c=.o)

GNL	:=	get_next_line.c get_next_line_utils.c
G_OBJS	:=	$(GNL:.c=.o)

%.o		:	%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

.PHONY	:	re all clean fclean bonus

all		:	$(NAME)
bonus	:	$(NAME)

$(NAME)	:	$(OBJS) $(if $(filter bonus,$(MAKECMDGOALS)), $(B_OBJS)) $(G_OBJS)
			$(AR) $(NAME) $^

clean	:
			$(RM) $(OBJS) $(B_OBJS) $(G_OBJS)
			$(RM) *.gch

fclean	:
			$(RM) $(OBJS) $(B_OBJS) $(G_OBJS) $(NAME)
			$(RM) *.gch

re		:
			$(MAKE) fclean
			$(MAKE) all
