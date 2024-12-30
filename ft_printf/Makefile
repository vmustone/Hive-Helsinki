# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 12:58:26 by vmustone          #+#    #+#              #
#    Updated: 2022/12/22 19:41:44 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a

LIBFT_DIR = ./libft

INCLUDE = ft_printf.h

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_NAME) ./$(NAME)
	cc -c $(FLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJ) 
	
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re