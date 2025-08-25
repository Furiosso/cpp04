#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain("I have to catch a mouse"))
{
	this->type = "Cat";
	std::cout << "A cat has been created" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "A cat has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "A cat has been destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW" << std::endl;
}

Brain*	Cat::getBrain(void) const { return _brain; }