/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:11 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 14:16:10 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), sign(false), grade(150), exe(150)
{
	return ;
}

Form::Form(std::string const name, int grade, int exe) : name(name), sign(false), grade(grade), exe(exe)
{
	try
	{
		if (this->grade > 150)
			throw Form::GradeTooLowException();
		else if (this->grade < 1)
			throw Form::GradeTooHighException();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Form::Form(Form const &src) : sign(false), grade(src.getGrade()), exe(src.getExe())
{
	*this = src;
	return ;
}

Form &Form::operator=(Form const &src)
{
	this->sign = src.getSign();
	return(*this);
}

Form::~Form()
{
	return ;
}

std::string const Form::getName() const
{
	return (this->name);
}

bool	Form::getSign() const
{
	return (this->sign);
}

int	Form::getGrade() const
{
	return (this->grade);
}

int	Form::getExe() const
{
	return (this->exe);
}

void	Form::beSigned(Bureaucrat bu)
{
	try 
	{
		if (bu.getGrade() < this->grade)
			this->sign = true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	bu.signForm(this->getSign(), this->getName());
}