/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:11 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 16:51:05 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), grade(150), exe(150)
{
	return ;
}

AForm::AForm(std::string const name, int grade, int exe) : name(name), sign(false), grade(grade), exe(exe)
{
	try
	{
		if (this->grade > 150)
			throw AForm::GradeTooLowException();
		else if (this->grade < 1)
			throw AForm::GradeTooHighException();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

AForm::AForm(AForm const &src) : sign(false), grade(src.getGrade()), exe(src.getExe())
{
	*this = src;
	return ;
}

AForm &AForm::operator=(AForm const &src)
{
	this->sign = src.getSign();
	return(*this);
}

AForm::~AForm()
{
	return ;
}

std::string const AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSign() const
{
	return (this->sign);
}

int	AForm::getGrade() const
{
	return (this->grade);
}

int	AForm::getExe() const
{
	return (this->exe);
}

void	AForm::beSigned(Bureaucrat bu)
{
	if (bu.getGrade() > this->grade)
		throw AForm::GradeTooLowException();
	sign = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->sign == false)
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->exe)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << src.getName() << ", AForm grade " << src.getGrade() << ", execution grade " << src.getExe() << ", signed: " << src.getSign() << std::endl;
	return (o);
}