/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-escamilla <daniel-escamilla@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:29:00 by daniel-esca       #+#    #+#             */
/*   Updated: 2025/05/13 14:41:34 by daniel-esca      ###   ########.fr       */
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
				const char *what() const throw()
				{
					return ("Intern: Form not found");
				}
		};
};

#endif
