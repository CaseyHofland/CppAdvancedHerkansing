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

	friend class Module;
};