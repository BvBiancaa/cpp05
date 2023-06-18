/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:37:43 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:02:31 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Presidential : public AForm
{
	private:
		std::string const target;
		bool sign;
		int const grade;
		int const exe;
	public:
		Presidential();
		Presidential(std::string const target);
		Presidential(Presidential const &src);
		Presidential &operator=(Presidential const &src);
		virtual ~Presidential();
		std::string const getTarget() const;
		bool	getSign() const;
		int	getGrade() const;
		int	getExe() const;
		void	execute(Bureaucrat const & executor) const;
		void	pardon(Bureaucrat const & executor) const;
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