#pragma once

#include <string>
#include <vector>
#include "Docent.h"
#include "Student.h"
using namespace std;

class Docent;
class Student;

class Module {
public:
	Module(string name, int ec);
	Module(string name, int ec, Docent* docent);
	virtual ~Module();

	const string Name() const;
	const int EC() const;

	void SetEC(int ec);
	void SetDocent(Docent* docent);

	void AddStudent(Student* student);
	void AddStudents(vector<Student*> students);
	void RemoveStudent(Student* student);
	void RemoveStudents(vector<Student*> students);

	friend ostream& operator<<(ostream& os, const Module& module);

private:
	void EraseDocent();

	string name;
	int ec;
	Docent* docent = NULL;
	vector<Student*> students;

	friend class Docent;
	friend class Student;
};