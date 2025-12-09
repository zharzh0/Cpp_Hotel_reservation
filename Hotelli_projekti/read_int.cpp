#include <iostream>

using namespace std;

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