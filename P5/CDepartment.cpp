#include "CDepartment.h"
using namespace std;

//Constructors 

CDepartment::CDepartment(){
	ID = "Z000";
	Name = "None";
}

CDepartment::CDepartment(string id, string name){
	ID = id;
	Name = name;
}

CDepartment::CDepartment(const CDepartment& department){
	ID = department.ID;
	Name = department.Name;
}

//Destructor
CDepartment::~CDepartment(){}

//operator overloaders

ostream&operator <<(ostream& outs, CDepartment& department){
	outs << department.ID << "\t" << department.Name;
	return outs;
}

istream&operator >>(istream& ins, CDepartment& department){
	ins >> department.ID >> department.Name;
	return ins;
}

//functions
bool CDepartment::exists(){
	return ID != "Z000";
}
