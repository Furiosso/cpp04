#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice& Ice::operator=(const Ice& rhs)
{
	this->_type = rhs.getType();
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
