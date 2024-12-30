# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: villemustonen <villemustonen@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 01:39:18 by villemuston       #+#    #+#              #
#    Updated: 2023/10/15 08:30:37 by villemuston      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fragtrap

Flags = -std=c++98 -Wall -Werror -Wextra

Src = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

Obj = $(Src:%.cpp=%.o)

all: $(Name)

$(Name): $(Src) $(Obj)
	c++ $(Flags) $(Obj) -o $(Name)

clean:
	rm -f $(Obj)

fclean: clean
	rm -f $(Name)

re: fclean all

.phony: all clean fclean re