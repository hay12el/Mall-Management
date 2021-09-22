#include "Manager.h"

Manager::Manager() : Employee(), LevelOfManagement(0)
{
}

Manager::Manager(string nameI, int idI, int job, float salary, int level) : Employee(nameI, idI, job, salary), LevelOfManagement(level) {}

Manager::Manager(const Manager& obj) : Employee(obj)
{
	LevelOfManagement = obj.LevelOfManagement;
}

Manager::~Manager()
{
}
