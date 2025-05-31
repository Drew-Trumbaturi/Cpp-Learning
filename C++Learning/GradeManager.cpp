#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "GradeManager.h"

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
		if (avg >= 90 || avg == 100) {
			grade = 'A';
		}
		else if (avg >= 80 || avg == 89)
		{
			grade = 'B';
		}
		else if (avg >= 70 || avg == 79)
		{
			grade = 'C';
		}
		else if (avg >= 60 || avg == 69)
		{
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

	cin.get();
}