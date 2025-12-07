#include <iostream>
#include <stdlib.h>
#include "Hotel.h"

using namespace std;
int basicUI();
int reserveUI(Hotel& hotel);

Hotel static createHotel() {
	int hotelSize = 10 + rand() % 191;
	return Hotel(hotelSize);
}

int main() {

	srand(time(nullptr));
	
	Hotel h = createHotel();

	cout << "Tervetuloa hotelliin \n \n";
	h.printRooms();

	while (true) {
		int selection = basicUI();
		
		switch (selection) {
		case 1: reserveUI(h);
			break;

		case 4: h.printRooms();
			break;

		case 5: {
			int id;
			cout << "Anna varauksen ID: \n";
			cin >> id;
			h.printReservation(id);
			break;
		}

		case 6: cout << "Ohjelma suljetaan.";
			return -1;

		default: cout << "Virheellinen syote. ";
			break;
		}
		
		cout << "Paina Enter jatkaaksesi...\n";
		cin.ignore();
		cin.get();
	};
}

