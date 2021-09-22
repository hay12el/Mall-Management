#include "Chain.h"
#include "Clothing.h"
#include "Food.h"

Chain::Chain() : chaiName(""), storeAmount(0), stores(nullptr) , EmployeeAmount(0), employeeList(nullptr){}

Chain::Chain(string name) : chaiName(name), storeAmount(0), stores(nullptr), EmployeeAmount(0), employeeList(nullptr) {}

Chain::Chain(const Chain& obj) : chaiName(obj.chaiName)
{
	if (obj.storeAmount > 0)
	{
		storeAmount = obj.storeAmount;
		for (int i = 0; i < storeAmount; i++)
			stores[i] = obj.stores[i];
	}
	else
	{
		storeAmount = 0;
		stores = nullptr;
	}

	if (obj.EmployeeAmount > 0)
	{
		EmployeeAmount = obj.EmployeeAmount;
		for (int i = 0; i < EmployeeAmount; i++)
			employeeList[i] = obj.employeeList[i];
	}
	else
	{
		EmployeeAmount = 0;
		employeeList = nullptr;
	}
}

Chain::~Chain()
{
	if (stores != nullptr)
		delete[] stores;
	if (employeeList != nullptr)
		delete[] employeeList;
}

void Chain::addStore(int num)
{
	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == num)
		{
			cout << "allready have that store!" << endl;
			return;
		}
	}
	if (storeAmount == 0)
	{
		storeAmount = 1;
		stores = new Store * [1];
		stores[0] = new Store(num, this->chaiName);
		cout << "Insert done! (" << num << ")" << endl;
	}
	else
	{
		int i;
		storeAmount += 1;
		Store** temp;
		temp = new Store * [storeAmount];
		for (i = 0; i < storeAmount - 1; i++)
			temp[i] = stores[i];
		temp[i] = new Store(num, this->chaiName);
		
		delete[] stores;
		stores = temp;
		cout << "Insert done!(" << num << ")" << endl;
	}
}

void Chain::addEmployee()
{
	bool flag = false;
	string name;
	int id;
	char type = 'E';
	int percent;
	float salary;
	int shopId;
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter ID: ";
	cin >> id;
	while (type < 'A' || type > 'D') {
		cout << "Enter employee type: (A- manager, B- senior, C- junior, D- cashier) ";
		cin	>> type;
	}
	cout << "Enter percent of job: ";
	cin >> percent;
	cout << "Enter basic salary: ";
	cin >> salary;
	cout << "Enter shop ID: ";
	cin >> shopId;

	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == shopId)
		{
			stores[i]->addEmployee(name, id, percent, salary, type);
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "No such store!" << endl;
		return;
	}

	if (EmployeeAmount != 0)
	{
		int i;
		Employee** temp = new Employee * [EmployeeAmount + 1];
		for (i = 0; i < EmployeeAmount; i++)
		{
			temp[i] = employeeList[i];
		}
		EmployeeAmount += 1;

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
		EmployeeAmount = 1;
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

void Chain::Shopping(int shopid, float sum, int empId)
{
	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == shopid)
		{
			stores[i]->makePurchse(sum, empId);
		}
	}
}

void Chain::cancle(int storeId, float sum, int empId)
{
	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == storeId)
		{
			stores[i]->cancle(sum, empId);
		}
	}
}

void Chain::print()
{
	cout << "Chain name: " << this->chaiName << endl;
	cout << "Stores amount: " << this->storeAmount << endl;
	for (int i = 0; i < this->storeAmount; i++)
	{
		cout << "(" << i + 1 << ") ";
		stores[i]->print();
	}
	if (typeid(*this) == typeid(Food))
	{
		this->printFood(this);
	}
	if (typeid(*this) == typeid(Clothing))
	{
		this->printClothing(this);
	}
}

void Chain::printClothing(Chain* ptr)
{
	Clothing* help;

	help = dynamic_cast<Clothing*>(ptr);
	if (help != nullptr)
		help->print();
}

void Chain::printFood(Chain* ptr)
{
	Food* help;

	help = dynamic_cast<Food*>(ptr);
	if (help != nullptr)
		help->print();
}

void Chain::printsaleries()
{
	float sum = 0.0;
	for (int i = 0; i < this->EmployeeAmount; i++)
	{
		if (typeid(*employeeList[i]) == typeid(Cashier))
		{
			sum += employeeList[i]->cashierSalary(employeeList[i]);
		}		
		if (typeid(*employeeList[i]) == typeid(Junior))
		{
			sum += employeeList[i]->juniorSalary(employeeList[i]);
		}		
		if (typeid(*employeeList[i]) == typeid(Senior))
		{
			sum += employeeList[i]->seniorSalary(employeeList[i]);
		}		
		if (typeid(*employeeList[i]) == typeid(Manager))
		{
			sum += employeeList[i]->managerSalary(employeeList[i]);
		}
	}
	cout << "Sum of CHAIN salaries: " << sum << endl;
}

void Chain::printsaleriesShop(int id)
{
	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == id)
		{
			stores[i]->printSalaries();
		}
	}
}

void Chain::printEmployee(int id)
{
	for (int i = 0; i < this->EmployeeAmount; i++)
	{
		if (employeeList[i]->getId() == id)
		{
			employeeList[i]->print();
			return;
		}
	}
}

void Chain::printShop(int id)
{
	for (int i = 0; i < this->storeAmount; i++)
	{
		if (stores[i]->getId() == id)
		{
			stores[i]->printStore();
			return;
		}
	}
}

