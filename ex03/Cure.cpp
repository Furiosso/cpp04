#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria("cure")
{
	*this = src;
}

Cure& Cure::operator=(const Cure& rhs)
{
	this->_type = rhs.getType();
	return *this;
}

Cure::~Cure(void) {}

AMateria*	Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
