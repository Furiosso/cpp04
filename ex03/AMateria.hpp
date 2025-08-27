#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& rhs);
		virtual ~AMateria(void);
		const std::string&	getType(void) const;
		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream& o, AMateria const& value);

#endif
