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

	vector<room> rooms;
public:
	Hotel(int roomCount);
	void printRooms() const;
	int reserveRoom(int roomNumber);
	int reserveFirstAvailable();
};