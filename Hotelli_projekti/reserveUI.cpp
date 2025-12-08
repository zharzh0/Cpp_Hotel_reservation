#include "Hotel.h"
#include <iostream>
#include <string>

using namespace std;

int reserveUI(Hotel& hotel) {

	string guestName;
	int selection;
	int nights;
	double pricePerNight = 100.0;

	cout << "Mille nimelle varaus tulee? Syota nimi: \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, guestName);

	cout << "Valitaanko huone automaattisesti, vai haluatko itse valita huoneen numeron? \n";
	cout << "1. Automaattinen \n";
	cout << "2. Valitse huoneen numero \n";
	cin >> selection;

	while (selection != 1 && selection != 2) {
		cout << "Virheellinen valinta, yrita uudelleen.\n";
		cin >> selection;
	}

	cout << "Moneksiko yoksi varaus tehdaan? 1-10: \n";
	cin >> nights;

	if (nights < 1 || nights > 10) {
		cout << "Yomaara on oltava valilta 1-10. \n";
		return -1;
	}

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
		
		int roomNumber;
		cout << "Anna huoneen numero: ";
		cin >> roomNumber; 

		int reservationID = hotel.reserveRoom(roomNumber, guestName, nights, totalPrice);

		if (reservationID == -1) {
			cout << "Huonetta ei loydy tai se on jo varattu. \n";
			return -1;
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

	cout << "Virheellinen valinta. \n";
	return -1;
}