#pragma once

#include <string>
#include <vector>
#include "Module.h"
using namespace std;

class Module;

class Docent {
public:
	Docent(string name);
	virtual ~Docent();

	const string Name() const;

	friend ostream& operator<<(ostream& os, const Docent& docent);

private:
	string name;
	vector<Module*> modules;

	// We make Module a friend class so that Docent can safely Add and Remove itself to it 
	// without causing an infinite loop
	friend class Module;
};