#include "Food.h"

Food::Food() : Chain(), numOfImporters(0) {}

Food::Food(string name, int num) : Chain(name), numOfImporters(num) {}

Food::Food(const Food& obj) : Chain(obj), numOfImporters(obj.numOfImporters) {}

void Food::print()
{
	cout << "Number of importers: " << this->numOfImporters << endl;
}

Food::~Food()
{
}
