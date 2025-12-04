#include <iostream>
#include <stdlib.h>
#include "Hotel.h"

using namespace std;
int basicUI();
int reserveUI(Hotel& hotel);

int main() {

	srand(time(nullptr));
	Hotel h(50);
	cout << "Tervetuloa hotelliin \n \n";
	h.printRooms();

	while (true) {
		int selection = basicUI();
		
		switch (selection) {
		case 1: reserveUI(h);
			break;

		case 4: h.printRooms();
			break;

		case 5: cout << "Ohjelma suljetaan.";
			return -1;

		default: cout << "Virheellinen syote. ";
			break;
		}
		
		cout << "Paina Enter jatkaaksesi...\n";
		cin.ignore();
		cin.get();
	};
}

