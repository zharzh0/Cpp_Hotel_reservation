#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int basicUI() {

	int selection;
	cout << "1. Varaa hotellihuone\n" ;
	cout << "2. Tarkastele varaustasi\n";
	cout << "3. Peru varaus\n";
	cout << "4. Vapaiden huoneiden maara\n";
	cout << "5. Sulje ohjelma\n";
	
	cin >> selection;
	return selection;
}