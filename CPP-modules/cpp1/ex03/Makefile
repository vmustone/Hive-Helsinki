# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 21:24:20 by vmustone          #+#    #+#              #
#    Updated: 2023/10/16 08:30:28 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = weapon

Flags = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

Src = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

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