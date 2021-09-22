#include "Cashier.h"

Cashier::Cashier() : Employee(), actions(0) {}

Cashier::Cashier(string nameI, int idI, int job, float salary): Employee(nameI, idI, job, salary) , actions(0) {}

Cashier::Cashier(const Cashier& obj) : Employee(obj) , actions(obj.actions) {}

Cashier::~Cashier()
{
}
