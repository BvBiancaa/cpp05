/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:16:07 by bmuni             #+#    #+#             */
/*   Updated: 2023/04/11 21:32:38 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return (*this);
}

AForm *init(std::string type, std::string name)
{
	if (type == "shrubbery creation")
		return (new Shrubbery(name));
	else if (type == "robotomy request")
		return (new Robo(name));
	return (new Presidential(name));
}

AForm* Intern::makeForm(std::string type, std::string name)
{
	std::string	types[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (type == types[i])
		{
			std::cout << "Intern creates " << type << std::endl;
			return (init(types[i], name));
		}
	}
	std::cout << "Intern can't create " << type << ", type doesn't exist!" << std::endl;
	return (new Shrubbery("ERROR"));
}