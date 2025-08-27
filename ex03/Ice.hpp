#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	private:
	protected:
	public:
		Ice(void);
		Ice(const Ice& src);
		Ice& operator=(const Ice& rhs);
		~Ice(void);
		AMateria* 	clone() const;
		void		use(ICharacter& target);
};

#endif
