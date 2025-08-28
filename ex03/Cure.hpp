#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	private:
	protected:
	public:
		Cure(void);
		Cure(const Cure& src);
		Cure& operator=(const Cure& rhs);
		~Cure(void);
		AMateria* 	clone() const;
		void		use(ICharacter& target);
};

#endif
