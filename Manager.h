#ifndef __MANAGER_H
#define __MANAGER_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class Manager : public Employee
{
private:
	int LevelOfManagement;
public:
	Manager();
	Manager(string, int, int, float, int);
	Manager(const Manager&);
	~Manager();
	float getSalary() { return LevelOfManagement * Employee::getBasic() * Employee::getJobPer(); };
};

#endif