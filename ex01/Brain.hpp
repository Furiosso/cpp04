#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(std::string idea);
		Brain(const Brain& src);
		Brain& operator=(const Brain& rhs);
		~Brain(void);
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif
