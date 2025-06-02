#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Book.h"

using namespace std;

void Book::display() const {
	cout << title << " by " << author << ", (" << year << ") - $" << fixed << setprecision(2) << price << endl;
}

bool Book::matchesTitle(const string& search) const {
	string lowerTitle = title;
	string lowerSearch = search;

	transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
	transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);


	return lowerTitle.find(lowerSearch) != string::npos;
}