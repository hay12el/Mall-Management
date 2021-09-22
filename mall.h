#ifndef __MALL_H
#define __MALL_H

#include <iostream>
#include <string>
#include "Employee.h"
#include "Junior.h"
#include "Manager.h"
#include "Senior.h"
#include "Cashier.h"
#include "Chain.h"
#include "Clothing.h"
#include "Food.h"
#include "Store.h"

#define ChainsAmount 3

using namespace std;

class Employee;
class Junior;
class Manager;
class Senior;
class Cashier;
class Chain;
class Clothing;
class Food;
class Store;

class Mall {
private:
	Chain** chains;
public:
	Mall();
	~Mall();
	void menu();
	void addShop();
	void addEmployee();
	void shopping();
	void returnItem();
	void printChain();
	void printSalaryChain();
	void printSalaryShop();
	void printShop();
	void printEmployee();
};

#endif