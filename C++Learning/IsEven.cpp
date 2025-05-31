#include <iostream>
#include "MainMenu.h"
#include "IsEven.h"

using namespace std;


void printEvenNumbers(int a) {

	cout << "Even numbers from 1 to " << a << ":" << endl;

	for (size_t i = 1; i <= a; i++)
	{
		if (i % 2 == 0)
		{
			cout << i << " ";
		}
	}
}


int IsEven::isEven() {
	int a;
	char yn;

	cout << "Enter a number: ";
	cin >> a;

	if (a <= 0)
	{
		cout << "Please enter a positive number." << endl;
	}

	if (a % 2 == 0)
	{
		cout << a << " is an even number" << endl;
	}
	else {
		cout << a << " is not an even number" << endl;

	}

	printEvenNumbers(a);
	
	cout << "\nWould you like to go back to the menu? [y/n]: ";
	cin >> yn;

	if (yn == 'y' || yn == 'Y')
	{
		MainMenu menu;
		menu.mainMenu();
	}

	return 0;
}