#include "Dog.hpp"

Dog::Dog(void) : Animal(), _brain(new Brain("I want a bone"))
{
	this->type = "Dog";
	std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "A dog has been copied" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "A dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF-WOOF" << std::endl;
}

Brain*	Dog::getBrain(void) const { return _brain; }
