/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:32 by bmuni             #+#    #+#             */
/*   Updated: 2023/04/11 16:31:46 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat gigi("gigi", 1);

	std::cout << gigi.getName() << "  " << gigi.getGrade() << std::endl;
	gigi.incrementGrade();
	std::cout << gigi.getName() << "  " << gigi.getGrade() << std::endl;
	gigi.incrementGrade();
	std::cout << gigi << std::endl;
}