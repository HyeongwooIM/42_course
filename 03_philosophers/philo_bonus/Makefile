CC = cc
CFLAGS = -Wall -Werror -Wextra  -fsanitize=thread -g3
#  -fsanitize=thread -g3
SRCS = philo_bonus.c \
			# util.c 
			# act.c
OBJS = $(SRCS:%.c=%.o)
NAME = philo_bonus

all : $(NAME)

# %.o : %.c
# 	@$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o ${NAME} ${OBJS}
	@echo	"🙋‍♀️🙋‍♂️ make"

clean :
	@rm -rf $(OBJS)
	@echo	"🙋‍♀️🙋‍♂️ make clean"

fclean : clean
	@rm -rf $(NAME)
	@echo	"🙋‍♀️🙋‍♂️ make fclean"

re :
	@make fclean
	@make all
	@echo	"🙋‍♀️🙋‍♂️ make re"

.PHONY : all bonus clean fclean re
