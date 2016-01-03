/*
 * dump.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include <iostream>

#include "../Event.h"


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

