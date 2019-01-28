#ifndef name_H
#define name_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class name {
		string firstName;
		string lastName;

	public:
		name();
		name(string,string);

		string getFirstName();
		string getLastName();
		void setFirstName();
		void setLastName();
};

#endif
