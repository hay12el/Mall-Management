#include "mall.h"

Mall::Mall()
{
	chains = new Chain * [ChainsAmount];
	chains[0] = new Clothing("Golbary", "Moshe gabay");
	chains[0]->addStore(65);
	chains[1] = new Food("Super Sal", 4);
	chains[1]->addStore(81);
	chains[1]->addStore(3);
	chains[2] = new Clothing("TNT", "Ruti Sulimani");
	chains[2]->addStore(3);
}

Mall::~Mall()
{
	if (chains != nullptr)
	{
		delete[] chains;
	}
}

void Mall::menu()
{
	while (1)
	{
		fflush(stdin);
		cout << "*************************************************************************" << endl;
		cout << "Welcome. What would you like to do?" << endl;
		cout << "*************************************************************************" << endl;
		cout << "[1] - Add shop." << endl;
		cout << "[2] - Add Employee." << endl;
		cout << "[3] - Shopping." << endl;
		cout << "[4] - Return item." << endl;
		cout << "[5] - Print chain." << endl;
		cout << "[6] - Sum salries chain." << endl;
		cout << "[7] - Sum salaries shop." << endl;
		cout << "[8] - Print shop." << endl;
		cout << "[9] - Print employee." << endl;
		cout << "[10]- Exit." << endl;
		cout << "*************************************************************************" << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			addShop();
			break;
		case 2:
			addEmployee();
			break;
		case 3:
			shopping();
			break;
		case 4:
			returnItem();
			break;
		case 5:
			printChain();
			break;
		case 6:
			printSalaryChain();
			break;
		case 7:
			printSalaryShop();
			break;
		case 8:
			printShop();
			break;
		case 9:
			printEmployee();
			break;
		case 10:
			cout << "Thank you, goodbye." << endl;
			return;
			break;
		default:
			cout << "No such option , sorry. Choose again please." << endl;
		}
	}
}

void Mall::addShop()
{
	string cname;
	int id;
	cout << "Enter chain's name: " << endl;
	cin.ignore();
	getline(cin, cname);
	cout << "Enter shop id: ";
	cin >> id;
	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == cname)
		{
			chains[i]->addStore(id);
			return;
		}
	}
	cout << "no chain in that name!" << endl;
}

void Mall::addEmployee()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin >> chainname;
	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
			chains[i]->addEmployee();
	}
}

void Mall::shopping()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);
	int storeid;
	cout << "Enter store ID: ";
	cin >> storeid;
	float value;
	cout << "Enter value of purchase: ";
	cin >> value;
	int idEmp;
	cout << "Enter the ID number of the employee who helped you: ";
	cin >> idEmp;

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
			chains[i]->Shopping(storeid, value, idEmp);
	}
}

void Mall::returnItem()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);
	int storeid;
	cout << "Enter store ID: ";
	cin >> storeid;
	float value;
	cout << "Enter value of purchase: ";
	cin >> value;
	int idEmp;
	cout << "Enter the ID number of the employee who helped you: ";
	cin >> idEmp;

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
			chains[i]->cancle(storeid ,value ,idEmp);
	}
}

void Mall::printChain()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
		{
			chains[i]->print();
			return;
		}
	}
}

void Mall::printSalaryChain()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
		{
			chains[i]->printsaleries();
			return;
		}
	}
}

void Mall::printSalaryShop()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);
	int storeid;
	cout << "Enter store ID: ";
	cin >> storeid;

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
		{
			chains[i]->printsaleriesShop(storeid);
			return;
		}
	}
}

void Mall::printShop()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);
	int storeid;
	cout << "Enter store ID: ";
	cin >> storeid;

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
		{
			chains[i]->printShop(storeid);
			return;
		}
	}
}

void Mall::printEmployee()
{
	string chainname;
	cout << "Enter chain's name: ";
	cin.ignore();
	getline(cin, chainname);
	int idEmp;
	cout << "Enter the ID number of the employee: ";
	cin >> idEmp;

	for (int i = 0; i < ChainsAmount; i++)
	{
		if (chains[i]->getName() == chainname)
		{
			chains[i]->printEmployee(idEmp);
			return;
		}
	}
}
