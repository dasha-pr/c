#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void task1()
{
	char string[100];

	cout << "Enter words:\n";
	cin.getline(string, 100);
	char* nexTokenPtr = NULL;
	char* pch = strtok_s(string, " ", &nexTokenPtr);
	char* word = 0; 
	int length = strlen(pch); 
	int maxLen = 0; 

	while (pch != NULL) 
	{
		length = strlen(pch); 

		if (maxLen < length)
		{
			maxLen = length;
			word = pch; 
		}

		pch = strtok_s(NULL, " ", &nexTokenPtr); 
	}
	cout << "The longest world: " << word << " , it's length: " << maxLen << " symbols " << endl;
}


struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}
	default:
		result = false;
	}
	return result;
}

struct HomeAddress
{
	int postcode;
	char country[20];
	char region[20];
	char area[20];
	char city[20];
	char street[30];
	int house;
	int flat;
};

struct Enrollee
{
	char Name[30];
	char Male[7];
	char Citizenship[20];
	Date birth;
	HomeAddress address;
};


void abonentsInfoInput(const int N, Enrollee person[])
{
	
	for (size_t i = 0; i < N; i++)
	{
		cout << "\nInput enrollee's FIO (using space): ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].Name;

		cout << "\nInput enrollee's male: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].Male;

		cout << "\nInput enrollee's citizenship: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].Citizenship;

		do
		{
			cout << "\nInput enrollee's birtday (using space): ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> person[i].birth.day >> person[i].birth.month >> person[i].birth.year;
		} while (!person[i].birth.isCorrect());

		cout << "\nInput enrollee's home adress (using space): ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cout << "Adress area:"; 
		cin >> person[i].address.area; 
		cout << "\nCity:";
		cin >> person[i].address.city;
		cout << "\nCountry:";
		cin >> person[i].address.country;
		cout << "\nFlat:";
		cin >> person[i].address.flat;
		cout << "\nHouse:";
		cin >> person[i].address.house;
		cout << "\nPostcode:";
		cin >> person[i].address.postcode;
		cout << "\nRegion:";
		cin >> person[i].address.region;
		cout << "\nStreet:";
		cin >> person[i].address.street;
	}
}

void infoOutput(const int N, Enrollee person[])
{
	for (size_t i = 0; i < N; i++)
	{
		cout << "Person " << N;
		cout << "FIO: " << person[i].Name << endl;;
		cout << "Male: " << person[i].Male << endl;
		cout << "Birth Date: " << person[i].birth.day << "." << person[i].birth.month << "." << person[i].birth.year << endl;
		cout << "Citizenship: " << person[i].Citizenship << endl;
		cout << "Adress area: " << person[i].address.area << "\nCity: " << person[i].address.city << "\nCountry: " << person[i].address.country << "\nFlat number: " << person[i].address.flat << "\nHouse number: " << person[i].address.house << "\nPostcode: " << person[i].address.postcode << "\nRegion: " << person[i].address.region << "\nStreet: " << person[i].address.street << endl;
		cout << endl;
	}
}

void task2()
{
	const int N = 2;
	Enrollee person[N];
	abonentsInfoInput(N, person);
	infoOutput(N, person);
}




int main()
{
	task1();
	task2();
}
