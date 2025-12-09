#include "Hotel.h"
#include <iostream>
#include <string>

using namespace std;

int readInt(const string& description, int min, int max);

int reserveUI(Hotel& hotel) {

	string guestName;
	double pricePerNight = 100.0;

	while (true) {
		cout << "Mille nimelle varaus tulee? Syota nimi: \n";
		getline(cin, guestName);

		if (!guestName.empty())
			break;

		cout << "Nimi ei voi olla tyhja, yrita uudelleen...\n";
	}
	
	int selection = readInt(
		"Valitaanko huone automaattisesti vai itse? 1 = auto, 2 = manuaalinen: \n",
		1,
		2
	);

	int nights = readInt(
		"Moneksiko yoksi varaus tehdaan? 1-10: \n",
		1,
		10
	);

	double totalPrice = nights * pricePerNight;

	if (selection == 1) {

		int roomNumber = hotel.getFirstAvailableRoomNumber();
	
		if (roomNumber == -1)
		{
			cout << "Ei vapaita huoneita.";
			return -1;
		}

		int reservationID = hotel.reserveRoom(roomNumber, guestName, nights, totalPrice);

		cout << "Huone varattu onnistuneesti!\n";
		cout << "Huonenumero: " << roomNumber << "\n";
		cout << "Varauksen ID: " << reservationID << "\n";
		cout << "Varattujen oiden maara: " << nights << "\n";
		cout << "Hinta: " << totalPrice << "\n";
		return reservationID;
	}
	
	else if (selection == 2) {

		while (true) {
			int roomNumber;
			cout << "Anna huoneen numero: ";
			cin >> roomNumber;

			int reservationID = hotel.reserveRoom(roomNumber, guestName, nights, totalPrice);

			if (reservationID == -1) {
				cout << "Huonetta ei loydy tai se on jo varattu. Valitse toinen huone\n";
				continue;
			}
			else {
				cout << "Huone varattu onnistuneesti!\n";
				cout << "Huonenumero: " << roomNumber << "\n";
				cout << "Varauksen ID: " << reservationID << "\n";
				cout << "Varattujen oiden maara: " << nights << "\n";
				cout << "Hinta: " << totalPrice << "\n";
				return reservationID;
			}
		}
	}

	cout << "Virheellinen valinta. \n";
	return -1;
}