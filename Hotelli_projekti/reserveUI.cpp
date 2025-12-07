#include "Hotel.h"
#include <iostream>
#include <string>

using namespace std;

int reserveUI(Hotel& hotel) {

	string guestName;
	int selection;

	cout << "Mille nimelle varaus tulee? Syota nimi: \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, guestName);

	cout << "Varataanko huone automaattisesti, vai haluatko valita huoneen numeron? \n";
	cout << "1. Automaattinen \n";
	cout << "2. Valitse huoneen numero \n";
	cin >> selection;

	if (selection == 1) {

		int roomNumber = hotel.getFirstAvailableRoomNumber();
	
		if (roomNumber == -1)
		{
			cout << "Ei vapaita huoneita.";
			return -1;
		}

		int reservationID = hotel.reserveRoom(roomNumber, guestName);

		cout << "Huone varattu onnistuneesti!\n";
		cout << "Huonenumero: " << roomNumber << "\n";
		cout << "Varauksen ID: " << reservationID << "\n";
		return reservationID;
	}
	
	else if (selection == 2) {
		
		int roomNumber;
		cout << "Anna huoneen numero: ";
		cin >> roomNumber; 

		int reservationID = hotel.reserveRoom(roomNumber, guestName);

		if (reservationID == -1) {
			cout << "Huonetta ei loydy tai se on jo varattu. \n";
			return -1;
		}
		else {
			cout << "Huone varattu onnistuneesti!\n";
			cout << "Huonenumero: " << roomNumber << "\n";
			cout << "Varauksen ID: " << reservationID << "\n";
			return reservationID;
		}
	}

	cout << "Virheellinen valinta. \n";
	return -1;
}