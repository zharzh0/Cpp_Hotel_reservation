#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

//telling the file a readInt exists in the project
int readInt(const string& description, int min, int max);

int basicUI() {

	cout << "1. Varaa hotellihuone\n";
	cout << "2. Nayta kaikki varaukset\n";
	cout << "3. Peru varaus\n";
	cout << "4. Vapaiden huoneiden maara\n";
	cout << "5. Etsi varaus ID:lla\n";
	cout << "6. Sulje ohjelma\n\n";

	//using the readInt function
	int selection = readInt(
		"Valitse toiminto(1 - 6): \n",
		1,
		6
	);

	return selection;
}