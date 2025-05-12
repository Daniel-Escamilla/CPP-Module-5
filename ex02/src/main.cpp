/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:20:40 by descamil          #+#    #+#             */
/*   Updated: 2025/05/12 19:32:00 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int main()
{
    try
	{
        Form badForm1("F1", 0, 10);
    }
	catch (std::exception &e)
	{
        std::cout << "Error al crear F1: " << e.what() << std::endl;
    }
    try
	{
        Form badForm2("F2", 10, 200);
    }
	catch (std::exception &e)
	{
        std::cout << "Error al crear F2: " << e.what() << std::endl;
    }

	Bureaucrat john("John", 20);
    Bureaucrat sofie("Sofie", 100);
    Form contract("Contract", 40, 30);

    std::cout << "\nEstado inicial de contract:\n" << contract << "\n\n";

    john.signForm(contract);
    std::cout << "Después de John: " << contract << "\n\n";

    sofie.signForm(contract);

    return 0;
}