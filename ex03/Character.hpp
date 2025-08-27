#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*  	_inventory[4];
	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& src);
		Character& operator=(const Character& rhs);
		~Character(void);
		const std::string&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
