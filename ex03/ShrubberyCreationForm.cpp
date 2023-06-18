/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:02:10 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:04:08 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("default", 145, 137), target("default"), sign(false), grade(145), exe(137)
{
	return ;
}
	
Shrubbery::Shrubbery(std::string const target) : AForm(target, 145, 137), target(target), sign(false), grade(145), exe(137)
{
	return ;
}

Shrubbery::Shrubbery(Shrubbery const &src) : AForm(src.getTarget(), src.getGrade(), src.getExe()), target(src.getTarget()), sign(src.getSign()), grade(src.getGrade()), exe(src.getExe())
{
	return ;
}

Shrubbery &Shrubbery::operator=(Shrubbery const &src)
{
	this->sign = src.getSign();
	return (*this);
}

Shrubbery::~Shrubbery()
{
	return ;
}

std::string const Shrubbery::getTarget() const
{
	return (this->target);
}

bool	Shrubbery::getSign() const
{
	return (this->sign);
}

int	Shrubbery::getGrade() const
{
	return (this->grade);
}

int	Shrubbery::getExe() const
{
	return (this->exe);
}

void Shrubbery::execute(Bureaucrat const & executor) const
{
	try 
	{
		if (executor.getGrade() <= this->grade)
			this->draw();
		else if (this->getSign() == true)
			throw Shrubbery::GradeTooLowException();
		else
			throw Shrubbery::NotSignedException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Shrubbery::draw(void) const
{
	std::fstream file;
	const std::string toOpen = this->getTarget() + "_shrubbery.txt";
	file.open(toOpen.c_str(), std::ios::out);
	file << "          ,@@@@@@@,          " << std::endl;
	file << "      ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	file << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      " << std::endl;
	file << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'      " << std::endl;
	file << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'      " << std::endl;
	file << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'      " << std::endl;
	file << "  `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
	file << "      |o|        | |         | |      " << std::endl;
	file << "      |.|        | |         | |      " << std::endl;
	file << "  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
}