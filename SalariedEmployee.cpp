#include<iostream>
#include<string>
#include "SalariedEmployee.h"
using namespace std;
SalariedEmployee::SalariedEmployee(const std::string& first_ref, const std::string& last_ref,
	const std::string& ssn_ref, double salary) :Employee(first_ref, last_ref, ssn_ref) 
{
	setWeeklySalary(salary);
}
void SalariedEmployee::setWeeklySalary(double salary)
{
	if (salary >= 0)
	{
		weekly_salary_ = salary;
		return;
	}
	else
	{
		throw invalid_argument("Weekly salary must be >= 0.0");
	}
}
double SalariedEmployee::getWeeklySalary() const
{
	return weekly_salary_;
}
double SalariedEmployee::earnings() const
{
	return weekly_salary_;
}
void  SalariedEmployee::print() const
{
	cout << "salaried employee: ";
	Employee::print();
	cout << "\nweekly salary:" << getWeeklySalary();
}