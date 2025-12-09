#include <iostream>
#include <stdlib.h>
#include "Hotel.h"
#include <string>

using namespace std;
int basicUI();
int reserveUI(Hotel& hotel);

//randomize how many rooms the hotel will have
static Hotel createHotel() {
	int hotelSize = 10 + rand() % 191;
	return Hotel(hotelSize);
}

int main() {

	//seed for random number generations
	srand(time(nullptr));
	
	// initializing a new hotel with random amount of rooms
	Hotel h = createHotel();

	cout << "Tervetuloa hotelliin \n \n";

	while (true) {
		h.printRooms();
		int selection = basicUI();
		
		switch (selection) {
		case 1: reserveUI(h);
			break;

		case 2: h.printAllReservations();
			break;

		case 3: {
			string guestName;
			cout << "Anna nimi jolla varaus on tehty: \n";
			getline(cin, guestName);
			h.printReservation(guestName);
			break;
		}

		case 4: cout << "Ohjelma suljetaan.";
			return -1;

		default: cout << "Virheellinen syote. ";
			break;
		}
		
		//clean the buffer and wait for user to press enter
		cout << "Paina Enter jatkaaksesi...\n";
		cin.get();
		system("cls"); //clear the terminal (on windows machines)
	};
}

