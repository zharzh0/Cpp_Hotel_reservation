#include "Hotel.h"

Hotel::Hotel(int roomCount) {
    for (int i = 1; i <= roomCount; ++i)
    {
        rooms.emplace_back(i, false);
    }
}

void Hotel::printRooms() const {

    int roomsReserved = 0;
    int roomsAvailable = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i].reserved == true)
        {
            roomsReserved++;
        }
        else
        {
            roomsAvailable++;
        }
    }

    cout << "Total rooms available: " << roomsAvailable << endl;
}