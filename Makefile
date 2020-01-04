# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 17:10:05 by vdarmaya          #+#    #+#              #
#    Updated: 2020/01/04 17:10:05 by vdarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = ./includes

DIR_OBJ = ./obj/

DIR_LIB = ./libft/

SRC_DIR = ./srcs/

FILES = main.c

SRCS = $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(patsubst %.c, $(DIR_OBJ)%.o, $(FILES))

RM = /bin/rm -rf

all: mkdirobj $(OBJS)
		@ make -C $(DIR_LIB)
		@ /bin/echo "Archiving object in $(NAME)"
		@ $(CC) -o $(NAME) $(OBJS) $(MFLAGS) -L $(DIR_LIB) -lft
		@ echo "\033[32mAll done!\033[0m"

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	@ /bin/echo -n "    $(notdir $@)"
	@ $(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDE_DIR)
	@ echo " \033[32mOK\033[0m"

mkdirobj:
	@ mkdir -p $(DIR_OBJ)

clean:
	@ make clean -C $(DIR_LIB)
	@ /bin/echo -n "Removing object files:"
	@ $(RM) $(DIR_OBJ)
	@ echo " \033[32mdone\033[0m"

fclean: clean
	@ make fclean -C $(DIR_LIB)
	@ /bin/echo -n "Removing library:"
	@ $(RM) $(NAME)
	@ $(RM) $(NAME).dSYM
	@ echo " \033[32mdone\033[0m"

debug: mkdirobj
	@ make -C $(DIR_LIB)
	@ $(CC) -o $(NAME) $(SRCS) -I$(INCLUDE_DIR) $(MFLAGS) -L $(DIR_LIB) -lft -g


re: fclean all

.PHONY : all clean fclean re