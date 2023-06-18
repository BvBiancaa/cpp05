/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:32 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:13:22 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	srand(time(NULL));

 	Bureaucrat	rando("falzo", -90);
	Bureaucrat	rando2("falzopp", 200);
	Bureaucrat	errup("gigino", 149);

	std::cout << rando;
	std::cout << rando2;
	std::cout << errup;
	errup.decrementGrade();
	std::cout << errup;
	errup.decrementGrade();
	std::cout << errup;

	AForm		*shrub = new Shrubbery("home");
	Bureaucrat	master("gino", 1);
	Bureaucrat	miao("mariangelo", 140);
	
	master.executeForm(*shrub);
	master.signForm(*shrub);
	std::cout << *shrub;
	std::cout << master;
	std::cout << miao;
	master.executeForm(*shrub);
	miao.executeForm(*shrub);
	delete shrub;

	AForm		*robo = new Robo("Lobotomy?");
	Bureaucrat	prio("ciccina", 1);

	prio.executeForm(*robo);
	prio.signForm(*robo);
	prio.executeForm(*robo);
	prio.executeForm(*robo);
	prio.executeForm(*robo);
	delete robo;
	
	AForm		*presi = new Presidential("pina");
	Bureaucrat	pio("Lucie", 6);

	pio.executeForm(*presi);
	pio.signForm(*presi);
	pio.executeForm(*presi);
	pio.incrementGrade();
	pio.executeForm(*presi);
	delete presi;

	AForm	*mix1 = new Shrubbery("one");
	AForm	*mix2 = new Robo("two");
	AForm	*mix3 = new Presidential("three");
	Bureaucrat sad("useless", 150);
	
	prio.signForm(*mix1);
	prio.signForm(*mix2);
	prio.signForm(*mix3);
	prio.executeForm(*mix1);
	prio.executeForm(*mix2);
	prio.executeForm(*mix3);
	sad.executeForm(*mix1);
	sad.signForm(*mix1);
	sad.signForm(*mix2);
	sad.signForm(*mix3);
	sad.executeForm(*mix1);
	sad.executeForm(*mix2);
	sad.executeForm(*mix3);
	delete mix1;
	delete mix2;
	delete mix3;
	return (0);
}