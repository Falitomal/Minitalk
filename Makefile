NAME = minitalk

CLIENT = client
SERVER = server

SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ = ${:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF = ./ft_printf

${PRINTF}: ${OBJ}
			@make -sC ./ft_printf
			@cp ./ft_printf/libftprintf.a
			@echo "--Done Printf--"

$(NAME): all

all:  
			@echo "----Making PRINTF----"
			@make -s -C $(PRINTF) 
			@gcc $(FLAGS) server.c -o $(SERVER)
			@echo "----Making Server----"
			@gcc $(FLAGS) client.c -o $(CLIENT)
			@echo "----Making Client----"
			@echo "----ALL DONE----"


clean:
			@rm	-rf $(NAME) $(OBJ) .a.out server client
			@make -sC ./ft_printf clean
			@clear
			@echo "----Simple Clean Done----"

fclean:	clean
			@make fclean -s -C $(PRINTF)
			@rm -rf minitalk.a
			@echo "----Force Clean Done----"

re: fclean all
			@echo "--Force Rebuild--"
.PHONY: all clean re fclean