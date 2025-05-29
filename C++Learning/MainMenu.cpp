
// Chat gippities implimentation cause i was too lazy 
#include <iostream>
#include <conio.h>      // For _getch()
#include <vector>
#include <stdlib.h>     // For system("cls")
#include "IsEven.h"
#include "TestScores.h"
#include "MainMenu.h"

using namespace std;

void displayMenu(const vector<string>& options, int selected) {
	system("cls");
	cout << "Choose an option from the menu:\n";
	cout << "==================================\n";
	for (int i = 0; i < options.size(); i++) {
		if (i == selected)
			cout << "> ";
		else
			cout << "  ";

		cout << "Option " << i + 1 << ": " << options[i] << "\n";
	}
	cout << "==================================\n";
	cout << "Use the Up/Down keys or press 1/2, then Enter.\n";
}

void MainMenu::mainMenu() {
	vector<string> options = {
		"Is Even\n\tDescription:\n\tAsks the user to input a number and checks if it is even,\n\tthen shows all the numbers from 0 to n that are even.",
		"Test Scores\n\tDescription:\n\tGets the user to input a desired amount of test scores,\n\tthen shows the average, min, and max of the scores."
	};

	int selected = 0;
	char ch;

	while (true) {
		displayMenu(options, selected);
		ch = _getch();

		if (ch == 13) { // ENTER
			break;
		}
		else if (ch >= '1' && ch <= '9') {
			int index = ch - '1';
			if (index >= 0 && index < options.size()) {
				selected = index;
				break;
			}
		}
		else if (ch == -32) { // Arrow key prefix
			ch = _getch();
			if (ch == 72) { // Up arrow
				selected--;
				if (selected < 0) selected = options.size() - 1;
			}
			else if (ch == 80) { // Down arrow
				selected++;
				if (selected >= options.size()) selected = 0;
			}
		}
	}

	// Clear screen before executing selection
	system("cls");

	switch (selected)
	{
	case 0:
	{
		IsEven even;
		even.isEven();
	}
	break;

	case 1:
	{
		TestScores scores;
		scores.testScores();
	}
	break;

	default:
		break;
	}
}



// My original implimentation.

//#include <iostream>
//#include <stdlib.h>
//#include "IsEven.h"
//#include "TestScores.h"
//#include "MainMenu.h"
//
//using namespace std;
//
//void MainMenu::mainMenu() {
//	int option;
//
//	system("cls");
//	cout << "Choose an option from the menu:" << endl;
//	cout << "==================================" << endl;
//	cout << "Option 1: Is Even\n\tDescription:\n\tAsks the user to input a number and checks if it is even,\n\tthen shows all the numbers from 0 to n that are even." << endl;
//	cout << "" << endl;
//	cout << "Option 2: Test Scores\n\tDescription\n\tGets the user to input a desires amount of test scores,\n\tthen shows the average, min, and max of the scores." << endl;
//	cout << "==================================" << endl;
//	cout << "\nEnter an option: ";
//	cin >> option;
//
//	switch (option)
//	{
//	case 1:
//		system("cls");
//		IsEven even;
//		even.isEven();
//		break;
//
//	case 2:
//		system("cls");
//		TestScores scores;
//		scores.testScores();
//		break;
//
//	default:
//		break;
//	}
//}