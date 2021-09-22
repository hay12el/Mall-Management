#ifndef __CASHIER_H
#define __CASHIER_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Employee;

class Cashier : public Employee
{
private:
	int actions;
public:
	Cashier();
	Cashier(string, int, int, float);
	Cashier(const Cashier&);
	void addPurchase() { actions++; }
	void cancle() { actions--; }
	~Cashier();
	float getSalary() { return Employee::getJobPer() * (Employee::getBasic() + this->actions); };
};

#endif