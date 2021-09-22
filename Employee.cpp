#include "Junior.h"
#include "Senior.h"
#include "Cashier.h"
#include "Employee.h"
#include "Manager.h"

Employee::Employee() : name(" "), id(0), JobPercentage(0), basicSalary(0){}

Employee::Employee(string nameI, int idI, int jobI, float salary) : name(nameI), id(idI), JobPercentage(jobI), basicSalary(salary){}

Employee::Employee(const Employee& obj)
{
	name = obj.name;
	id = obj.id;
	JobPercentage = obj.JobPercentage;
	basicSalary = obj.basicSalary;
}

void Employee::juniorFunc(Employee* ptr, float sum)
{
	Junior* help;
	help = dynamic_cast<Junior*>(ptr);
	if (help != nullptr)
		help->addPurchase(sum);
}

void Employee::print()
{
	cout << "Name: " << this->name << ", ID: " << this->id<<", Job: ";
	if (typeid(*this) == typeid(Cashier))
	{
		cout << "Cashier.";
	}
	if (typeid(*this) == typeid(Junior))
	{
		cout << "Junior.";
	}
	if (typeid(*this) == typeid(Senior))
	{
		cout << "Senior.";
	}
	if (typeid(*this) == typeid(Manager))
	{
		cout << "Manager.";
	}
	cout << endl;
}

void Employee::juniorFuncancle(Employee* ptr, float sum)
{
	Junior* help;
	help = dynamic_cast<Junior*>(ptr);
	if (help != nullptr)
		help->cancle(sum);
}

void Employee::CashierFunc(Employee* ptr)
{
	Cashier* help;
	help = dynamic_cast<Cashier*>(ptr);
	if (help != nullptr)
		help->addPurchase();
}

void Employee::CashierFuncancle(Employee* ptr)
{
	Cashier* help;
	help = dynamic_cast<Cashier*>(ptr);
	if (help != nullptr)
		help->cancle();
}

float Employee::cashierSalary(Employee* ptr)
{
	Cashier* help;
	help = dynamic_cast<Cashier*>(ptr);
	if(help != nullptr)
		return help->getSalary();
	delete help;
}

float Employee::managerSalary(Employee* ptr)
{
	Manager* help;
	help = dynamic_cast<Manager*>(ptr);
	if (help != nullptr)
		return help->getSalary();
	delete help;
}

float Employee::juniorSalary(Employee* ptr)
{
	Junior* help;
	help = dynamic_cast<Junior*>(ptr);
	if (help != nullptr)
		return help->getSalary();
	delete help;
}

float Employee::seniorSalary(Employee* ptr)
{
	Senior* help;
	help = dynamic_cast<Senior*>(ptr);
	if (help != nullptr)
		return help->getSalary();
	delete help;
}

Employee::~Employee(){}
