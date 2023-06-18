/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:10 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 16:52:33 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const n, int grade) : name(n), grade(grade)
{
	try
	{
		if (this->grade > 150)
		{
			this->grade = 150;
			throw GradeTooLowException();
		}
		else if (this->grade < 1)
		{
			this->grade = 1;
			throw GradeTooHighException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
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

std::ostream & operator<<(std::ostream & os, const Bureaucrat& bu)
{
	os << bu.getName() << "  bureaucrat grade " << bu.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		if (form.getGrade() >= this->getGrade())
			std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (form.getExe() >= this->getGrade() && form.getSign() == true)
		{
			form.execute(*this);
			std::cout << this->getName() << " executes " << form.getName() << std::endl;
		}
		else if (form.getSign() == false)
			throw NotSignedException();
		else
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}