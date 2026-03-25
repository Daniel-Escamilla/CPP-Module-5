/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:55 by daniel-esca       #+#    #+#             */
/*   Updated: 2025/09/27 17:23:10 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) { (void)copy; return (*this); }

AForm *Intern::createRobotomyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createShrubberyCreation(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(Intern::*formFunctions[3])(const std::string &) = {
		&Intern::createRobotomyRequest,
		&Intern::createPresidentialPardon,
		&Intern::createShrubberyCreation
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formFunctions[i])(target);
		}
	}
	throw FormNotFoundException();
}

Intern::FormNotFoundException::FormNotFoundException() {}

Intern::FormNotFoundException::FormNotFoundException(const FormNotFoundException &copy)
{
	(void)copy;
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

Intern::FormNotFoundException &Intern::FormNotFoundException::operator=(const FormNotFoundException &copy)
{
	(void)copy;
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Intern: Form not found");
}