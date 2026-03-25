/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:52:34 by descamil          #+#    #+#             */
/*   Updated: 2025/05/12 19:26:42 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(std::string name, int SignGrade, int ExecuteGrade)
	: _name(name), _gradeToSign(SignGrade), _gradeToExecute(ExecuteGrade)
{
	_signed = false;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _signed(copy._signed)
{
	
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("the grade is too high to sign!");
}

AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::GradeTooHighException(const GradeTooHighException &copy)
{
	(void)copy;
}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooHighException &AForm::GradeTooHighException::operator=(const GradeTooHighException &copy)
{
	(void)copy;
	return *this;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("the grade is too low to sign!");
}

AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::GradeTooLowException(const GradeTooLowException &copy)
{
	(void)copy;
}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::GradeTooLowException &AForm::GradeTooLowException::operator=(const GradeTooLowException &copy)
{
	(void)copy;
	return *this;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("the form is not signed!");
}

AForm::FormNotSignedException::FormNotSignedException() {}

AForm::FormNotSignedException::FormNotSignedException(const FormNotSignedException &copy)
{
	(void)copy;
}
AForm::FormNotSignedException::~FormNotSignedException() throw() {}

AForm::FormNotSignedException &AForm::FormNotSignedException::operator=(const FormNotSignedException &copy)
{
	(void)copy;
	return *this;
}

const char *AForm::GradeTooLowExecuteException::what() const throw()
{
	return ("the grade is too low to execute!");
}

AForm::GradeTooLowExecuteException::GradeTooLowExecuteException() {}

AForm::GradeTooLowExecuteException::GradeTooLowExecuteException(const GradeTooLowExecuteException &copy)
{
	(void)copy;
}
AForm::GradeTooLowExecuteException::~GradeTooLowExecuteException() throw() {}

AForm::GradeTooLowExecuteException &AForm::GradeTooLowExecuteException::operator=(const GradeTooLowExecuteException &copy)
{
	(void)copy;
	return *this;
}

const char *AForm::GradeTooHighExecuteException::what() const throw()
{
	return ("the grade is too high to execute!");
}

AForm::GradeTooHighExecuteException::GradeTooHighExecuteException() {}

AForm::GradeTooHighExecuteException::GradeTooHighExecuteException(const GradeTooHighExecuteException &copy)
{
	(void)copy;
}
AForm::GradeTooHighExecuteException::~GradeTooHighExecuteException() throw() {}

AForm::GradeTooHighExecuteException &AForm::GradeTooHighExecuteException::operator=(const GradeTooHighExecuteException &copy)
{
	(void)copy;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << ", signed: " << (AForm.isSigned() ? "true" : "false") 
		<< ", grade required to sign: " << AForm.getGradeToSign()
		<< ", grade required to execute: " << AForm.getGradeToExecute();
	return (out);
}

void AForm::checkExecutability(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowExecuteException();
}