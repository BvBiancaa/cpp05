/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:38:29 by bmuni             #+#    #+#             */
/*   Updated: 2023/04/11 16:46:53 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int grade;
		const int exe;
	public:
		Form();
		Form(std::string const name, int grade, int exe);
		Form(Form const &src);
		Form &operator=(Form const &src);
		~Form();
		std::string const getName() const;
		bool	getSign() const;
		int	getGrade() const;
		int	getExe() const;
		void	beSigned(Bureaucrat bu);
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
};

std::ostream& operator<<(std::ostream&os, const Form&fo);

#endif