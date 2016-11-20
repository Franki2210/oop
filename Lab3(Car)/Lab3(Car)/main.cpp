// Lab3(Car).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ControlCar.h"
#include "Car.h"


using namespace std;

void main()
{
	CCar car;
	CControlCar controlCar(car, cin, cout);

	setlocale(LC_ALL, "russian");

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!controlCar.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
}
