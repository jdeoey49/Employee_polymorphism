#pragma once
#include"CommissionEmployee.h"
#include<string>
class BasePlusCommissionEmployee:public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const std::string& first_ref, const std::string& last_ref,
		const std::string& ssn_ref, double sales = 0.0, double rate = 0.0, double salary = 0.0);
	virtual ~BasePlusCommissionEmployee(){}
	void setBaseSalary(double salary);
	double getBaseSalary() const;
	virtual double earnings() const override;
	virtual void print() const override;
private:
	double base_salary_;
};

