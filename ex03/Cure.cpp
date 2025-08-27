#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& src)
{
	*this = src;
}

Cure& Cure::operator=(const Cure& rhs)
{
	return *this;
}

Cure::~Cure(void) {}

AMateria*	Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << " wounds *" << std::endl;
}
