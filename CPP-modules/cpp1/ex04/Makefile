# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 15:35:48 by vmustone          #+#    #+#              #
#    Updated: 2023/10/16 08:41:21 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = replace

Flags = -std=c++98 -Wall -Werror -Wextra

Src = main.cpp file.cpp

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