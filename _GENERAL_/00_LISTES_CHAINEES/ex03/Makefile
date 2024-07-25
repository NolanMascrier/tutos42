# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:35:47 by nmascrie          #+#    #+#              #
#    Updated: 2023/04/14 12:35:49 by nmascrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= tests
FLAG	= -Wall -Wextra -Werror -g3

SRC	=	utils.c old.c new.c main.c

OBJ  = $(SRC:c=o)

#Flags pour les nettoyages
CLEANCMD = rm -rf *.o
FCLEANCMD = rm -f *.a tests

#Cree la lib, et garde les fichiers .o generes
all:$(NAME)

$(NAME): $(OBJ)
	@echo "\e[34mCompilation des test ...\e[97m\e[4m"
	@cc $(FLAG) -o $(NAME) $(OBJ)
	@echo "\e[0m\033[1;32mTests compilee.\n"

#compile un unique fichier .c en .o
%.o: %.c
	@printf "\033[0;33mCompilation de %-33.33s\r" $@
	@cc $(FLAG) -c $< -o $@ -Iinclude

clean:
	$(CLEANCMD)
	@echo "\e[91m\e[1mFichiers .o nettoyes\n"

fclean: clean
	@echo "\e[91m\e[1m"
	$(FCLEANCMD)
	@echo "\e[91m\e[1mFichiers crees nettoyes\n"

re: fclean all

.PHONY: all clean fclean re