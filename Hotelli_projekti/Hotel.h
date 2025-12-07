#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Hotel
{
private:
	struct room
	{
		int number;
		int reservationID;
		bool reserved;

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
		string guestName;

		reservation(int id_, int room_, const string& name_) 
			: id(id_), roomNumber(room_), guestName(name_) {}
	};

	vector<room> rooms;
	vector<reservation> reservations;

public:
	Hotel(int roomCount);
	void printRooms() const;
	void printReservation(int id) const;
	int reserveRoom(int roomNumber, const string& guestName);
	int getFirstAvailableRoomNumber() const;
};