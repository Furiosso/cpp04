#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src)
{
	*this = src;
}

Ice& Ice::operator=(const Ice& rhs)
{
	return *this;
}

Ice::~Ice(void) {}

AMateria*	Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
