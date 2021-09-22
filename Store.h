#ifndef __STORE_H
#define __STORE_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "Employee.h"
#include "Junior.h"
#include "Manager.h"
#include "Senior.h"
#include "Cashier.h"

using namespace std;

class Employee;
class Junior;
class Manager;
class Senior;
class Cashier;

class Store {
private:
	int storeId;
	string chainName;
	int employeeAmount;
	Employee** employeeList;
public:
	Store();
	Store(int, string);
	Store(const Store&);
	void addEmployee(string, int, int, float, char);
	int getId() { return this->storeId; }
	void makePurchse(float, int);
	void cancle(float, int);
	void print();
	void printStore();
	void printSalaries();
	~Store();
};



#endif
