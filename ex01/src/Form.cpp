/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:52:34 by descamil          #+#    #+#             */
/*   Updated: 2025/09/27 17:22:15 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(std::string name, int SignGrade, int ExecuteGrade)
	: _name(name), _gradeToSign(SignGrade), _gradeToExecute(ExecuteGrade)
{
	_signed = false;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _signed(copy._signed)
{
	
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high to sign!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low to sign!");
}

// GradeTooHighException canonical implementations
Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &copy)
{
	(void)copy;
}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException &copy)
{
	(void)copy;
	return *this;
}

// GradeTooLowException canonical implementations
Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &copy)
{
	(void)copy;
}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &copy)
{
	(void)copy;
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", signed: " << (form.isSigned() ? "true" : "false") 
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return (out);
}