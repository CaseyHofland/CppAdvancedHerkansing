#include <iostream>
#include <algorithm>
#include "Module.h"

Module::Module(string name, int ec) : name(name), ec(ec) {}

Module::Module(string name, int ec, Docent* docent) : name(name), ec(ec), docent(docent) {}

Module::~Module() 
{
	EraseDocent();
	for( auto& student : students )
		student->modules.erase(remove(student->modules.begin(), student->modules.end(), this), end(student->modules));
}

const string Module::Name() const
{
	return name;
}

const int Module::EC() const
{
	return ec;
}

void Module::SetEC(int ec) 
{
	this->ec = ec;
}

void Module::SetDocent(Docent* docent)
{
	EraseDocent();
	this->docent = docent;
	docent->modules.push_back(this);
}

void Module::AddStudent(Student* student) 
{
	student->modules.push_back(this);
	students.push_back(student);
}

void Module::AddStudents(vector<Student*> students) 
{
	for( auto& student : students )
		AddStudent(student);
}

void Module::RemoveStudent(Student* student) 
{
	student->modules.erase(remove(student->modules.begin(), student->modules.end(), this), end(student->modules));
	students.erase(remove(students.begin(), students.end(), student), end(students));
}

void Module::RemoveStudents(vector<Student*> students) 
{
	for( auto& student : students )
		RemoveStudent(student);
}

void Module::EraseDocent() 
{
	if(docent)
	{
		docent->modules.erase(remove(docent->modules.begin(), docent->modules.end(), this), end(docent->modules));
		docent = nullptr;
	}
}

ostream& operator<<(ostream& os, const Module& module)
{
	os << module.name << ":" << '\n';
	os << "  EC:       " << module.ec << '\n';
	os << "  Docent:   " << (module.docent ? module.docent->Name() : "-") << '\n';
	os << "  Students: " << '\n';

	for(auto const& student : module.students)
		os << "    " << student->Name() << '\n';

	return os << endl;
}
