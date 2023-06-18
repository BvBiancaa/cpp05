/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:32 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:14:14 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(NULL));

	Intern unknown;
 	Presidential *one;
	Shrubbery *two;
	Robo *three;
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	
	one = (Presidential *)unknown.makeForm("presidential pardon", "target");
	two = (Shrubbery *)unknown.makeForm("shrubbery creation", "target");
	three = (Robo *)unknown.makeForm("robotomy request", "target");
	std::cout << *one << std::endl;
	std::cout << *two << std::endl;
	std::cout << *three << std::endl;

	bureaucrat->signForm(*one);
	bureaucrat->executeForm(*one);

	delete one;
	delete two;
	delete three;
	delete bureaucrat;
}