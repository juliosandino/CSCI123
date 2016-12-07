#include "TimeFormatMistake.h"
using namespace std;

//Constructors
TimeFormatMistake::TimeFormatMistake(){
	Hour = 0;
	Minutes = 0;
}

TimeFormatMistake::TimeFormatMistake(int hour, int minutes){
	Hour = hour;
	Minutes = minutes;
}

TimeFormatMistake::~TimeFormatMistake(){};

//accessor functions
int TimeFormatMistake::get_hour() {
	return Hour;
}

int TimeFormatMistake::get_minutes() {
	return Minutes;
}






