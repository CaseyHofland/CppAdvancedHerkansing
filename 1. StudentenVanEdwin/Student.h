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

	// We make Module a friend class so that Student can safely Add and Remove itself to it 
	// without causing an infinite loop
	friend class Module;
};