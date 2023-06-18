/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:32 by bmuni             #+#    #+#             */
/*   Updated: 2023/04/11 21:42:36 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	Bureaucrat gigi("gigi", 20);

	std::cout << gigi.getName() << "  " << gigi.getGrade() << std::endl;
	gigi.incrementGrade();
	std::cout << gigi << std::endl;

	Form *gianni = new Form();
	Form paolo("paolo", 1, 1);
	paolo.beSigned(gigi);
	gianni->beSigned(gigi);
	delete gianni;
}