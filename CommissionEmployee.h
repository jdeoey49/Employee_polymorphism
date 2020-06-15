#pragma once
#include"Employee.h"
#include<string>
class CommissionEmployee:public Employee
{
public:
	CommissionEmployee(const std::string& first_ref, const std::string last_ref,
		const std::string ssn_ref, double sales=0.0, double rate=0.0);
	virtual ~CommissionEmployee(){}
	void setCommissionRate(double rate);
	double getCommissionRate() const;
	void setGrossSales(double sales);
	double getGrossSales() const;
	virtual double earnings() const override;
	virtual void print() const override;
private:
	double gross_sales_;
	double commission_rate_;
};

