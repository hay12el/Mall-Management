#ifndef __JUNIOR_H
#define __JUNIOR_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Employee;

class Junior : virtual public Employee
{
private:
	int numOfPurchses;
	float* purchases;
public:
	Junior();
	Junior(string, int, int, float);
	Junior(const Junior&);
	~Junior();
	void addPurchase(float);
	void cancle(float);
	float avg();
	float getSalary() { return (avg() + Employee::getBasic() + numOfPurchses) * Employee::getJobPer(); };
};

#endif