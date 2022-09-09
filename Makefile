# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 21:04:41 by jledesma          #+#    #+#              #
#    Updated: 2022/09/09 12:28:38 by jledesma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CLIENT = client
SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}
#BONUS
SRC_CLIENT_B = client_bonus.c 
SRC_SERVER_B = server_bonus.c
OBJ_CLIENT_B = ${SRC_CLIENT_B:.c=.o}
OBJ_SERVER_B = ${SRC_SERVER_B:.c=.o}
NAME_BONUS_CL = client_bonus
NAME_BONUS_SV = server_bonus

#UTILS
SRC_PRINTF = ft_printf
LIBFPRINTF = ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
COLOR_DONE = \033[47m\033[1;32m
all: normi $(LIBFPRINTF) $(CLIENT) $(SERVER) bonus


$(SERVER): $(OBJ_SERVER) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(OBJ_SERVER)
	@echo "$(COLOR_DONE)----SERVER DONE----\n"

$(CLIENT): $(OBJ_CLIENT) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(OBJ_CLIENT)
	@echo "$(COLOR_DONE)----CLIENT DONE----\n"
	
$(SERVER_B): $(OBJ_SERVER_B) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(NAME_BONUS_SV)
	@echo "$(COLOR_DONE)----SERVER BONUS DONE----\n"

$(CLIENT_B): $(OBJ_CLIENT_B) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(NAME_BONUS_CL)
	@echo "$(COLOR_DONE)----CLIENT BONUS DONE----\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@ 

${LIBFPRINTF}:
			@$(MAKE) -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----DONE PRINTF----\n"
normi:
	@norminette .
	@echo "$(COLOR_DONE)----NORMINETTE----\n"
clean:
			@ $(MAKE) clean -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----CLEAN PRINTF-----\n"
			@rm	-rf $(OBJ_SERVER) $(OBJ_CLIENT)
			@echo "$(COLOR_DONE)----CLEAN SERVER&CLIENT----\n"
			@rm	-rf $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
			@echo "$(COLOR_DONE)----CLEAN BONUS----\n"
			
fclean:	clean
			@ $(MAKE) fclean -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----FORCE CLEAN LIBFTPRINTF----\n"
			@rm -rf minitalk.a $(CLIENT) $(SERVER) $(NAME_BONUS_CL) $(NAME_BONUS_SV)
			@echo "$(COLOR_DONE)----FORCE CLEAN----\n"

bonus : ${SERVER_B} ${CLIENT_B} ${LIBFPRINTF}
			@gcc $(SRC_CLIENT_B) ${LIBFPRINTF} -o ${NAME_BONUS_CL}
			@gcc $(SRC_SERVER_B) ${LIBFPRINTF} -o ${NAME_BONUS_SV}
			@echo "$(COLOR_DONE)----MAKE BONUS----\n"

re: fclean all
			@echo "$(COLOR_DONE)----FORCE REBUILD----\n"
			
.PHONY: all clean re fclean normi bonus