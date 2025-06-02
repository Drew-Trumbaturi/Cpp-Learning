#pragma once
#include <string>

using namespace std;

class Book {
public:
	string title;
	string author;
	int year;
	double price;

	void display() const;
	bool matchesTitle(const string& search) const;
};