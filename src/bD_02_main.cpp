//============================================================================
// Name        : bD_02_main.cpp
// Author      : Francesco Forcher
// Version     : 1.0
// Copyright   : All rights reserved © 2015
// Description : Modify v01 and use a struct
//============================================================================

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

/* DBG: Function-like macro for debug, when macro DEBUG is defined DBG_ALT is
 * expanded into its first argument, otherwise its expanded into its second
 * argument. Arguments can be void, but is preferable to use a empty statement
 * (a single semicolon) instead.
 */
#ifdef DEBUG
#define DBG(x, y) x
#else
#define DBG(x, y) y
#endif

struct Event {
	unsigned int event_ID;
	unsigned int number_of_points;
	int* energies;
};

void clear(Event* ev) {
	delete[] ev->energies;
	delete ev;
	ev = nullptr;
}

Event* read(std::ifstream& ifs) {
	using namespace std;

	Event* ev = new Event;
	// Being ev a very small structure, i prefer to always allocate it before
	// rather than complicate the program's logic trying to read
	// from file into temporary variables before (potentially) creating it.
	if (ifs >> ev->event_ID) {
		ifs >> ev->number_of_points;
		ev->energies = new int[ev->number_of_points];
		for (unsigned int i = 0; i < ev->number_of_points; ++i) {
			ifs >> ev->energies[i];
		}
	} else {
		//We cannot do clear(ev) here, because here ev has undefined values.
		delete ev;
		ev = nullptr;
	}

	return ev;
}

void dump(const Event& ev) {
	using namespace std;

	if (ev.number_of_points == 0)
		return;

	cout << "Event " << ev.event_ID << ": " << ev.number_of_points << " points"
			<< endl;
	for (unsigned int i = 0; i < ev.number_of_points; ++i) {
		cout << "    " << ev.energies[i] << endl;
	}
	return;
}

int main(int argc, char* argv[]) {
	using namespace std;

	//Read file name, see DBG macro at the start.
	DBG(const char* filename = "./bragg_events.txt";
		, const char* filename = argv[1];)

	//Open file
	ifstream ifs(filename);

	Event* event;
	while (ifs) {
		event = read(ifs);
		if (event) {
			dump(*event);
			clear(event);
		}
	}

	return 0;
}

