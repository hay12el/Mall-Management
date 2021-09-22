#include "Store.h"

Store::Store() : storeId(0), chainName(""), employeeAmount(0), employeeList(nullptr) {}

Store::Store(int id, string chain) : storeId(id), chainName(chain), employeeAmount(0), employeeList(nullptr) {}

Store::Store(const Store& obj) : storeId(obj.storeId), chainName(obj.chainName)
{
	if (obj.employeeAmount > 0)
	{
		employeeAmount = obj.employeeAmount;
		employeeList = new Employee*[employeeAmount];
		for (int i = 0; i < this->employeeAmount; i++)
			employeeList[i] = obj.employeeList[i];
	}
	else
	{
		employeeAmount = 0;
		employeeList = nullptr;
	}
}

void Store::addEmployee(string name, int id, int percent, float salary, char type)
{
	if (this->employeeAmount != 0)
	{
		int i;
		Employee** temp = new Employee * [employeeAmount+1];
		for (i = 0; i < employeeAmount; i++)
		{
			temp[i] = employeeList[i];
		}
		employeeAmount += 1;

		switch (type)
		{
		case('A'):
			temp[i] = new Manager(name, id, percent, salary, 1);
			break;
		case('B'):
			temp[i] = new Senior(name, id, percent, salary);
			break;
		case('C'):
			temp[i] = new Junior(name, id, percent, salary);
			break;
		case('D'):
			temp[i] = new Cashier(name, id, percent, salary);
			break;
		}
		delete[] employeeList;
		employeeList = temp;
		cout << "added!" << endl;
	}
	else
	{
		employeeAmount = 1;
		employeeList = new Employee * [1];

		switch (type)
		{
		case('A'):
			employeeList[0] = new Manager(name, id, percent, salary, 1);
			break;
		case('B'):
			employeeList[0] = new Senior(name, id, percent, salary);
			break;
		case('C'):
			employeeList[0] = new Junior(name, id, percent, salary);
			break;
		case('D'):
			employeeList[0] = new Cashier(name, id, percent, salary);
			break;
		}
		cout << "added!" << endl;
	}
}

void Store::makePurchse(float sum, int id)
{
	for (int i = 0; i < this->employeeAmount; i++)
	{
		if (employeeList[i]->getId() == id)
		{
			if (typeid(employeeList[i]) == typeid(Junior))
				employeeList[i]->juniorFunc(employeeList[i], sum);
			if (typeid(employeeList[i]) == typeid(Cashier))
				employeeList[i]->CashierFunc(employeeList[i]);
		}
	}
}

void Store::cancle(float sum, int id)
{
	for (int i = 0; i < this->employeeAmount; i++)
	{
		if (employeeList[i]->getId() == id)
		{
			if (typeid(employeeList[i]) == typeid(Junior))
				employeeList[i]->juniorFuncancle(employeeList[i], sum);
			if (typeid(employeeList[i]) == typeid(Cashier))
				employeeList[i]->CashierFuncancle(employeeList[i]);
		}
	}
}

void Store::print()
{
	cout << "Store ID: " << this->storeId << endl;
}

void Store::printStore()
{
	cout << "Number of employees: " << this->employeeAmount << endl;
	for (int i = 0; i < this->employeeAmount; i++)
	{
		cout << "(" << i + 1 << ")";
		employeeList[i]->print();
	}
}

void Store::printSalaries()
{
	float sum = 0;
	for (int i = 0; i < this->employeeAmount; i++)
	{
		if (typeid(*employeeList[i]) == typeid(Cashier))
		{
			sum += employeeList[i]->cashierSalary(employeeList[i]);
		}
		else if (typeid(*employeeList[i]) == typeid(Junior))
		{
			sum += employeeList[i]->juniorSalary(employeeList[i]);
		}
		else if (typeid(*employeeList[i]) == typeid(Senior))
		{
			sum += employeeList[i]->seniorSalary(employeeList[i]);
		}
		else if (typeid(*employeeList[i]) == typeid(Manager))
		{
			sum += employeeList[i]->managerSalary(employeeList[i]);
		}
	}
	cout << "Sum of STORE salaries: " << sum << endl;
}


Store::~Store()
{
	delete[] employeeList;
}