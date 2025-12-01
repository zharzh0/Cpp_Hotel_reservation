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
			bool reserved;

			room(int n, bool taken)
			{
				number = n;
				reserved = taken;
			}

	};

	vector<room> rooms;
public:
	Hotel(int roomCount);
	void printRooms() const;
};

