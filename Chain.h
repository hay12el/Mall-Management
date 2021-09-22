#ifndef __CHAIN_H
#define __CHAIN_H

#include <iostream>
#include <string>
#include "Store.h"
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
class Store;

class Chain
{
private:
	string chaiName;
	int storeAmount;
	Store** stores;
	int EmployeeAmount;
	Employee** employeeList;
public:
	Chain();
	Chain(string);
	Chain(const Chain&);
	virtual ~Chain();
	void addStore(int);
	string getName() { return chaiName; }
	void addEmployee();
	void Shopping(int, float, int);
	void cancle(int, float, int);
	void print();
	void printClothing(Chain* ptr);
	void printFood(Chain* ptr);
	void printsaleries();
	void printsaleriesShop(int);
	void printEmployee(int);
	void printShop(int);
};
#endif