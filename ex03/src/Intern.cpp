/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-escamilla <daniel-escamilla@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:30:55 by daniel-esca       #+#    #+#             */
/*   Updated: 2025/05/13 14:45:24 by daniel-esca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

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