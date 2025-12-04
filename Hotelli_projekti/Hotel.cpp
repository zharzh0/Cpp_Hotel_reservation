#include "Hotel.h"
#include <cstdlib>

Hotel::Hotel(int roomCount) {
    for (int i = 1; i <= roomCount; ++i)
    {
        rooms.emplace_back(i);
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

    cout << "Huoneita saatavilla: " << roomsAvailable << endl;
}

int Hotel::reserveRoom(int roomNumber) {

    for (int i = 0; i < rooms.size(); i++) {

        if (rooms[i].number == roomNumber) {

            if (rooms[i].reserved) {

                return -1;  
            }

            rooms[i].reserved = true;
            rooms[i].reservationID = 10000 + rand() % 30001;
            return rooms[i].reservationID;
        }
    }

}

int Hotel::reserveFirstAvailable() {

    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].reserved == false) {

            rooms[i].reserved = true;

            int generatedID = 10000 + rand() % 30001;
            rooms[i].reservationID = generatedID;

            return generatedID;
        }
    }

    return -1;
}