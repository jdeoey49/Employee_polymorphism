#include<iostream>
#include "Employee.h"
using namespace std;
void Employee::print() const
{
	cout << getFirstName() << ' ' << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber();
}
void Employee::setFirstName(const std::string& first) // set first name
{
	first_name_ = first;
}
std::string Employee::getFirstName() const // return first name
{
	return first_name_;
}
void Employee::setLastName(const std::string& last) // set last name
{
	last_name_ = last;
}
std::string Employee::getLastName() const // return last name
{
	return last_name_;
}
void Employee::setSocialSecurityNumber(const std::string& ssn) // set SSN
{
	ssn_ = ssn;
}
std::string Employee::getSocialSecurityNumber() const // return SSN
{
	return ssn_;
}