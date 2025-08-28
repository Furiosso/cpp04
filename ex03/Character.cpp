#include "Character.hpp"

Character::Character(void) : _name("")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& src) : _name(src.getName())
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

const std::string&	Character::getName(void) const { return _name; }

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > -1 && idx < 4)
		this->_inventory[idx] = NULL;	
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
