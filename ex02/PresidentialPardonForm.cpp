/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:40:34 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:03:44 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

Presidential::Presidential() : AForm("default", 25, 5), target("default"), sign(false), grade(25), exe(5)
{
	return ;
}

Presidential::Presidential(std::string const target) : AForm(target, 25, 5), target(target), sign(false), grade(25), exe(5)
{
	return ;
}

Presidential::Presidential(Presidential const &src) : AForm(src.getTarget(), src.getGrade(), src.getExe()), target(src.getTarget()), sign(src.getSign()), grade(src.getGrade()), exe(src.getExe())
{
	return ;
}

Presidential &Presidential::operator=(Presidential const &src)
{
	this->sign = src.getSign();
	return (*this);
}

Presidential::~Presidential()
{
	return ;
}

std::string const Presidential::getTarget() const
{
	return (this->target);
}

bool	Presidential::getSign() const
{
	return (this->sign);
}

int	Presidential::getGrade() const
{
	return (this->grade);
}

int	Presidential::getExe() const
{
	return (this->exe);
}

void	Presidential::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->exe)
		throw Presidential::GradeTooLowException();
	else
		this->pardon(executor);
}

void	Presidential::pardon(Bureaucrat const & executor) const
{
	std::cout << "\033[1;33m" <<  executor.getName() << " has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
}