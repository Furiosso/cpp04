#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal& src);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal(void);
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
