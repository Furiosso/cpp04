# include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "A cat has been created" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "A cat has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "A cat has been destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW" << std::endl;
}
