#include "AMateria.hpp"

AMateria::AMateria(void) : _type("ice") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& src) {}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	return *this;
}

AMateria::~AMateria(void) {}

const std::string&	AMateria::getType(void) const { return this->_type; }
