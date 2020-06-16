#pragma once
#include"Employee.h"
#include<string>
class SalariedEmployee:public Employee
{
public:
	SalariedEmployee(const std::string& first_ref, const std::string& last_ref,
		const std::string& ssn_ref, double salary = 0.0);
	virtual ~SalariedEmployee(){}
	void setWeeklySalary(double salary);
	double getWeeklySalary() const;
	virtual double earnings() const override;
	virtual void print() const override;
private:
	double weekly_salary_;
};

