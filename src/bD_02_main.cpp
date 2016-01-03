//============================================================================
// Name        : bD_02_main.cpp
// Author      : Francesco Forcher
// Version     : 1.0
// Copyright   : All rights reserved © 2015
// Description : Modify v01 and use a struct
//============================================================================

#include <iostream>
#include <fstream>

#include "dbg_macro.h"
#include "Event.h"

void clear(Event* ev);

Event* read(std::ifstream& ifs);

void dump(const Event& ev);

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

