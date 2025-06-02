#include <iostream>
#include <conio.h>      // For _getch()
#include <vector>
#include <stdlib.h>     // For system("cls")
#include "LibraryMenu.h"
#include "MainMenu.h"
#include "Book.h"
#include "CatalogManager.h"

using namespace std;

void displayLibraryMenu(const vector<string>& options, int selected) {
	system("cls");
	cout << "Choose an option from the menu:\n";
	cout << "==================================\n";
	for (int i = 0; i < options.size(); i++) {
		if (i == selected)
			cout << "> ";
		else
			cout << "  ";

		cout << "Option " << i + 1 << ": " << options[i] << "\n" << endl;
	}
	cout << "==================================\n";
	cout << "Use the Up/Down keys or press [1-9], then Enter.\n";
}

void LibraryMenu::menu() {
	CatalogManager catalog;

	vector<string> options = {
		"List all books",
		"Search by title",
		"Add a new book",
		"Save and exit",
	};

	int selected = 0;
	char choice;

	while (true) {
		displayLibraryMenu(options, selected);
		choice = _getch();

		if (choice == 13) { // ENTER
			break;
		}
		else if (choice >= '1' && choice <= '9') {
			int index = choice - '1';
			if (index >= 0 && index < options.size()) {
				selected = index;
				break;
			}
		}
		else if (choice == -32) { // Arrow key prefix
			choice = _getch();
			if (choice == 72) { // Up arrow
				selected--;
				if (selected < 0) selected = options.size() - 1;
			}
			else if (choice == 80) { // Down arrow
				selected++;
				if (selected >= options.size()) selected = 0;
			}
		}
	}
	
	

	switch (selected)
	{
		case 0:
		{
			cout << "\n";
			catalog.displayList();
		}
		break;

		case 1:
		{
			catalog.searchList();
		}
		break;

		case 2:
		{
			catalog.addBook();
		}
		break;

		case 3:
		{
			MainMenu menu;
			menu.mainMenu();
		}
		break;

		default:
			break;
	}
	
}

