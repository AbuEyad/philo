# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 08:16:20 by habu-zua          #+#    #+#              #
#    Updated: 2023/11/10 14:32:49 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = objects/

SRC =	philo_bonus \
    	eat \
    	getters \
    	init_data \
    	monitor \
		parse \
    	print_msg \
       	routine \
    	setters \
    	sleep \
    	think \
    	time \
    	utils

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
#-g #-fsanitize=thread 
.PHONY: all clean fclean re