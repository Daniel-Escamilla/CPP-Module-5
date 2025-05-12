/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-escamilla <daniel-escamilla@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:52:02 by descamil          #+#    #+#             */
/*   Updated: 2025/05/13 01:19:36 by daniel-esca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

class Bureaucrat;

class AForm
{
	private:
		std::string	const	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_signed;
	public:
		AForm(std::string name, int SignGrade, int ExecuteGrade);
		~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);

		std::string getName() const;
		bool		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			checkExecutability(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowExecuteException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooHighExecuteException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
