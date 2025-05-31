#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "GradeManager.h"
#include "MainMenu.h"

using namespace std;

class Student {
public:
	string name;
	vector<int> scores;
	double avg;
	char grade;

	void calculateAvg() {
		int sum = 0;

		for (int score : scores) {
			sum += score;
		}

		if (!scores.empty())
		{
			avg = (double)sum / scores.size();
		}
		else {
			avg = 0;
		}
	}
	void assignGrade() {
		if (avg >= 90) {
			grade = 'A';
		}
		else if (avg >= 80) {
			grade = 'B';
		}
		else if (avg >= 70) {
			grade = 'C';
		}
		else if (avg >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
	}
};


void GradeManager::gradeManager() {
	vector<Student> students;
	string line;
	char yn;

	ifstream infile("students.txt");

	while (getline (infile, line)) {
		stringstream ss( line);
		Student student;
		ss >> student.name;

		int score;
		while (ss >> score)
		{
			student.scores.push_back(score);
		}

		student.calculateAvg();
		student.assignGrade();

		students.push_back(student);
	}

	ofstream outfile("report.txt");

	for (const Student& student : students) {
		cout << student.name << " - Average: " << student.avg << " - Grade: " << student.grade << endl;
		outfile << student.name << " - Average: " << student.avg << " - Grade: " << student.grade << endl;
	}

	infile.close();

	cout << "\nWould you like to go back to the menu? [y/n]: ";
	cin >> yn;

	if (yn == 'y' || yn == 'Y')
	{
		MainMenu menu;
		menu.mainMenu();
	}
}