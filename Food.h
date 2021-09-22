#ifndef __FOOD_H
#define __FOOD_H

#include <iostream>
#include <string>
#include "Chain.h"
#include "Store.h"
#include "Employee.h"

using namespace std;

class Food : public Chain {
private:
	int numOfImporters;
public:
	Food();
	Food(string, int);
	Food(const Food&);
	void print();
	~Food();
};

#endif
