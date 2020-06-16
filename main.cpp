#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Employee.h"
#include"SalariedEmployee.h"
#include"CommissionEmployee.h"
#include"BasePlusCommissionEmployee.h"
using namespace std;
void virtualviaPointer(const Employee* const emp);
void virtualviaReference(const Employee& empr);
int main()
{
	cout << fixed << setprecision(2);
	try
	{
		//create derived-class objects
		SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800.0);
		CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
		BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

		
		/*Manipulation objects with static binding*/
		cout << "Employee processed individually using static binding:\n\n";
		//output each Empoyee's infromation and earnings using name handles
		salariedEmployee.print();
		cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
		commissionEmployee.print();
		cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
		basePlusCommissionEmployee.print();
		cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";
		

		/****************************************************************************/

		/*Manipulation objects with dynamic binding*/
		//create vector of three base-class pointers
		vector<Employee*> employee(3);
		employee[0] = &salariedEmployee;
		employee[1] = &commissionEmployee;
		employee[2] = &basePlusCommissionEmployee;
		cout << "Employee processed polymorphically via dynamic binding:\n\n";
		cout << "Virtual function calls made off base-class pointers:\n\n";
		for (int i = 0; i <= 2; i++)
		{
			virtualviaPointer(employee[i]);
		}
		cout << "Virtual function calls made off base-class reference:\n\n";
		for (int i = 0; i <= 2; i++)
		{
			virtualviaReference(*(employee[i]));
		}
		/*Manipulation Using euntime type information(RTTI)*/
		vector<Employee *> newemployee(3);
		newemployee[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 800);
		newemployee[1] = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, 0.06);
		newemployee[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, 0.04, 300);
		Employee* employeePtr = nullptr;
		for (int i = 0; i < newemployee.size(); i++)
		{
			employeePtr = newemployee[i];
			employeePtr->print();//output employee information
			cout << endl;
			//downcast pointer
			BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>(employeePtr);
			//determine whether element points to a BasePlusCommissionEmployee
			if (derivedPtr != nullptr)//true for "is a" relationship
			{
				double oldBaseSalary = derivedPtr->getBaseSalary();
				cout << "old base salary: $" << oldBaseSalary << endl;
				derivedPtr->setBaseSalary(1.10*oldBaseSalary);
				cout << "new base salary with 10% increase is: $"
					<< derivedPtr->getBaseSalary() << endl;
			}
			cout << "earned $" << employeePtr->earnings() << "\n\n";
			
		}
		for (int i = 0; i < newemployee.size(); i++)
		{
			employeePtr = newemployee[i];
			cout << "deleting object of " << typeid(*employeePtr).name() << endl;
			delete employeePtr;
		}
	}
	catch(invalid_argument& i)
	{
		cout << i.what();
	}
	return 0;
}
void virtualviaPointer(const Employee* const emp)
{
	emp->print();
	cout << "\nearned $" << emp->earnings() << "\n\n";
}
void virtualviaReference(const Employee& empr)
{
	empr.print();
	cout << "\nearned $" << empr.earnings() << "\n\n";
}
