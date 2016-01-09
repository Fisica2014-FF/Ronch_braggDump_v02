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

	//Try to open the file and check the stream.
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "[ERROR] File not opened";
		return -1;
	}

	//Dump variables
	Event* event;
	while (ifs) {
		event = read(ifs);
		if (event) {
			dump(*event);
			clear(event);
		}
		cout << endl;
	}

	return 0;
}

