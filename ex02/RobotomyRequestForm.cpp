/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:32:20 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 16:59:42 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

Robo::Robo() :  AForm("default", 72, 45), target("default"), sign(false), grade(72), exe(45)
{
	return ;
}

Robo::Robo(std::string const target) : AForm(target, 72, 45), target(target), sign(false), grade(72), exe(45)
{
	return ;
}

Robo::Robo(Robo const &src) : AForm(src.getTarget(), src.getGrade(), src.getExe()), target(src.getTarget()), sign(src.getSign()), grade(src.getGrade()), exe(src.getExe())
{
	return ;
}

Robo &Robo::operator=(Robo const &src)
{
	this->sign = src.getSign();
	return (*this);
}

Robo::~Robo()
{
	return ;
}

std::string const Robo::getTarget() const
{
	return (this->target);
}

bool	Robo::getSign() const
{
	return (this->sign);
}

int	Robo::getGrade() const
{
	return (this->grade);
}

int	Robo::getExe() const
{
	return (this->exe);
}

bool randomBool()
{
    int g = std::rand();
    return (g % 2);
}

void	Robo::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->exe)
		throw Robo::GradeTooLowException();
	else
		this->percentage();
}

void	Robo::percentage(void) const
{
	std::cout << "\033[1;32mDRRRILL" << std::endl;
	if (randomBool() == true)
		std::cout << this->target << " has been robotomized successfully\033[0m" << std::endl;
	else
		std::cout << "on " << this->target << " the robotomy failed\033[0m" << std::endl;
}