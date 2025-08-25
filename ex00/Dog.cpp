# include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "A dog has been created" << std::endl;
}

Dog::Dog(const Dog& src) : Animal()
{
	std::cout << "A dog has been copied" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "A dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF-WOOF" << std::endl;
}
