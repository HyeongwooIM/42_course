NAME = Zombie
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp main.cpp ZombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re