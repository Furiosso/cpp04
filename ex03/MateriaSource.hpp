#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
	protected:
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource(void);
		void		learnMateria(AMateria*);
		AMateria*	createMateria(const std::string& type);
};

#endif
