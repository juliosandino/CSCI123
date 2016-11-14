#ifndef P4_CDEPARTMENT_H
#define P4_CDEPARTMENT_H

#include <iostream>
#include <string>
using namespace std;

const int NUMBER_OF_DEPARTMENTS = 10;

class CDepartment {
	public:
		string ID;
		string Name;

		//Constructors
		CDepartment();
		CDepartment(string ID, string Name);
		CDepartment(const CDepartment& department);
		~CDepartment();

		//functions
		bool exists();

		//operator overloading
		friend ostream&operator <<(ostream& outs, CDepartment& department);
		friend istream&operator >>(istream& ins, CDepartment& department);
};

#endif
