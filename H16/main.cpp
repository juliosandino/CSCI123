#include <iostream>
#include <iomanip>
#include <string>
#include "TimeFormatMistake.h"
using namespace std;

int main() {
	bool again = true;

	int hour;
	int minutes;
	string mode;
	char answer;

	do {
		try {
			cout << "Enter time in 24-hour format:" << "\n";
			cout << "Hour: ";
			cin >> hour;
			cout << "Minute: ";
			cin >> minutes;
			
			if (hour > 23 || hour < 0 || minutes > 59 || minutes < 0)
				throw TimeFormatMistake(hour, minutes);

			if (hour >= 12)
				mode = "PM";
			else
				mode = "AM";
			
			if (hour > 12)
				hour -= 12;
			else if (hour == 0)
				hour = 12;

			cout << "That is " << hour << ":" << setfill('0') << setw(2) << minutes << " " <<  mode  << "\n";
		} catch (TimeFormatMistake e) {
			cout << "There is no such time as " << e.get_hour() << ":" 
				 << setfill('0') << setw(2) << e.get_minutes() << "\n";
		}
		
			cout << "Again (y/n)? ";
			cin >> answer;

			if (toupper(answer) == 'Y')
				again = true;
			else
				again = false;

	}
	while (again);
	cout << "Good-bye" << "\n";
	return 0;
}
