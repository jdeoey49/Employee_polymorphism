#include<iostream>
#include<string>
#include "CommissionEmployee.h"
using namespace std;
CommissionEmployee::CommissionEmployee(const std::string& first_ref, const std::string last_ref,
	const std::string ssn_ref, double sales, double rate):Employee(first_ref, last_ref, ssn_ref)	
{
	setGrossSales(sales);
	setCommissionRate(rate);
}
void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate >= 0.0 && rate <= 1.0)
	{
		commission_rate_ = rate;
		return;
	}
	else
	{
		throw invalid_argument("commission rate must be between 0.0 and 1.0");
	}
}
double CommissionEmployee::getCommissionRate() const
{
	return commission_rate_;
}
void CommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
		gross_sales_ = sales;
	else
	{
		throw invalid_argument("gross sales must be >0");
	}
}
double CommissionEmployee::getGrossSales() const
{
	return gross_sales_;;
}
double CommissionEmployee::earnings() const
{
	return gross_sales_ * commission_rate_;
}
void CommissionEmployee::print() const
{
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales()<<"; commission rate: "
		<<getCommissionRate();
}

