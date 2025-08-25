#include "Animal.hpp"

Animal::Animal(void) : type("")
{
	std::cout << "An animal has been created" << std::endl;
}

Animal::Animal(const Animal& src) : type(src.getType())
{
	std::cout << "An animal has been copied" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	this->type = rhs.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "An animal has been destroyed" << std::endl;
}

std::string	Animal::getType(void) const { return this->type; }
