// StudentenVanEdwin.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Module.h"
#include "Student.h"
#include "Docent.h"
using namespace std;

string hr() 
{
	return "____________________\n";
}

int main() 
{
	// We are settings up all the docents, students and modules so we can do some simple tests revolving pointers and references
	Docent* const edwin = new Docent("Edwin");
	Docent* raf = new Docent("Raf");
	Docent* const tim = new Docent("Tim");

	Student* const nathan = new Student("Nathan");
	Student* const casey = new Student("Casey");
	Student* const geoffrey = new Student("Geoffrey");
	Student* const mirna = new Student("Mirna");
	Student* const luuk = new Student("Luuk");
	Student* const max = new Student("Max");
	Student* const vanessa = new Student("Vanessa");
	Student* const nathalie = new Student("Nathalie");
	Student* const marnix = new Student("Marnix");
	Student* const hidde = new Student("Hidde");

	Module* const prog = new Module("Programmeren", 2, edwin);
	Module* const art = new Module("Art", 4, raf);
	Module* const design = new Module("Design", 3, tim);

	// Now lets pass our modules to students or students to modules (2 different ways possible)
	prog->AddStudents({nathan, casey, geoffrey, max});
	art->AddStudents({luuk, vanessa, nathalie, hidde});

	casey->AddModule(design);
	mirna->AddModule(design);
	vanessa->AddModule(design);
	marnix->AddModules({prog, art, design});

	// 1) print a list of modules, with docents & students
	cout << *prog << *art << *design << hr() << endl;

	// 2) show the total EC per student
	cout << *nathan << *casey << *geoffrey << *mirna << *luuk << *max << *vanessa << *nathalie << *marnix << *hidde << hr() << endl;

	// 3) change EC of module 1: show total EC per student
	int oldEC = prog->EC();
	prog->SetEC(100);
	cout << prog->Name() << " EC changed from " << oldEC << " EC to " << prog->EC() << " EC" << '\n';
	cout << '\n';
	cout << *nathan << *casey << *geoffrey << *mirna << *luuk << *max << *vanessa << *nathalie << *marnix << *hidde << hr() << endl;

	// 4) remove student from module & show list again
	casey->RemoveModules({design, prog});
	cout << "Casey removed from design and programming" << '\n';
	cout << '\n';
	art->RemoveStudent(luuk);
	cout << "Art removed Luuk" << '\n';
	cout << '\n';
	art->RemoveStudent(casey);
	cout << "Art tried to remove Casey even though Casey wasn't in its list" << '\n';
	cout << '\n';
	cout << *prog << *art << *design << hr() << endl;

	// 5) delete pointers and show list again
	delete prog;
	delete luuk;
	//delete raf;	<= unfortunately, this line would cause errors. Possibly could be fixed with shared / weak pointers?

	cout << "Programming and Luuk deleted" << '\n';
	cout << '\n';
	cout << *art << *design << hr() << endl;

	// We delete all of our pointers to clean up our memory footprint
	delete art;
	delete design;

	delete nathan;
	delete casey;
	delete geoffrey;
	delete mirna;
	delete max;
	delete vanessa;
	delete nathalie;
	delete marnix;
	delete hidde;

	delete edwin;
	delete raf;
	delete tim;

	return 0;
}
