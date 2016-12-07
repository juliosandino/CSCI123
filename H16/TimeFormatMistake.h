#include <iostream>

class TimeFormatMistake{
	public:
		//Constructors
		TimeFormatMistake();
		TimeFormatMistake(int hour, int minutes);
		~TimeFormatMistake();

		//accessor Functions
		int get_hour();
		int get_minutes();

	private:
		int Hour;
		int Minutes;
};
