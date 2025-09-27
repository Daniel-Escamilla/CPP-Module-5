/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:20:44 by descamil          #+#    #+#             */
/*   Updated: 2025/09/27 13:36:28 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);

		Bureaucrat(std::string const name, int grade);

		std::string			getName() const;
		int					getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				GradeTooHighException(const GradeTooHighException &copy);
				~GradeTooHighException() throw();
				GradeTooHighException &operator=(const GradeTooHighException &copy);
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException(const GradeTooLowException &copy);
				~GradeTooLowException() throw();
				GradeTooLowException &operator=(const GradeTooLowException &copy);
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
