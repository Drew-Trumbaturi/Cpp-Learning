#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "CatalogManager.h"
#include "Book.h"
#include "LibraryMenu.h"

using namespace std;

void CatalogManager::displayList() {
	vector<Book> books;
	string line;

	ifstream infile("books.txt");

	while (getline(infile, line))
	{
		stringstream stream(line);
		string title, author, yearStr, priceStr;

		// Reads each line and initializes the variable before the comma 
		// i.e - 
		getline(stream, title, ',');
		getline(stream, author, ',');
		getline(stream, yearStr, ',');
		getline(stream, priceStr);

		Book book;
		book.title = title;
		book.author = author;
		book.year = stoi(yearStr);     // string to int
		book.price = stod(priceStr);   // string to double

		books.push_back(book);
	}

	for (const Book& book : books) {
		book.display();
	}

	cin.get();
}

void CatalogManager::searchList() {
	vector<Book> books;
	string line, search;
	string title, author, yearStr, priceStr;
	Book book;

	cout << "Enter book title to search: ";
	getline(cin, search);

	ifstream file("books.txt");

	while (getline(file, line))
	{
		stringstream stream(line);

		// Reads each line and initializes the variable before the comma 
		// i.e - 
		getline(stream, title, ',');
		getline(stream, author, ',');
		getline(stream, yearStr, ',');
		getline(stream, priceStr);

		
		book.title = title;
		book.author = author;
		book.year = stoi(yearStr);     // string to int
		book.price = stod(priceStr);   // string to double

		books.push_back(book);
	}

	for (const Book& book : books) {
		if (book.matchesTitle(search)) {
			book.display();
		}
	}

	cin.get();
}

void CatalogManager::addBook() {
	vector<Book> books;
	string line;
	string title, author, yearStr, priceStr;
	int year;
	double price;

	Book book;

	cout << "Title: ";
	getline(cin, title);

	cout << "Author: ";
	getline(cin, author);

	cout << "Year: ";
	getline(cin, yearStr);

	cout << "Price: $";
	getline(cin, priceStr);

	ofstream outfile;
	outfile.open("books.txt", ios::app);

	cout << title << " by " << author << " (" << yearStr << ") - $" << fixed << setprecision(2) << priceStr << endl;

	if (outfile.is_open()) {
		outfile << title << "," << author << "," << yearStr << "," << fixed << setprecision(2) << priceStr << endl;
		outfile.close();
	}

	cin.get();
}
