#include<iostream>
#include<string>
#include "BasePlusCommissionEmployee.h"
using namespace std;
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first_ref, const std::string& last_ref,
	const std::string& ssn_ref, double sales, double rate, double salary) :
	CommissionEmployee(first_ref, last_ref, ssn_ref, sales, rate)
{
	setBaseSalary(salary);
}
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary > 0.0)
	{
		base_salary_ = salary;
		return;
	}
	else
	{
		throw invalid_argument("base salary must > 0"); 
	}
}
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return base_salary_;
}
double BasePlusCommissionEmployee::earnings() const
{
	return getBaseSalary() + CommissionEmployee::earnings();
}
void BasePlusCommissionEmployee::print() const
{
	cout << "base-salaried ";
	CommissionEmployee::print();
	cout << "; base salary: " << getBaseSalary();
}
