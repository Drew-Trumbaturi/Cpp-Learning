#include <iostream>
#include "MainMenu.h"
#include "TestScores.h"

using namespace std;

const int MAX_SCORES = 100;

void calculateScores(int scores[], int size) {
	int sum = 0;
	int max = scores[0];
	int min = scores[0];

	for (size_t i = 0; i < size; i++)
	{
		sum += scores[i];
		if (scores[i] > max) max = scores[i];
		if (scores[i] < min) min = scores[i];
	}

	double avg = (double)sum / size;

	cout << "Average score: " << avg <<  endl;
	cout << "Highest score: " << max << endl;
	cout << "Lowest score: " << min << endl;
}

bool yesNo(const string& message) {
	char yn;

	cout << message << " [y/n]: ";
	cin >> yn;

	return (yn == 'y' || yn == 'Y');
}

void TestScores::testScores() {
	int size;
	int scores[MAX_SCORES];
	bool cont = true;

	do
	{
		cout << "How many test scores would you like to enter? (" << MAX_SCORES << "): ";
		cin >> size;

		if (cin.fail() || size > MAX_SCORES || size < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a number between 1 and " << MAX_SCORES << "." << endl;
			continue;
		}

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter score number #" << i + 1 << ": ";
			cin >> scores[i];

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid score. Please enter an integer: ";
				cin >> scores[i];
			}
		}

		calculateScores(scores, size);
		
		cont = yesNo("Would you like to enter more scores?");
	

	} while (cont);

	

	if (yesNo("Would you like to go back to the menu?"))
	{
		MainMenu menu;
		menu.mainMenu();
	}
}