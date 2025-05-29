#include <iostream>
#include "MainMenu.h"
#include "TestScores.h"

using namespace std;

double calculateAverage(int scores[], int size) {
	int sum = 0;
	double avg;

	for (size_t i = 0; i < size; i++)
	{
		sum += scores[i];
	}

	avg = (double)sum / size;

	cout << "Average score: " << avg <<  endl;

	return avg;
}

int findMax(int scores[], int size) {
	int max = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (scores[i] > max)
		{
			max = scores[i];
		}
	}
	
	cout << "Highest score: " << max << endl;

	return max;
}

int findMin(int scores[], int size) {
	int min = scores[0];
	
	for (size_t i = 0; i < size; i++)
	{
		if (scores[i] < min)
		{
			min = scores[i];
		}
	}

	cout << "Lowest score: " << min << endl;

	return min;
}

void TestScores::testScores() {
	int size;
	int scores[100];
	bool cont = true;
	char yn;

	do
	{
		cout << "How many test scores would you like to enter? (max 100): ";
		cin >> size;

		if (size > 100 || size < 1)
		{
			cout << "Please enter a number between 1 and 100." << endl;
			continue;
		}

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter score number #" << i + 1 << ": ";
			cin >> scores[i];
		}

		calculateAverage(scores, size);
		findMax(scores, size);
		findMin(scores, size);

		cout << "Would you like to enter more scores? [y/n]: ";
		cin >> yn;

		cont = (yn == 'y' || yn == 'Y');

	} while (cont);

	cout << "Would you like to go back to the menu? [y/n]: ";
	cin >> yn;

	if (yn == 'y' || yn == 'Y')
	{
		MainMenu menu;
		menu.mainMenu();
	}
}