#include "Senior.h"

Senior::Senior() : Junior(), cancled(nullptr), cancleAmount(0)
{}

Senior::Senior(string name, int id, int job, float basic) : Employee(name, id, job, basic), Junior() , cancled(nullptr), cancleAmount(0) {}

Senior::Senior(const Senior& obj) : Junior(obj), cancled(obj.cancled), cancleAmount(0){}

Senior::~Senior()
{
	if (cancled != nullptr)
		delete[] cancled;
	Junior::~Junior();
}
