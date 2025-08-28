#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& src) : _type(src._type) {}

AMateria::~AMateria(void) {}

const std::string&	AMateria::getType(void) const { return this->_type; }

void	AMateria::use(ICharacter& target)
{
	if (this->_type != "ice" && this->_type != "cure")
		std::cout << "* slaps " << target << " in the face with " << this->_type << " or  whatever it has nearby" << std::endl;
}
