#include "Junior.h"

Junior::Junior() : Employee(), purchases(nullptr), numOfPurchses(0) {}

Junior::Junior(string nameI, int idI, int job, float salary): Employee(nameI, idI, job, salary), purchases(nullptr), numOfPurchses(0){}

Junior::Junior(const Junior& obj) : Employee(obj)
{
	if (obj.purchases != nullptr)
	{
		purchases = obj.purchases;
		numOfPurchses = obj.numOfPurchses;
	}
	else 
	{
		purchases = nullptr;
		numOfPurchses = 0;
	}
}

Junior::~Junior()
{
	if (purchases != nullptr)
		delete[] purchases;

}

void Junior::addPurchase(float sum)
{
	if (numOfPurchses == 0)
	{
		numOfPurchses = 1;
		purchases = new float(1);
		purchases[0] = sum;
	}
	else
	{
		int i;
		float* temp;
		numOfPurchses += 1;

		temp = new float(numOfPurchses);

		for (i = 0; i < numOfPurchses - 1; i++)
		{
			temp[i] = purchases[i];
		}
		temp[i] = sum;
		delete[] purchases;
		purchases = temp;
	}
}

void Junior::cancle(float sum)
{
	int i;
	bool flag = false;
	for (int i = 0; i < this->numOfPurchses; i++)
	{
		if (this->purchases[i] == sum)
		{
			flag = true;
			float* temp;
			temp = new float(numOfPurchses - 1);
			int g = 0;

			for (int j = 0; j < numOfPurchses; j++)
			{
				if (purchases[j] != sum)
				{
					temp[g] = purchases[j];
					g++;
				}
			}
			delete[] purchases;
			purchases = temp;
		}
	}
	if (flag == false)
	{
		cout << "No such purchase!" << endl;
		return;
	}
}

float Junior::avg()
{
	float sum = 0;
	for (int i = 0; i < numOfPurchses; i++)
		sum += purchases[i];
	if (sum == 0)
		return 0;
	return sum / numOfPurchses;
}
