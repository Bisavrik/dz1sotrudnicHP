#include <iostream>
#include <cstring>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

struct Worker
{
	char* surname;
	char* name;
	char* number;
	double salary;
};

bool isValidPhoneNumber(const char* phoneNumber) 
{
	if (strlen(phoneNumber) != 13) 
	{
		return false;
	}
	
	if (phoneNumber[0] != '(' || phoneNumber[4] != ')' ||
		!(phoneNumber[1] >= '0' && phoneNumber[1] <= '9') ||
		!(phoneNumber[2] >= '0' && phoneNumber[2] <= '9') ||
		!(phoneNumber[3] >= '0' && phoneNumber[3] <= '9') ||
		!(phoneNumber[5] >= '0' && phoneNumber[5] <= '9') ||
		!(phoneNumber[6] >= '0' && phoneNumber[6] <= '9') ||
		!(phoneNumber[7] >= '0' && phoneNumber[7] <= '9') ||
		!(phoneNumber[8] >= '0' && phoneNumber[8] <= '9') ||
		!(phoneNumber[9] >= '0' && phoneNumber[9] <= '9') ||
		!(phoneNumber[10] >= '0' && phoneNumber[10] <= '9') ||
		!(phoneNumber[11] >= '0' && phoneNumber[11] <= '9') ||
		!(phoneNumber[12] >= '0' && phoneNumber[12] <= '9')) 
	{
		return false;
	}
	return true;
}

void addWorker(Worker& worker)
{
	char* surname = new char[255];
	cout << "Enter surname: ";
	cin >> surname;
	int size1 = strlen(surname);
	worker.surname = new char[size1 + 1];
	strcpy(worker.surname, surname);

	char* name = new char[255];
	cout << "Enter name: ";
	cin >> name;
	int size2 = strlen(name);
	worker.name = new char[size2 + 1];
	strcpy(worker.name, name);

	char* number = new char[255];
	bool valid = false;
	while (!valid)
	{
		cout << "Enter number in format (000)0000000: ";
		cin >> number;

		if (isValidPhoneNumber(number)) 
		{
			valid = true;
		}
		else 
		{
			cout << "Error: The phone number must be in the format (000)0000000." << endl;
		}
	}
	int size3 = strlen(number);
	worker.number = new char[size3 + 1];
	strcpy(worker.number, number);

	cout << "Enter salary: ";
	cin >> worker.salary;

	delete[] surname;
	delete[] name;
	delete[] number;
}

void showWorker(Worker& worker)
{
	cout << "Surname: " << worker.surname << endl;
	cout << "Name: " << worker.name << endl;
	cout << "Number: " << worker.number << endl;
	cout << "Salary: " << worker.salary << endl;
}

void deleteWorker(Worker* listWorker, int& sum)
{
	char surname[225];
	char name[225];

	cout << "Enter worker that you want to delete: " << endl;
	cout << "Surname: ";
	cin >> surname;
	cout << "Name: ";
	cin >> name;

	for (int i = 0; i < sum; i++)
	{
		if (strcmp(listWorker[i].surname, surname) == 0 && strcmp(listWorker[i].name, name) == 0)
		{
			delete[] listWorker[i].surname;
			delete[] listWorker[i].name;
			delete[] listWorker[i].number;
			for (int j = i; j < sum - 1; j++)
			{
				listWorker[j] = listWorker[j + 1];
			}
			--sum;
			cout << "Worker delete." << endl;
			return;
		}
	}
	cout << "Worker not found." << endl;
}

void showAllWorkers(Worker* listWorker, int sum)
{
	for (int i = 0; i < sum; i++)
	{
		cout << "Worker " << i + 1 << ":" << endl;
		showWorker(listWorker[i]);
	}
}

Worker* searchBySurname(Worker* listWorker, int sum, char* findSurname)
{
	for (int i = 0; i < sum; i++)
	{
		if (strcmp(findSurname, listWorker[i].surname) == 0)
		{
			return &listWorker[i];
		}
	}
	return nullptr;
}

Worker* searchBySalary(Worker* listWorker, int sum)
{
	double salary;
	cout << "Enter salary to search: ";
	cin >> salary;

	bool found = false;
	for (int i = 0; i < sum; i++)
	{
		if (listWorker[i].salary == salary)
		{
			showWorker(listWorker[i]);
			found = true;
			return &listWorker[i];
		}
	}
	if (!found)
	{
		cout << "No worker found with salary " << salary << "." << endl;
	}
}

void sortBySurname(Worker* listWorker, int sum)
{
	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = 0; j < sum - i - 1; j++)
		{
			if (strcmp(listWorker[j].surname, listWorker[j + 1].surname)>0)
			{
				Worker temp = listWorker[j];
				listWorker[j] = listWorker[j + 1];
				listWorker[j + 1] = temp;
			}
		}
	}
	showAllWorkers(listWorker, sum);
}