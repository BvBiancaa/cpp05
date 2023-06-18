/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:38:29 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:02:41 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool sign;
		const int grade;
		const int exe;
	public:
		AForm();
		AForm(std::string const name, int grade, int exe);
		AForm(AForm const &src);
		AForm &operator=(AForm const &src);
		virtual ~AForm();
		std::string const getName() const;
		bool	getSign() const;
		int	getGrade() const;
		int	getExe() const;
		void	beSigned(Bureaucrat bu);
		virtual void	execute(const Bureaucrat &bureaucrat) const = 0;
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

std::ostream& operator<<(std::ostream&os, const AForm&fo);

#endif