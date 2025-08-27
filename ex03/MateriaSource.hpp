#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>

class	MateriaSource
{
	private:
	protected:
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource(void);
};

std::ostream&	operator<<(std::ostream& o, MateriaSource const& value);

#endif
