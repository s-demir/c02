NAME		= ex00
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
RM			= rm -rf

SRCS		= main.cpp Fixed.cpp
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re