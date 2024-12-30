Name = animal

Flags = -std=c++98 -Wall -Werror -Wextra

Src = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

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