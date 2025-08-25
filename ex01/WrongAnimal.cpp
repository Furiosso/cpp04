# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("")
{
	std::cout << "A wrong animal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	*this = src;
	std::cout << "A wrong animal has been copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "A wrong animal has been destroyed" << std::endl;
}

std::string	WrongAnimal::getType(void) const { return this->type; }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "wrong GROOOOAR" << std::endl;
}
