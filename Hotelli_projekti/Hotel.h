#pragma once
#include <vector>
#include <iostream>

using namespace std;

//making class that holds structs
class Hotel
{
private:
	struct room
	{
		int number;
		int reservationID;
		bool reserved;

		//old school constructor
		room(int n)
		{
			number = n;
			reservationID = 0;
			reserved = false;
		}
	};

	struct reservation
	{
		int id;
		int roomNumber;
		int nights;
		double price;
		string guestName;

		//member initializer list style constructor
		reservation(int id_, int room_, const string& name_, int nights_, double price_)
			: id(id_), roomNumber(room_), guestName(name_), nights(nights_), price(price_) {}
	};

	//storage for rooms and reservations
	vector<room> rooms;
	vector<reservation> reservations;

public:

	//public methods available to other parts of the app
	Hotel(int roomCount);
	void printRooms() const; 
	void printReservation(int id) const;
	int reserveRoom(int roomNumber, const string& guestName, int nights, double price);
	int getFirstAvailableRoomNumber() const;
};