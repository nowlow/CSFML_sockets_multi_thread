SRC = 	netscape.c						\
		src/client.c 					\
		src/server.c	 				\
		src/threads/clients_manager.c	\
		src/threads/messages_manager.c	\
		src/threads/thread_manager.c

NAME = netscape

CSFML_FLAGS =	-lcsfml-system			\
				-lcsfml-network

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) -Wall -W -Wextra $(SRC) -I./include $(CSFML_FLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all