#ifndef __CLOTHING_H
#define __CLOTHING_H

#include <iostream>
#include <string>
#include "Chain.h"
#include "Store.h"
#include "Employee.h"

using namespace std;

class Clothing : public Chain{
private:
	string importer;
public:
	Clothing();
	Clothing(string, string);
	Clothing(const Clothing&);
	void print();
	~Clothing();
};

#endif