/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:10 by bmuni             #+#    #+#             */
/*   Updated: 2023/04/11 17:40:25 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const n, int grade) : name(n)
{
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	this->grade = src.grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::string const Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		this->grade -= 1;
		if (this->grade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		this->grade = 1;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		this->grade += 1;
		if (this->grade > 150)
			throw GradeTooLowException();
	}
 	catch(const std::exception& e)
	{
		this->grade = 150;
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(bool s, std::string name)
{
	if (s == true)
		std::cout << this->getName() << " signed " << name << std::endl;
	else
		std::cout << this->getName() << " cannot sign " << name << " because grade is too low" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat& bu)
{
	os << bu.getName() << "  bureaucrat grade " << bu.getGrade() << std::endl;
	return (os);
}