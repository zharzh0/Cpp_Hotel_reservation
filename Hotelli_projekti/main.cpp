#include <iostream>
#include "Hotel.h"

using namespace std;
int basicUI();

int main() {

	

	int selection = basicUI();
	Hotel h(50);
	h.printRooms();

	switch (selection) {
	//case 1: reserveRoom(); kesken
	//case 4: close_program; ei tehty
	}


}

