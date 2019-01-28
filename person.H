#ifndef person_H
#define person_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class person {

		string name, address, phone;

	public:
		person();
		person(string,string,string);

		string getName();
		string getAddress();
		string getPhone();
};

#endif
