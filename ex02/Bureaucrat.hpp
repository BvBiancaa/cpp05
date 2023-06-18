/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:31:20 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:02:36 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{	
					return ("Grade too low");
				}
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm not signed");
				}
		};
		Bureaucrat();
		Bureaucrat(std::string const n, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &src);
		~Bureaucrat();
		std::string const getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form);
};

std::ostream& operator<<(std::ostream&os, const Bureaucrat&bu);

#endif