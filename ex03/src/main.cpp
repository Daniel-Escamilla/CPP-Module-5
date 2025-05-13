/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-escamilla <daniel-escamilla@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:20:40 by descamil          #+#    #+#             */
/*   Updated: 2025/05/13 15:12:56 by daniel-esca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	Intern	someRandomIntern;
	AForm*	form;

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete (form);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		form = someRandomIntern.makeForm("presidential pardon", "Target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete (form);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
