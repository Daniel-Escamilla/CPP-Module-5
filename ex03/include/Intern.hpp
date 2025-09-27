/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:29:00 by daniel-esca       #+#    #+#             */
/*   Updated: 2025/09/27 16:44:09 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm	*createRobotomyRequest(const std::string &target);
		AForm	*createShrubberyCreation(const std::string &target);
		AForm	*createPresidentialPardon(const std::string &target);
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		AForm	*makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception
		{

			public:
				FormNotFoundException();
				FormNotFoundException(const FormNotFoundException &copy);
				~FormNotFoundException() throw();
				FormNotFoundException &operator=(const FormNotFoundException &copy);
				const char *what() const throw();
		};
};

#endif
