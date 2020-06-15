#pragma once
#include<string>
//This is an abstract base-class
class Employee
{
public:
	Employee(const std::string& first_ref, const std::string& last_ref, const std::string& ssnref):
		first_name_(first_ref),last_name_(last_ref),ssn_(ssnref){}
	
	virtual ~Employee() {}//virtual destructor -> make any other destructors in the hierachy virtual as well
	virtual double earnings() const=0;//pure virtual function (Does not have implementation)
	virtual void print() const;//virtual but not pure virtual (Have default implementation)

	void setFirstName(const std::string&); // set first name
	std::string getFirstName() const; // return first name
	void setLastName(const std::string&); // set last name
	std::string getLastName() const; // return last name
	void setSocialSecurityNumber(const std::string&); // set SSN
	std::string getSocialSecurityNumber() const; // return SSN

private:
	std::string first_name_;
	std::string last_name_;
	std::string ssn_;
};

