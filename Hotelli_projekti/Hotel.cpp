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

void Hotel::printReservation(int id) const {

    for (int i = 0; i < reservations.size(); i++) {

        if (reservations[i].id == id) {

            cout << "Varaus loytyi:\n\n";
            cout << "---------------------------\n";
            cout << "Varaus ID:      " << reservations[i].id << "\n";
            cout << "Huonenumero:    " << reservations[i].roomNumber << "\n";
            cout << "Varaajan nimi:  " << reservations[i].guestName << "\n";
            cout << "---------------------------\n\n";

            return;
        }
    }

    cout << "Varausta ID:lla " << id << " ei loytynyt. \n\n";

}

int Hotel::reserveRoom(int roomNumber, const string& guestName) {

    for (int i = 0; i < rooms.size(); i++) {

        if (rooms[i].number == roomNumber) {

            if (rooms[i].reserved) {

                return -1;  
            }

            rooms[i].reserved = true;
            int generatedID = 10000 + rand() % 30001;
            rooms[i].reservationID = generatedID;

            reservations.emplace_back(generatedID, roomNumber, guestName);

            return generatedID;
        }
    }

    return -1;
}

int Hotel::getFirstAvailableRoomNumber() const {
    for (int i = 0; i < rooms.size(); i++) {

        if (!rooms[i].reserved) {
            return rooms[i].number;
        }
    }
    return -1;
}