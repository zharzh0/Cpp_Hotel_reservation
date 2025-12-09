#include "Hotel.h"
#include <cstdlib>


//constructor for adding roomCount amount of rooms into the rooms vector
Hotel::Hotel(int roomCount) {
    for (int i = 1; i <= roomCount; ++i)
    {
        rooms.emplace_back(i);
    }
}


//METHODS FOR HOTEL CLASS BELOW


//get room count
int Hotel::getRoomCount() const {
    return static_cast<int>(rooms.size());
}

//print all available rooms
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

//print reservation details using guests name
void Hotel::printReservation(const string& guestName){

    for (int i = 0; i < reservations.size(); i++) {

        if (reservations[i].guestName == guestName) {

            cout << "Varaus loytyi:\n\n";
            cout << "---------------------------\n";
            cout << "Varaus ID:      " << reservations[i].id << "\n";
            cout << "Huonenumero:    " << reservations[i].roomNumber << "\n";
            cout << "Varaajan nimi:  " << reservations[i].guestName << "\n";
            cout << "Varatut yot:    " << reservations[i].nights << "\n";
            cout << "Hinta:          " << reservations[i].price << "\n";
            cout << "---------------------------\n\n";

            return;
        }
    }

    cout << "Varausta nimella " << guestName << " ei loytynyt. \n\n";
}


//print all made reservations
void Hotel::printAllReservations() const {

    if (reservations.empty()) {
        cout << "Ei yhtaan  varausta.\n\n";
        return;
    }

    cout << "Kaikki varaukset:\n\n";

    for (int i = 0; i < reservations.size(); i++) {
       
            cout << "---------------------------\n";
            cout << "Varaus ID:      " << reservations[i].id << "\n";
            cout << "Huonenumero:    " << reservations[i].roomNumber << "\n";
            cout << "Varaajan nimi:  " << reservations[i].guestName << "\n";
            cout << "Varatut yot:    " << reservations[i].nights << "\n";
            cout << "Hinta:          " << reservations[i].price << "\n";
            cout << "---------------------------\n\n";

    }
}

//reserve any room thats available
int Hotel::reserveRoom(int roomNumber, const string& guestName, int nights, double price) {

    for (int i = 0; i < rooms.size(); i++) {

        if (rooms[i].number == roomNumber) {

            if (rooms[i].reserved) {

                return -1;  
            }

            rooms[i].reserved = true; //setting the room as reserved 
            int generatedID = 10000 + rand() % 90000; //generate random ID between 10000-99999
            rooms[i].reservationID = generatedID;

            //putting the reservation into the reservations vector
            reservations.emplace_back(generatedID, roomNumber, guestName, nights, price);

            return generatedID;
        }
    }

    return -1;
}

//void Hotel::cancelReservation(int id) {
//    
//}

//find the first hotel room thats available for reservation
int Hotel::getFirstAvailableRoomNumber() const {
    for (int i = 0; i < rooms.size(); i++) {

        if (!rooms[i].reserved) {
            return rooms[i].number;
        }
    }
    return -1;
}