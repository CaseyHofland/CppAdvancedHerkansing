#include <iostream>
#include <algorithm>
#include <iterator>
#include "Student.h"

Student::Student(string name) : name(name) {}

Student::~Student() 
{
	for( auto& module : modules )
		module->students.erase(remove(module->students.begin(), module->students.end(), this), end(module->students));
}

const string Student::Name() const
{
	return name;
}

const int Student::MaxEC() const
{
	int ec = 0;
	for( auto const& module : modules )
		ec += module->EC();

	return ec;
}

void Student::AddModule(Module* module) 
{
	module->students.push_back(this);
	modules.push_back(module);
}

void Student::AddModules(vector<Module*> modules)
{
	for( auto& module : modules )
		AddModule(module);
}

void Student::RemoveModule(Module* module) 
{
	module->students.erase(remove(module->students.begin(), module->students.end(), this), end(module->students));
	modules.erase(remove(modules.begin(), modules.end(), module), end(modules));
}

void Student::RemoveModules(vector<Module*> modules) 
{
	for( auto& module : modules )
		RemoveModule(module);
}

ostream& operator<<(ostream& os, const Student& student) 
{
	os << student.name << " - " << student.MaxEC() << endl;
	return os;
}
