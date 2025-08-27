#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	return *this;
}

MateriaSource::~MateriaSource(void) {}

std::ostream&	operator<<(std::ostream& o, MateriaSource const& value)
{
	o << value;
	return o;
}

