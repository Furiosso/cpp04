CC = c++

NAME = polymorphism

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize="address,leak" -g3

CFILES = main.cpp\
		 Animal.cpp\
		 Dog.cpp\
		 Cat.cpp\
		 WrongAnimal.cpp\
		 WrongCat.cpp\
		 Brain.cpp

ODIR = build

OFILES = $(addprefix $(ODIR)/, $(notdir $(CFILES:.cpp=.o)))

all: $(NAME)

$(ODIR)/%.o: %.cpp
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re