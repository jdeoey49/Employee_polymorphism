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