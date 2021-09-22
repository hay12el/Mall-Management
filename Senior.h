#ifndef __SENIOR_H
#define __SENIOR_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "Junior.h"

using namespace std;

class Senior : public Junior
{
private:
	int cancleAmount;
	float* cancled;
public:
	Senior();
	Senior(string, int, int, float);
	Senior(const Senior&);
	~Senior();
	float getSalary() { return 1.5 * (Junior::getSalary()); };
};

#endif