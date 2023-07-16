NAME = Bureaucrat
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
SRCS = main.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re