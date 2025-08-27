#include "ICharacter.hpp"

std::ostream&	operator<<(std::ostream& o, ICharacter const& value)
{
	o << value;
	return o;
}

