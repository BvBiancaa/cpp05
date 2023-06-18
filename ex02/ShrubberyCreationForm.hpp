/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:52:08 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 17:11:07 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Shrubbery : public AForm
{
	private:
		const std::string target;
		bool sign;
		const int grade;
		const int exe;
	public:
	Shrubbery();
	Shrubbery(std::string const target);
	Shrubbery(Shrubbery const &src);
	Shrubbery &operator=(Shrubbery const &src);
	virtual ~Shrubbery();
	std::string const getTarget() const;
	bool	getSign() const;
	int	getGrade() const;
	int	getExe() const;
	void	execute(Bureaucrat const &executor) const;
	void	draw(void) const;
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