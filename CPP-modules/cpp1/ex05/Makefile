# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 05:47:37 by villemuston       #+#    #+#              #
#    Updated: 2023/10/09 19:37:02 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = harl

Flags = -std=c++98 -Wall -Werror -Wextra

Src = main.cpp Harl.cpp

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