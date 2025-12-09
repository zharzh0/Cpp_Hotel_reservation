#include <iostream>

using namespace std;

//reads a validated integer input. Displays "description" as a prompt and ensures the value is between min and max.
//invalid input is cleared and the user is asked again until a valid number is entered.

int readInt(const string& description, int min, int max) {

	int value;

	while (true) {
		cout << description;

		if (cin >> value) {
			if (value >= min && value <= max) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}

			cout << "Syotteen on oltava valilta " << min << " - " << max << ".\n";
		}

		else {
			cout << "Virheellinen syote, syota numero.\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	}
}