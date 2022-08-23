# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 21:04:41 by jledesma          #+#    #+#              #
#    Updated: 2022/08/10 22:00:10 by jledesma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CLIENT = client
SERVER = server

SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ = ${:.c=.o}

SRC_PRINTF = ft_printf
LIBFPRINTF = ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
COLOR_DONE = \033[47m\033[1;32m

all:  $(LIBFPRINTF) $(CLIENT) $(SERVER)


$(SERVER): $(OBJ_SERVER) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(OBJ_SERVER)
	@echo "$(COLOR_DONE)----SERVER DONE----\n"

$(CLIENT): $(OBJ_CLIENT) minitalk.h
	@$(CC) $(CFLAGS) $(LIBFPRINTF) -o $@ $(OBJ_CLIENT)
	@echo "$(COLOR_DONE)----CLIENT DONE----\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

${LIBFPRINTF}:
			@$(MAKE) -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----DONE PRINTF----\n"
clean:
			@ $(MAKE) clean -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----CLEAN PRINTF-----\n"
			@rm	-rf $(OBJ_SERVER) $(OBJ_CLIENT)
			@echo "$(COLOR_DONE)----CLEAN SERVER&CLIENT----\n"
			
fclean:	clean
			@ $(MAKE) fclean -sC $(SRC_PRINTF)
			@echo "$(COLOR_DONE)----FORCE CLEAN LIBFTPRINTF----\n"
			@rm -rf minitalk.a $(CLIENT) $(SERVER)
			@echo "$(COLOR_DONE)----FORCE CLEAN----\n"

re: fclean all
			@echo "$(COLOR_DONE)----FORCE REBUILD----\n"
			
.PHONY: all clean re fclean