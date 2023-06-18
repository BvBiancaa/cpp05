/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:30:21 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:02:27 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Robo : public AForm
{
	private:
		const std::string target;
		bool sign;
		const int grade;
		const int exe;
	public:
		Robo();
		Robo(std::string const target);
		Robo(Robo const &src);
		Robo &operator=(Robo const &src);
		virtual ~Robo();
		std::string const getTarget() const;
		bool	getSign() const;
		int	getGrade() const;
		int	getExe() const;
		void	execute(Bureaucrat const & executor) const;
		void	percentage(void) const;
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm not signed");
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

#endif