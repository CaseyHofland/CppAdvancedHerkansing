#pragma once

#include <string>
#include <vector>
#include "Module.h"
using namespace std;

class Module;

class Student {
public:
	Student(string name);
	virtual ~Student();

	const string Name() const;
	const int MaxEC() const;

	void AddModule(Module* module);
	void AddModules(vector<Module*> modules);
	void RemoveModule(Module* module);
	void RemoveModules(vector<Module*> modules);

	friend ostream& operator<<(ostream& os, const Student& student);

private:
	string name;
	vector<Module*> modules;

	friend class Module;
};