/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-escamilla <daniel-escamilla@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:20:40 by descamil          #+#    #+#             */
/*   Updated: 2025/05/13 01:54:50 by daniel-esca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned>(std::time(0)));

	{
		try { ShrubberyCreationForm f("t"); }
		catch (std::exception &e) { std::cout << "Error Shrubbery: " << e.what() << "\n"; }

		try { RobotomyRequestForm f("t"); }
		catch (std::exception &e) { std::cout << "Error Robotomy: " << e.what() << "\n"; }

		try { PresidentialPardonForm f("t"); }
		catch (std::exception &e) { std::cout << "Error Pardon: " << e.what() << "\n"; }
	}

	try
	{
		Bureaucrat low("Alice", 1500);
		Bureaucrat mid("Bob", 70);
		Bureaucrat high("Carol", 1);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");

		std::cout << "\n"
			<< shrub << "\n"
			<< robot << "\n"
			<< pardon << "\n\n";

		low.signAForm(shrub);
		low.signAForm(robot);
		low.signAForm(pardon);

		std::cout << "\n";

		mid.signAForm(shrub);
		mid.signAForm(robot);
		mid.signAForm(pardon);

		std::cout << "\n";
		high.signAForm(shrub);
		high.signAForm(robot);
		high.signAForm(pardon);


		{
			std::cout << "\n";
			try { high.executeAForm(ShrubberyCreationForm("garden")); }
			catch (std::exception &e) { std::cout << e.what() << "\n"; }
		}
		std::cout << "\n";
		mid.executeAForm(pardon);
		std::cout << "\n";
		high.executeAForm(shrub);
		high.executeAForm(robot);
		high.executeAForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	return (0);
}
