#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Junior;
class Senior;
class Cashier;

class Employee
{
private:
	string name;
	int id;
	int JobPercentage;
	float basicSalary;
public:
	Employee();
	Employee(string, int, int, float);
	Employee(const Employee&);
	float getBasic() { return basicSalary; }
	int getJobPer() { return JobPercentage; }
	int getId() { return id; }
	void juniorFunc(Employee* ptr, float);
	void print();
	void juniorFuncancle(Employee* ptr, float);
	void CashierFunc(Employee* ptr);
	void CashierFuncancle(Employee* ptr);
	float cashierSalary(Employee* ptr);
	float managerSalary(Employee* ptr);
	float juniorSalary(Employee* ptr);
	float seniorSalary(Employee* ptr);
	virtual ~Employee();
};

#endif