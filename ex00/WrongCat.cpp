# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "A wrong cat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal()
{
	std::cout << "A wrong cat has been copied" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "wrong MEOW" << std::endl;
}
