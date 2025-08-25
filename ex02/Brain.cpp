#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "GRRRR";
	std::cout << "A brain has been created" << std::endl;
}

Brain::Brain(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
	std::cout << "A brain has been created" << std::endl;
}

Brain::Brain(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "A brain has been copied" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "A brain has been destroyed" << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index > -1 && index < 101)
		this->_ideas[index] = idea;
	else
		std::cerr << "Invalid index" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index > -1 && index < 101)
		return this->_ideas[index];
	std::cerr << "Invalid index" << std::endl;
	return "";
}