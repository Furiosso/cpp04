#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) 
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
		if (src._materia[i])
			this->_materia[i] = src._materia[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materia[i];
		this->_materia[i] = NULL;
		if (rhs._materia[i])
			this->_materia[i] = rhs._materia[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return	this->_materia[i]->clone();
	}
	return 0;
}
